#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "grid.h"
#include "gridnode.h"
#include "helperFunctions.h"
#include "gridEditWindow.h"




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


    updateActions_catalogNetwork();

    // -----------------------------------------------
    // Catalog - Construction Window
    // -----------------------------------------------
    ui->catalogView_1->setModel(myGrid.catalog);

    ui->catalogView_1->setModel(myGrid.catalog);
    ui->catalogView_1->sortByColumn(1, Qt::AscendingOrder);


    connect(ui->catalogView_1->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateActions_catalogConst);

    connect(ui->newCatalogEntry_tab1, &QAbstractButton::clicked,
            this, &MainWindow::insertCatalogEntry);
    connect(ui->newDatabaseName_tab1, &QAbstractButton::clicked,
            this, &MainWindow::newCatalogLabel_connector);


    updateActions_catalogConst();
    QModelIndex newLabel = insertCatalogLabel("Default Database");

    ui->catalogView_1->selectionModel()->setCurrentIndex(newLabel, QItemSelectionModel::Select);
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
    myGrid.componentsList = new customNodeTree(catalogHeaders, this); // same headers

    ui->componentsListView->setModel(myGrid.componentsList);   //
    ui->componentsListView->sortByColumn(1, Qt::AscendingOrder);

    bool draggable = true;
    myGrid.componentsList->setExtDrag(draggable);

    for (int column = 0; column < myGrid.componentsList->columnCount(); ++column)
        ui->componentsListView->resizeColumnToContents(column);

    connect(ui->componentsListView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateActions_compList);

    updateActions_compList();


    // -----------------------------------------------
    // Properties Edit Window
    // -----------------------------------------------
    updatePropertiesEditorLabel_input("Select a Component from the Database");
    ui->PropertiesEditor->setCurrentIndex(7);

    // -----------------------------------------------
    // Grid Edit Window
    // -----------------------------------------------


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
}

MainWindow::~MainWindow()
{
    delete ui;
}
/*
// void MainWindow::item_view_item_path_enter(QString itemPath, QPointF itemPos){
//     qDebug() << itemPath;
//     qDebug() << itemPos;

//     if (Scene->items().count() > 6) Scene->clear();
//     QPixmap *Image = new QPixmap(itemPath);

//     QGraphicsPixmapItem *graphicalItem = new QGraphicsPixmapItem(*Image);
//     graphicalItem->setTransformOriginPoint(graphicalItem->boundingRect().center());

//     qreal width = 100;  //ui->networkInterface->width() * 0.1;
//     qreal height = 100;
//     QSizeF desiredSize(width, height);

//     graphicalItem->setTransform(QTransform().scale(desiredSize.width() / graphicalItem->pixmap().width(),
//                                                    desiredSize.height() / graphicalItem->pixmap().height()));

//     // Need to adjust the position definition for the width and height of the iamge
//     itemPos.setX(itemPos.rx()-width/2);
//     itemPos.setY(itemPos.ry()-height/2);
//     graphicalItem->moveBy(itemPos.rx(), itemPos.ry());
//     qDebug() << "Position: " << graphicalItem->pos();
//     Scene->addItem(graphicalItem);

//     ui->networkInterface->setScene(Scene);
//     // ui->networkInterface->fitInView(rectScene, Qt::KeepAspectRatio);
//     ui->networkInterface->show();
//     ui->networkInterface->centerOn(0, 0);
//     ui->networkInterface->resetTransform();
// }
*/
void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Button Clicked";
    gridBus* newBus = myGrid.newBus();
    QString name = newBus->getName();
    ui->listWidget_3->addItem(name);
}



// Procedure after selecting the define new catalog entry button. Creates new entry in the tree
void MainWindow::insertCatalogEntry(){
    QString boxTitle = "Define a New Catalog Entry";
    QString boxText = "Select a Type of Grid Element to Create.";
    QString boxInformativeText = "";
    std::vector<QString> options = {"Bus", "Load", "Generator", "Energy Storage Module", "Filter", "Transformer", "Converter"};
    QString selection = customQuestionBox(boxTitle, boxText, boxInformativeText, options);
    qDebug() << selection;

    if (selection == "aborted_dlg_box"){
        qDebug() << "Aborted Catalog Entry Creation";
        return;
    }


    // Use the selection to create a gridNode of the corresponding type.
    // the name is assigned in the construction function within the grid class
    QString name;
    gridNode* newCatalogEntry;
    if (selection == "Bus"){
        newCatalogEntry = myGrid.newBus();
    } else if (selection == "Load"){
        newCatalogEntry = myGrid.newLoad();
    } else if (selection == "Generator") {
        newCatalogEntry = myGrid.newSource();
    } else if (selection == "Energy Storage Module"){
        newCatalogEntry = myGrid.newESM();
    } else if (selection == "Filter") {
        newCatalogEntry = myGrid.newFilter();
    } else if (selection == "Transformer") {
        newCatalogEntry = myGrid.newTransformer();
    } else if (selection == "Converter") {
        newCatalogEntry = myGrid.newConverter();
    } else {
        qDebug() << "This shouldn't happen. New catalog entry was not valid.";
        return;
    }


    if (newCatalogEntry == nullptr){ return; }
    name = newCatalogEntry->getName();
    QString type = newCatalogEntry->getType();
    newCatalogEntry->setCatalog(true);

    // Update the catalog with the new entry

    // Get the current index selection
    const QModelIndex index = ui->catalogView_1->selectionModel()->currentIndex();


    // Set the parent index as the next highest index which is designated "label"
    QString tempName = myGrid.catalog->getName(index);    // debugging
    qDebug() << "Selected Item: ";                                      // debugging
    qDebug() << tempName;                                               // debugging
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

    tempName = myGrid.catalog->getName(parentIndex);    // debugging
    qDebug() << "Parent Item: ";                                      // debugging
    qDebug() << tempName;                                               // debugging

    if (myGrid.catalog->isRoot(parentIndex)){
        qDebug() << "Root Node Found";
    }


    // Create the new child node at position zero underneath the parent
    if (!myGrid.catalog->insertRow(0, parentIndex)){
        return;
    }

    int column = 0; // The only column is the name
    // Get the index of the child's name
    const QModelIndex child = myGrid.catalog->index(0, column, parentIndex);

    tempName = myGrid.catalog->getName(child);    // debugging
    qDebug() << "New Item: ";                                      // debugging
    qDebug() << tempName;                                               // debugging

    // Set the name of the entry
    QList<QVariant> inptData;
    inptData << QVariant(name) << QVariant(type);
    myGrid.catalog->setFullData(child, inptData, Qt::EditRole);
    // Save the node reference in the child
    myGrid.catalog->setNodeData(child, newCatalogEntry);

    updateActions_catalogConst();
    updateActions_catalogNetwork();
}

// This function adds a new label to the catalog, which allows the User to group their entries
QModelIndex MainWindow::insertCatalogLabel(QString name, bool initialization){
    //Update the catalog with a new entry
    const QModelIndex index = ui->catalogView_1->selectionModel()->currentIndex();



    if (!myGrid.catalog->insertRow(index.row()+1, index.parent()))
        return index;

    updateActions_catalogConst();
    updateActions_catalogNetwork();

    int column = 0; // The only column is the name
    // Get the index of the child's name
    QModelIndex child = myGrid.catalog->index(index.row() + 1, column, index.parent());
    // Set the name the catalog's new label, and toggle it as a label row
    myGrid.catalog->setCatalogLabel(child, name, Qt::EditRole);
    return child;
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


// Double clicking on the catalog should make a new instance of the item in the components list
void MainWindow::on_catalogView_doubleClicked(const QModelIndex &indexCatalog) {
    if (myGrid.catalog->checkLabel(indexCatalog)){
        return; // This item is just a label
    }

    gridNode* selectedEntry = myGrid.catalog->getNodePtr(indexCatalog);
    gridNode* newInstance = new gridNode(*selectedEntry);

    int numInstances = checkNumComponentInstances(selectedEntry->getName(), myGrid.componentsList, 0, Qt::CaseSensitive);
    newInstance->setName(selectedEntry->getName() + "_" + QString::number(++numInstances));

    // Update the catalog with the new entry
    const QModelIndex indexCompList = ui->componentsListView->selectionModel()->currentIndex();

    if (!myGrid.componentsList->insertRow(indexCompList.row()+1, indexCompList.parent())){
        delete newInstance;
        return;
    }

    updateActions_compList();

    QString name = newInstance->getName();
    QString type = newInstance->getType();
    int column = 0; // The only column is the name
    // Get the index of the child's name
    const QModelIndex child = myGrid.componentsList->index(indexCompList.row() + 1, column, indexCompList.parent());
    // Set the name of the entry
    QList<QVariant> inptData;
    inptData << QVariant(name) << QVariant(type);
    myGrid.catalog->setFullData(child, inptData, Qt::EditRole);
    // Save the node reference in the child
    myGrid.catalog->setNodeData(child, newInstance);

    for (int column = 0; column < myGrid.componentsList->columnCount(); ++column)
        ui->componentsListView->resizeColumnToContents(column);
}


// Helper function to remove the need for input arguments from the button press signal
void MainWindow::newCatalogLabel_connector(){
    insertCatalogLabel();   // Call this with the default arguments
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
    } else if (type == "Genset"){
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
    QString inptName = "Default Shore Power";
    gridNode* newCatalogEntry;
    newCatalogEntry = myGrid.newSource(inptName);


    if (newCatalogEntry == nullptr){ return; }
    QString type = newCatalogEntry->getType();
    newCatalogEntry->setCatalog(true);

    // Update the catalog with the new entry
    // Get the current index selection
    const QModelIndex index = ui->catalogView_1->selectionModel()->currentIndex();


    // Set the parent index as the next highest index which is designated "label"
    QString tempName = myGrid.catalog->getName(index);    // debugging
    qDebug() << "Selected Item: ";                                      // debugging
    qDebug() << tempName;                                               // debugging

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

    tempName = myGrid.catalog->getName(parentIndex);    // debugging
    qDebug() << "Parent Item: ";                                      // debugging
    qDebug() << tempName;                                               // debugging

    if (myGrid.catalog->isRoot(parentIndex)){
        qDebug() << "Root Node Found";
    }


    // Create the new child node at position zero underneath the parent
    if (!myGrid.catalog->insertRow(0, parentIndex)){
        return;
    }

    int column = 0; // The only column is the name
    // Get the index of the child's name
    const QModelIndex child = myGrid.catalog->index(0, column, parentIndex);

    tempName = myGrid.catalog->getName(child);    // debugging
    qDebug() << "New Item: ";                                      // debugging
    qDebug() << tempName;                                               // debugging

    // Set the name of the entry
    QList<QVariant> inptData;
    inptData << QVariant(inptName) << QVariant(type);
    myGrid.catalog->setFullData(child, inptData, Qt::EditRole);
    // Save the node reference in the child
    myGrid.catalog->setNodeData(child, newCatalogEntry);

    updateActions_catalogConst();
    updateActions_catalogNetwork();
}
