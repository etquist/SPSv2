#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "grid.h"
#include "gridnode.h"
#include "helperFunctions.h"
#include "dbManager.h"




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect(ui->exitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    ui->tabWidget->setCurrentIndex(0);  // Open up to the Database Editor

    // -----------------------------------------------
    // Catalog - Network Window
    // -----------------------------------------------
    const QStringList catalogHeaders({"Name", "Type"}); // Column header names for the catalog
    myGrid.catalog = new customNodeTree(catalogHeaders, this);

    ui->catalogView->setModel(myGrid.catalog);
    ui->catalogView->sortByColumn(1, Qt::AscendingOrder);


    connect(ui->catalogView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateActions_catalogNetwork);
    connect(ui->importDatabase_tab1, &QAbstractButton::clicked,
            this, &MainWindow::importDatabase);


    updateActions_catalogNetwork();

    // -----------------------------------------------
    // Catalog - Construction Window
    // -----------------------------------------------
    ui->catalogView_1->setModel(myGrid.catalog);
    ui->catalogView_1->sortByColumn(1, Qt::AscendingOrder);


    connect(ui->catalogView_1->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateActions_catalogConst);

    connect(ui->newCatalogEntry_tab1, &QAbstractButton::clicked,
            this, &MainWindow::newDatabaseEntryButton);
    connect(ui->newDatabaseName_tab1, &QAbstractButton::clicked,
            this, &MainWindow::newCatalogLabel_connector);
    connect(ui->deleteEntry_button, &QAbstractButton::clicked,
            this, &MainWindow::deleteCatalogEntry);


    updateActions_catalogConst();
    QModelIndex defaultDBLabel = insertCatalogLabel("Default Database");

    ui->catalogView_1->selectionModel()->setCurrentIndex(defaultDBLabel, QItemSelectionModel::Select);
    insertCatalogEntry_shorePower();

    ui->catalogView_1->setAcceptDrops(true);
    ui->catalogView_1->setDragEnabled(true);
    ui->catalogView_1->setDragDropMode(QAbstractItemView::InternalMove);



    for (int column = 0; column < myGrid.catalog->columnCount(); ++column) {
        ui->catalogView_1->resizeColumnToContents(column);
        ui->catalogView->resizeColumnToContents(column);
    }
    // -----------------------------------------------
    // Components List
    // -----------------------------------------------
    const QStringList compListHeaders({"Name", "Type", "SN"}); // Column header names for the catalog
    myGrid.componentsList = new customNodeTree(compListHeaders, this); // same headers

    ui->componentsListView->setModel(myGrid.componentsList);   //
    ui->componentsListView->sortByColumn(1, Qt::AscendingOrder);

    bool draggable = true;
    myGrid.componentsList->setExtDrag(draggable);
    QString shorePowerStr = "Default Shore Power";
    QModelIndex shorePower = myGrid.catalog->findChildInDB(shorePowerStr, defaultDBLabel);
    on_catalogView_doubleClicked(shorePower);


    for (int column = 0; column < myGrid.componentsList->columnCount(); ++column)
        ui->componentsListView->resizeColumnToContents(column);

    connect(ui->componentsListView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateActions_compList);

    updateActions_compList();


    // -----------------------------------------------
    // Network Components List
    // -----------------------------------------------
    const QStringList netCompListHeaders({"Name", "Type", "SN", "System", "Subsystem"}); // Column header names for the catalog
    myGrid.networkComponents = new customNodeTree(netCompListHeaders, this);

    ui->networkComponentsViewer->setModel(myGrid.networkComponents);   //
    ui->networkComponentsViewer->sortByColumn(1, Qt::AscendingOrder);

    myGrid.networkComponents->setExtDrag(draggable);

    connect(ui->networkComponentsViewer->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateActions_netCompList);
    updateActions_netCompList();

    for (int column = 0; column < myGrid.networkComponents->columnCount(); ++column)
        ui->networkComponentsViewer->resizeColumnToContents(column);

    ui->gridEditor->setNetCompView(ui->networkComponentsViewer);

    // -----------------------------------------------
    // System Hierarchy Window
    // -----------------------------------------------
    ui->systemHierarchyViewer->myGridRef = &myGrid;

    Grid::systemHierNode* universal = new Grid::systemHierNode();
    universal->name = "Universal";
    myGrid.systemHierarchyTreeParent = universal;
    ui->systemHierarchyViewer->systemHierarchyTreeParent = universal;
    ui->systemHierarchyViewer->renderView();
    ui->systemHierarchyViewer->setSelection(universal);    // Default
    ui->comboBox_system->addItem(universal->name); // This is the only system that belongs in the tree

    Grid::systemHierNode* unassigned = new Grid::systemHierNode();
    unassigned->name = myGrid.unassignedName;
    universal->childs.insert(unassigned);   // unassigned is a "system" so we can keep track of them behind the scenes
    ui->comboBox_system->addItem(unassigned->name);

    QStringListModel *systemCompList = new QStringListModel();
    myGrid.systemComponentsList = systemCompList;
    ui->systemCompsList->setModel(systemCompList);

    connect(ui->pushButton_11, &QAbstractButton::clicked,
            this, &MainWindow::deleteSystem);


    // -----------------------------------------------
    // Properties Edit Window
    // -----------------------------------------------
    updatePropertiesEditorLabel_input("Select a Component from the Database");
    ui->PropertiesEditor->setCurrentIndex(7);

    // -----------------------------------------------
    // Grid Edit Window
    // -----------------------------------------------
    ui->gridEditor->setGridRef(&myGrid);


    // -----------------------------------------------
    // Windows Toolbar
    // -----------------------------------------------
    connect(ui->actionLaunch_GitHub, &QAction::triggered, this, &MainWindow::launchGitHub);

    // -----------------------------------------------
    // Help Buttons
    // -----------------------------------------------
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::databaseNetworkHelpButton);
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::databaseNetworkHelpButton);
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::databaseConstructorHelpButton);


    // -----------------------------------------------
    // Testing -- Initialize a database
    // -----------------------------------------------




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Button Clicked";
    gridNode* newBus = myGrid.newBus();
    QString name = newBus->getName();
    ui->listWidget_3->addItem(name);
}


void MainWindow::insertCatalogEntry(QString nameInpt, QString typeInpt, int uniqueIDInpt){
    QString name;
    QString type;
    int uniqueID;

    name = nameInpt;
    type = typeInpt;
    uniqueID = uniqueIDInpt;

    // Update the catalog with the new entry

    // Get the current index selection
    const QModelIndex index = ui->catalogView_1->selectionModel()->currentIndex();


    // Set the parent index as the next highest index which is designated "label"
    QModelIndex parentIndex;
    if (myGrid.catalog->checkLabel(index)){
        parentIndex = index;
    }
    else{
        parentIndex = index.parent();
        while (!myGrid.catalog->checkLabel(parentIndex)){
            parentIndex = parentIndex.parent(); // Keep going higher. The root node will be the highest stopping point
        }
    }

    if (myGrid.catalog->isRoot(parentIndex)){
        qDebug() << "Root Node Found";
    }


    // Create the new child node at position zero underneath the parent
    if (!myGrid.catalog->insertRow(0, parentIndex)){
        return;
    }

    int column = 0; // The only column is the name
    // Get the index of the child's name
    QModelIndex child = myGrid.catalog->index(0, column, parentIndex);

    // Set the name of the entry
    QList<QVariant> inptData;
    inptData << QVariant(name) << QVariant(type);
    myGrid.catalog->setFullData(child, inptData, Qt::EditRole);
    // Update the ID, database name, and mark this as a catalog entry



    myGrid.catalog->setUniqueID(child, uniqueID);
    myGrid.catalog->set_dbName(child, myGrid.catalog->getName(parentIndex));    // The database name is the same as the parentIndex
    myGrid.catalog->setCatalog(child, true);


    updateActions_catalogConst();
    updateActions_catalogNetwork();

}

void MainWindow::newDatabaseEntryButton(){

    // First, prompt the user to select the type of database entry that they would like to create.
    QString boxTitle = "Define a New Catalog Entry";
    QString boxText = "Select a Type of Grid Element to Create.";
    QString boxInformativeText = "";
    std::vector<QString> options = {"Bus", "Load", "Generator", "Energy Storage Module", "Filter", "Transformer", "Converter"};
    QString selection = customQuestionBox(boxTitle, boxText, boxInformativeText, options);
    qDebug() << selection;

    const QModelIndex index = ui->catalogView_1->selectionModel()->currentIndex();

    if (selection == "aborted_dlg_box"){
        qDebug() << "Aborted Catalog Entry Creation";
        return;
    }

    int numInstances = checkNumComponentInstances(selection, myGrid.catalog, 0, Qt::CaseSensitive);
    QString defaultName = selection + QString::number(++numInstances);

    QString name = promptForText(defaultName);  // Pass the default as the name
    QString type = selection;


    QString dbName;
    // Get the current index selection
    if (myGrid.catalog->checkLabel(index)){
        // It's a database label
        dbName = myGrid.catalog->getName(index);
    } else{
        dbName = myGrid.catalog->get_dbName(index);
    }
    dbManager* db = &myGrid.dbList[dbName];

    // Create the new database entry, and get back the uniqueId associated with it
    int uniqueID = db->newEntry(name, type);

    insertCatalogEntry(name, type, uniqueID);
    return;
}


// This function adds a new label to the catalog, which allows the User to group their entries
QModelIndex MainWindow::insertCatalogLabel(QString name, bool promptForPath, bool initialization){
    // Get the current index. Move it upward until the next level is the parent
    QModelIndex currentIndex = ui->catalogView_1->selectionModel()->currentIndex(); // Currently selected index
    while (!myGrid.catalog->isRoot(currentIndex.parent())){ // While the parent is not the root
        currentIndex = currentIndex.parent(); // Keep going higher. The root node will be the highest stopping point
    }

    QString dbPath;
    QString dbName;
    if (promptForPath == false){
        // Just use the executable path
        dbPath = QCoreApplication::applicationDirPath() + "/" + name + ".db";
        dbName = name;
    } else{
        dbPath = QFileDialog::getOpenFileName(this, "Open File", "", "Databases (*.db)");
        dbName = extractFileName(dbPath);
        if (dbPath == "null"){
            qDebug() << "Failed to open database at path: " << dbPath;
            return currentIndex;
        }

        // While the database name already exists in the catalog
        if (myGrid.dbPathList.end() != myGrid.dbPathList.find(dbName)){
            qDebug() << "User has already opened this.";
            QMessageBox msgBox;
            msgBox.setText("Database already opened.");
            msgBox.exec();
            return currentIndex;
        }
    }




    // While the database name already exists in the catalog
    if (myGrid.dbPathList.end() != myGrid.dbPathList.find(dbName)){
        qDebug() << "User has already opened this.";
        QMessageBox msgBox;
        msgBox.setText("Database already opened.");
        msgBox.exec();
        return currentIndex;
    }

    dbManager newDB(dbPath, dbName);


    // The parent is now the root, so we've reached the top level. Select this index
    ui->catalogView_1->selectionModel()->setCurrentIndex(currentIndex, QItemSelectionModel::Select);

    // Add the DB
    if (!myGrid.catalog->insertRow(currentIndex.row()+1, currentIndex.parent()))
        return currentIndex;

    updateActions_catalogConst();
    updateActions_catalogNetwork();

    int column = 0; // The only column is the name
    // Get the index of the child's name
    QModelIndex newLabel = myGrid.catalog->index(currentIndex.row() + 1, column, currentIndex.parent());
    // Set the name the catalog's new label, and toggle it as a label row
    myGrid.catalog->setCatalogLabel(newLabel, dbName, Qt::EditRole);

    // Select the newly made index
    ui->catalogView_1->selectionModel()->setCurrentIndex(newLabel, QItemSelectionModel::Select);

    // Get all the entry data from the database
    std::vector<QList<QVariant>> entries = newDB.getAllEntries_basicData();

    // Iterate through the entries in the database, returning the uniqueID, name, and type
    for (size_t i = 0; i < entries.size(); i++){
        QString nameInpt = entries.at(i)[0].toString();
        QString typeInpt = entries.at(i)[1].toString();
        int uniqueIDInpt = entries.at(i)[2].toInt();

        insertCatalogEntry(nameInpt, typeInpt, uniqueIDInpt);
    }


    myGrid.dbList.emplace(dbName, newDB); // Store the database for later use
    myGrid.dbPathList.emplace(dbName, dbPath);  // Store the path for later reference if needed

    updateActions_catalogConst();
    updateActions_catalogNetwork();

    return newLabel;
}




// Update actions function for the tree view widgets
void MainWindow::updateActions_catalogConst()
{

    const bool hasCurrent = ui->catalogView_1->selectionModel()->currentIndex().isValid();


    if (hasCurrent) {
        ui->catalogView_1->closePersistentEditor(ui->catalogView_1->selectionModel()->currentIndex());

        const int row = ui->catalogView_1->selectionModel()->currentIndex().row();
        const int column = ui->catalogView_1->selectionModel()->currentIndex().column();
        if (ui->catalogView_1->selectionModel()->currentIndex().parent().isValid())
            statusBar()->showMessage(tr("Position: (%1,%2)").arg(row).arg(column));
        else
            statusBar()->showMessage(tr("Position: (%1,%2) in top level").arg(row).arg(column));
    }
}

// Update actions function for the tree view widgets
void MainWindow::updateActions_catalogNetwork()
{
    const bool hasCurrent = ui->catalogView->selectionModel()->currentIndex().isValid();

    if (hasCurrent) {
        ui->catalogView->closePersistentEditor(ui->catalogView->selectionModel()->currentIndex());

        const int row = ui->catalogView->selectionModel()->currentIndex().row();
        const int column = ui->catalogView->selectionModel()->currentIndex().column();
        if (ui->catalogView->selectionModel()->currentIndex().parent().isValid())
            statusBar()->showMessage(tr("Position: (%1,%2)").arg(row).arg(column));
        else
            statusBar()->showMessage(tr("Position: (%1,%2) in top level").arg(row).arg(column));
    }
}


// Update actions function for the tree view widgets
void MainWindow::updateActions_compList()
{
    const bool hasCurrent = ui->componentsListView->selectionModel()->currentIndex().isValid();

    if (hasCurrent) {
        ui->componentsListView->closePersistentEditor(ui->componentsListView->selectionModel()->currentIndex());

        const int row = ui->componentsListView->selectionModel()->currentIndex().row();
        const int column = ui->componentsListView->selectionModel()->currentIndex().column();
        if (ui->componentsListView->selectionModel()->currentIndex().parent().isValid())
            statusBar()->showMessage(tr("Position: (%1,%2)").arg(row).arg(column));
        else
            statusBar()->showMessage(tr("Position: (%1,%2) in top level").arg(row).arg(column));
    }
}



// Update actions function for the tree view widgets
void MainWindow::updateActions_netCompList()
{
    const bool hasCurrent = ui->networkComponentsViewer->selectionModel()->currentIndex().isValid();

    if (hasCurrent) {
        ui->networkComponentsViewer->closePersistentEditor(ui->networkComponentsViewer->selectionModel()->currentIndex());

        const int row = ui->networkComponentsViewer->selectionModel()->currentIndex().row();
        const int column = ui->networkComponentsViewer->selectionModel()->currentIndex().column();
        if (ui->networkComponentsViewer->selectionModel()->currentIndex().parent().isValid())
            statusBar()->showMessage(tr("Position: (%1,%2)").arg(row).arg(column));
        else
            statusBar()->showMessage(tr("Position: (%1,%2) in top level").arg(row).arg(column));
    }

    // Update the label and combo box IF there's a valid selection
    QModelIndex index = ui->networkComponentsViewer->currentIndex();

    QString selectedName = myGrid.networkComponents->getName(index);

    if (selectedName != "Name" && myGrid.networkComponents->getType(index) != "Type"){
        ui->label_50->setText(selectedName + " parent system and subsystem: ");

        // Set the current index of the combo box to the selection's mission
        QString subsystemName = myGrid.networkComponents->getSubSystem(index);
        QString systemName = myGrid.networkComponents->getSystem(index);

        int currentSystemIndex = ui->comboBox_system->findText(systemName);
        int currentSubSystemIndex = ui->comboBox_subsystem->findText(subsystemName);

        ui->comboBox_system->setCurrentIndex(currentSystemIndex);
        ui->comboBox_subsystem->setCurrentIndex(currentSubSystemIndex);

    } else {
        // This is the header
        ui->label_50->setText("Select a component to assign its system and subsystem");
    }
}



// Double clicking on the catalog should make a new instance of the item in the components list
void MainWindow::on_catalogView_doubleClicked(const QModelIndex &indexCatalog) {
    if (myGrid.catalog->checkLabel(indexCatalog)){
        return; // This item is just a label
    }

    // Get the type from the database entry
    QString old_type = myGrid.catalog->getType(indexCatalog);

    // The new gridNode which will be inserted into the grid, and then into the components list
    gridNode* newInstance = myGrid.newNode(old_type, false);

    newInstance->setType(old_type);
    newInstance->setUniqueID(myGrid.catalog->getUniqueID(indexCatalog));

    // Update the name as oldName_#ofThisType
    int numInstances = checkNumComponentInstances(myGrid.catalog->getName(indexCatalog), myGrid.componentsList, 0, Qt::CaseSensitive);
    newInstance->setName(myGrid.catalog->getName(indexCatalog) + "_" + QString::number(++numInstances));

    // Get the currently selected index from the components List
    const QModelIndex indexCompList = ui->componentsListView->selectionModel()->currentIndex();

    // Insert a new entry below the selected index
    if (!myGrid.componentsList->insertRow(indexCompList.row()+1, indexCompList.parent())){
        delete newInstance;
        return;
    }

    updateActions_compList();


    int column = 0; // The only column is the name
    // Get the index of the child's name
    QModelIndex child = myGrid.componentsList->index(indexCompList.row() + 1, column, indexCompList.parent());
    // Set the name of the entry
    QList<QVariant> inptData;
    inptData << QVariant(newInstance->getName()) << QVariant(newInstance->getType()) << QVariant(newInstance->getSN());
    myGrid.componentsList->setFullData(child, inptData, Qt::EditRole);
    // Save the node reference in the child
    myGrid.componentsList->setNodeData(child, newInstance);

    for (int column = 0; column < myGrid.componentsList->columnCount(); ++column)
        ui->componentsListView->resizeColumnToContents(column);
}


// Helper function to remove the need for input arguments from the button press signal
void MainWindow::newCatalogLabel_connector(){
    QString name = promptForText("Enter a Name", "Enter a name for the new database. No duplicates allowed.");
    if (name == "userCNCL-exit"){
        return;
    }

    insertCatalogLabel(name);   // Call this with the default arguments
}


void MainWindow::on_catalogView_1_clicked(const QModelIndex &index)
{
    if (myGrid.catalog->checkLabel(index)){
        ui->PropertiesEditor->setCurrentIndex(7);
        ui->label_3->setText("Select a Component from the Database");
        return; // This item is just a label
    }

    QString type = myGrid.catalog->getType(index);

    if (type == "Load"){
        ui->PropertiesEditor->setCurrentIndex(5);
    } else if (type == "Generator"){
        ui->PropertiesEditor->setCurrentIndex(3);
    } else if (type == "ESM"){
        ui->PropertiesEditor->setCurrentIndex(0);
    } else if (type == "Filter"){
        ui->PropertiesEditor->setCurrentIndex(6);
    } else if (type == "Transformer"){
        ui->PropertiesEditor->setCurrentIndex(1);
    } else if (type == "Converter"){
        ui->PropertiesEditor->setCurrentIndex(2);
    } else if (type == "Bus"){
        ui->PropertiesEditor->setCurrentIndex(4);
    } else{
        qDebug() << "I'm not sure what you just selected?";
    }


    QString name = myGrid.catalog->getName(index);
    ui->label_3->setText(name + " Properties");

    /* To do:
    - Link the selected node to the available property edit items in the nwly opened tab

    */
    return;

}

void MainWindow::updatePropertiesEditorLabel_input(QString name){
    ui->label_3->setText(name);
}

void MainWindow::launchGitHub(){
    QString githubURL = "https://github.com/etquist/SPSv2/wiki";
    QDesktopServices::openUrl(QUrl(githubURL));
}





void MainWindow::databaseNetworkHelpButton()
{
    QMessageBox msgBox;
    msgBox.setText("The 'Database' is a collection of component templates which are editable. Create an instance of one of these for your grid by double clicking. The instance will populate in the 'Active Components' list for you to click and drag onto the editing window.");
    msgBox.exec();

    return;
}

void MainWindow::databaseConstructorHelpButton()
{
    QMessageBox msgBox;
    msgBox.setText("The 'Database' is a collection of component templates which are editable. Create one by selecting the 'New Database Entry' button, or import an existing database. Edit an entry's properties by selecting it. Instances of these database entries can be used as components within your power network.");
    msgBox.exec();

    return;
}

void MainWindow::insertCatalogEntry_shorePower(){
    QString name = "Default Shore Power";
    QString type = "Generator";


    // First, check if the entry already exists
    // Get the current index selection
    const QModelIndex index = ui->catalogView_1->selectionModel()->currentIndex();
    QString dbName = myGrid.catalog->getName(index);
    dbManager* db = &myGrid.dbList[dbName];

    if (-1 != db->queryEntry(name)){
        // The Default Show Power already exists in the database
        return;
    }

    // The entry doesn't exist, so proceed.

    int uniqueID = db->newEntry(name, type);

    insertCatalogEntry(name, type, uniqueID);


    updateActions_catalogConst();
    updateActions_catalogNetwork();
}


// Creates a new database manager associated with the chosen file by the user
//  updates the catalog, and then adds the database to a hashtable stored in myGrid
void MainWindow::importDatabase()
{
    QString name = "unspecified";
    insertCatalogLabel(name, true);

}

void MainWindow::on_catalogView_1_doubleClicked(const QModelIndex &index)
{
    // Make sure the index is valid
    if(!index.isValid()){
        return;
    }


    // Check to see what we selected here
    if (myGrid.catalog->checkLabel(index)){
        // if it's a database label
        QString original = myGrid.catalog->getName(index);
        QString modified = promptForText("Enter a New Name", "Enter the new name for the database. No duplicates allowed.");
        if (modified == "userCNCL-exit"){
            return;
        }

        if( myGrid.dbList.find(original) != myGrid.dbList.end()){
            dbManager* selectedDB = &myGrid.dbList[original];
            QString orig_dbName = selectedDB->getDBPath();
            QString orig_connectionName = selectedDB->getConnectionName();

            if (!selectedDB->changeDBName(modified)){
                // Successful name change. We now have a modified database manager object

                // Change the key associated with the old name to the new name
                myGrid.dbList[modified] = *selectedDB;
                myGrid.dbPathList[modified] = selectedDB->getDBPath();

                myGrid.dbList.erase(orig_connectionName);
                myGrid.dbPathList.erase(orig_connectionName);
        }




        } else{
            // Unsuccessful, revert back to original name
            myGrid.catalog->setCatalogLabel(index, original, Qt::EditRole);
        }


    } else{
        // if it's a catalog entry, only allow editing on the name itself
        if (index.column() == 0){
            QString newName = promptForText("Enter a New Name", "Enter the new name for the database entry.");
            if (newName == "userCNCL-exit"){
                return;
            }
            myGrid.catalog->setData(index, newName);

            dbManager* selectedDB = &myGrid.dbList[myGrid.catalog->get_dbName(index)];

            int uniqueID = myGrid.catalog->getUniqueID(index);
            selectedDB->setEntryName(uniqueID, newName);
        }

    }

}

void MainWindow::deleteCatalogEntry(){
    QModelIndex index = ui->catalogView_1->selectionModel()->currentIndex();

    if (!index.isValid()){
        qDebug() << "Invalid Index";
    }
    if (!myGrid.catalog->checkLabel(index)){
        // This is a valid index, on a catalog entry

        // Ask the User if they want to proceed.
        QString boxTitle = "CAUTION";
        QString boxText = "Are you sure that you would like to permamently delete this entry from the database?";
        QString boxInformativeText = "";
        std::vector<QString> options = {"Yes, Continue", "No, Do Not Delete"};
        QString selection = customQuestionBox(boxTitle, boxText, boxInformativeText, options);
        qDebug() << selection;

        const QModelIndex index = ui->catalogView_1->selectionModel()->currentIndex();

        if (selection == "aborted_dlg_box" | selection == "No, Do Not Delete"){
            qDebug() << "Aborted Catalog Entry Creation";
            return;
        }


        // Proceed with deletion procedures...
        QString dbName = myGrid.catalog->get_dbName(index);
        dbManager* db = &myGrid.dbList[dbName];

        int targetUniqueID = myGrid.catalog->getUniqueID(index);


        // Delete from the database
        db->deleteEntry(targetUniqueID);


        // Delete the catalog tree entry
        if (myGrid.catalog->removeRows(index.row(), 1, index.parent())){    // Only remove the single row
            qDebug() << "Successfully deleted from the catalog tree";
        }
        else{
            qDebug() << "Failed to delete from the catalog tree";
        }
    }
    return;

}

// Add a system and re-render the viewer
void MainWindow::on_pushButton_9_clicked()
{
    QString nameInpt;
    bool invalidName = true;

    while(invalidName){
        invalidName = false;
        nameInpt = promptForText("Enter a Unique System Name", "Enter a name for the system. Avoid duplicates of existing systems.");
        if (nameInpt == "userCNCL-exit"){
            return;
        }

        // If the name already, exists, prompt the user again
        for (auto it = myGrid.systemHierarchyTreeParent->childs.begin(); it != myGrid.systemHierarchyTreeParent->childs.end(); it++){
            if ((*it)->name == nameInpt){
                invalidName = true;
            }
        }
    }
    myGrid.insertSystem(nameInpt);
    ui->systemHierarchyViewer->renderView();

    ui->comboBox_system->addItem(nameInpt);    // Add the default subsystem to the drop down selector

}

// Add a subsystem and re-render the view
void MainWindow::on_pushButton_10_clicked()
{
    // Find the currently slected node that will potentially receive the new subsystem
    Grid::systemHierNode* curSelection = ui->systemHierarchyViewer->getSelection();
    if (curSelection->parent == myGrid.systemHierarchyTreeParent){
        // Good
    } else if (curSelection == myGrid.systemHierarchyTreeParent){
        // This is the universal node
        return;
    } else if (curSelection == nullptr) {
        // This is a nullptr because there is no current selection
        QMessageBox msgBox;
        msgBox.setText("Select a system to insert a subsystem.");
        msgBox.exec();
    } else{
        // This is a subsystem already. Change ref to the parent system
        curSelection = curSelection->parent;
    }


    ui->systemHierarchyViewer->setSelection(curSelection);

    QString nameInpt;
    bool invalidName = true;

    while(invalidName){
        invalidName = false;
        nameInpt = promptForText("Enter a Sub-System Name", "Enter a name for the sub-system.");
        if (nameInpt == "userCNCL-exit"){
            return;
        }

        // If the name already, exists, prompt the user again
        for (auto it = curSelection->childs.begin(); it != curSelection->childs.end(); it++){
            if ((*it)->name == nameInpt){
                invalidName = true;
            }
        }
    }

    Grid::systemHierNode* newSubsystem = myGrid.insertSubSystem(nameInpt, curSelection);
    ui->systemHierarchyViewer->renderView();

    ui->systemHierarchyViewer->setSelection(newSubsystem);

    // If the subsystem's parent is currently activated in the drop down, add the subsystem to the combo box
    if (ui->comboBox_system->currentText() == newSubsystem->parent->name){
        ui->comboBox_subsystem->addItem(nameInpt);
    }
}


// If the tab changes to the system editor, re-render the view
void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (index == 2){
        ui->systemHierarchyViewer->renderView();
        ui->systemHierarchyViewer->setSelection(ui->systemHierarchyViewer->systemHierarchyTreeParent);
    }
}


void MainWindow::resizeEvent(QResizeEvent* event)
{
    ui->systemHierarchyViewer->renderView();
}


// If the system combo box is changed, update the valid entires for the subsystem box
void MainWindow::on_comboBox_system_currentIndexChanged(int index)
{
    QString selectedSystem = ui->comboBox_system->currentText();
    ui->comboBox_subsystem->clear();

    // Find the selected system, and then add all of the subsystems of this system to the subsystem combo box.
    int numAdded = 0;
    for (auto it = myGrid.systemHierarchyTreeParent->childs.begin(); it != myGrid.systemHierarchyTreeParent->childs.end(); it++){
        if ((*it)->name == selectedSystem){
            for (auto it_sub = (*it)->childs.begin(); it_sub != (*it)->childs.end(); it_sub++){
                ui->comboBox_subsystem->addItem((*it_sub)->name);
                numAdded = numAdded + 1;
            }
        }
    }

    // Ensure that the system assignment is still made
    if (numAdded == 0){
        qDebug() << "No subsystems were added for the system " << selectedSystem << ", updating subsystem selection manually.";
        update_SystemSubSys_Selection();
    }

}


// If the subsystem box is changed and a valid component is selected, update the component's system/subsystem
void MainWindow::on_comboBox_subsystem_currentIndexChanged(int index)
{
    update_SystemSubSys_Selection();
}


void MainWindow::on_networkComponentsViewer_clicked(const QModelIndex &index)
{
    QString selectedName = myGrid.networkComponents->getName(index);

    if (selectedName != "Name" && myGrid.networkComponents->getType(index) != "Type"){
        // Not the header
        ui->label_50->setText(selectedName + " parent system and subsystem: ");

        // Set the current index of the combo box to the selection's mission
        QString subsystemName = myGrid.networkComponents->getSubSystem(index);
        QString systemName = myGrid.networkComponents->getSystem(index);

        int currentSystemIndex = ui->comboBox_system->findText(systemName);
        on_comboBox_system_currentIndexChanged(currentSystemIndex);

        int currentSubSystemIndex = ui->comboBox_subsystem->findText(subsystemName);
        ui->comboBox_subsystem->setCurrentIndex(currentSubSystemIndex);

    } else {
        // This is the header
        ui->label_50->setText("Select a component to assign its system and subsystem");
    }
}


// This function looks at the current selections for the combo boxes, and shifts system assignment accordingly
//  for the currently selected component in the network components viewer
void MainWindow::update_SystemSubSys_Selection(){
    QModelIndex currentSelection = ui->networkComponentsViewer->currentIndex();


    if (currentSelection.isValid() ){
        qDebug() << "Reassigning component: " << myGrid.networkComponents->getName(currentSelection);
        // There is a valid component selected.
        QString systemSelection = ui->comboBox_system->currentText();
        QString subsystemSelection = ui->comboBox_subsystem->currentText();

        // Get the serial number of the selected component
        int SN = myGrid.networkComponents->getSN(currentSelection);
        if (SN == -1){
            return; // The serial number was not valid
        }


        // Add the serial number to the system/subsystem's list
        Grid::systemHierNode* system = myGrid.findSystem(systemSelection);
        Grid::systemHierNode* subsystem = myGrid.findSubSystem(systemSelection, subsystemSelection);

        // If the selected system is found, insert the serial number. otherwise, return
        if (system == nullptr){
            qDebug() << "System not found. Selection: " << systemSelection;
            return;
        }
        system->SNs.insert(SN);

        // If a subsystemm is found, insert the serial number
        if (subsystem != nullptr){
            subsystem->SNs.insert(SN);

        } else{
            qDebug() << "No subsystem found";
        }


        // Remove the serial number from the original system/subsystem's list
        QString oldSystemName = myGrid.networkComponents->getSystem(currentSelection);
        QString oldSubSystemName = myGrid.networkComponents->getSubSystem(currentSelection);

        // If the system isnt changing, dont delete from the "old one"
        if (oldSystemName != systemSelection){
            Grid::systemHierNode* oldSystem = myGrid.findSystem(oldSystemName);
            oldSystem->SNs.erase(SN);
        }

        // If the subsystem hasn't changed, don't delete it from the "old one"
        if (oldSubSystemName != subsystemSelection){
            Grid::systemHierNode* oldSubsystem = myGrid.findSubSystem(oldSystemName, oldSubSystemName);
            if (oldSubsystem != nullptr){
                // The component was previously assigned to a valid subsystem
                oldSubsystem->SNs.erase(SN);
            } else{
                qDebug() << "No old subsystem found";
            }
        }

        // Add the system/subsystem name to the network components list viewer
        myGrid.networkComponents->setSystem(currentSelection, system->name);
        if (subsystem != nullptr){
            // Only add if a valid system was found
            myGrid.networkComponents->setSubSystem(currentSelection, subsystem->name);
        } else{
            // Otherwise, leave it blank
            myGrid.networkComponents->setSubSystem(currentSelection, "");
        }

        ui->systemHierarchyViewer->updateSystemList(ui->systemHierarchyViewer->getSelection());
    }
}


// Delete the currently selected system or subsystem from the hierarchy, and reassign all the members to "unassigned"
void MainWindow::deleteSystem(){
    Grid::systemHierNode* selection = ui->systemHierarchyViewer->getSelection();


    if (selection == nullptr){
        qDebug() << "Invalid Index";
        return;
    }

    if (selection == myGrid.systemHierarchyTreeParent){
        qDebug() << "Cannot delete the universal system";
        return;
    }

    // This is a valid index, on a catalog entry

    // Ask the User if they want to proceed.
    QString boxTitle = "CAUTION";
    QString boxText = "Are you sure that you would like to permamently delete this entry from the database?";
    QString boxInformativeText = "";
    std::vector<QString> options = {"Yes, Continue", "No, Do Not Delete"};
    QString prompt_selection = customQuestionBox(boxTitle, boxText, boxInformativeText, options);
    qDebug() << prompt_selection;

    const QModelIndex index = ui->catalogView_1->selectionModel()->currentIndex();

    if (prompt_selection == "aborted_dlg_box" | prompt_selection == "No, Do Not Delete"){
        qDebug() << "Aborted Catalog Entry Creation";
        return;
    }


    // Proceed with deletion procedures...
    ui->systemHierarchyViewer->setSelection(selection->parent);

    if (selection->parent == myGrid.systemHierarchyTreeParent){
        // If it's a system, remove it's name from the combo box
        ui->comboBox_system->removeItem(ui->comboBox_system->findText(selection->name));
    }

    ui->systemHierarchyViewer->deleteSystem(selection);

    ui->systemHierarchyViewer->updateSystemList(ui->systemHierarchyViewer->getSelection());
    ui->systemHierarchyViewer->renderView();

    return;

}
