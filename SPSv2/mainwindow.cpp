#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "grid.h"
#include "gridnode.h"
#include "helperFunctions.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //connect(ui->exitAction, &QAction::triggered, qApp, &QCoreApplication::quit);

    // -----------------------------------------------
    // Catalog
    // -----------------------------------------------
    const QStringList catalogHeaders({"Name"}); // Column header names for the catalog
    myGrid.catalog = new customNodeTree(catalogHeaders, this);

    ui->catalogView->setModel(myGrid.catalog);
    for (int column = 0; column < myGrid.catalog->columnCount(); ++column)
        ui->catalogView->resizeColumnToContents(column);

    connect(ui->catalogView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateActions_catalog);

    connect(ui->toolButton_4, &QAbstractButton::clicked, this, &MainWindow::insertCatalogEntry);

    updateActions_catalog();

    // -----------------------------------------------
    // Components List
    // -----------------------------------------------
    myGrid.componentsList = new customNodeTree(catalogHeaders, this); // same headers

    ui->componentsListView->setModel(myGrid.componentsList);   //
    for (int column = 0; column < myGrid.componentsList->columnCount(); ++column)
        ui->componentsListView->resizeColumnToContents(column);

    connect(ui->componentsListView->selectionModel(), &QItemSelectionModel::selectionChanged,
            this, &MainWindow::updateActions_compList);

    updateActions_compList();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::item_view_item_path_enter(QString itemPath, QPointF itemPos){
    qDebug() << itemPath;
    qDebug() << itemPos;

    if (Scene->items().count() > 6) Scene->clear();
    QPixmap *Image = new QPixmap(itemPath);

    QGraphicsPixmapItem *graphicalItem = new QGraphicsPixmapItem(*Image);
    graphicalItem->setTransformOriginPoint(graphicalItem->boundingRect().center());

    qreal width = 100;  //ui->networkInterface->width() * 0.1;
    qreal height = 100;
    QSizeF desiredSize(width, height);

    graphicalItem->setTransform(QTransform().scale(desiredSize.width() / graphicalItem->pixmap().width(),
                                                   desiredSize.height() / graphicalItem->pixmap().height()));

    // Need to adjust the position definition for the width and height of the iamge
    itemPos.setX(itemPos.rx()-width/2);
    itemPos.setY(itemPos.ry()-height/2);
    graphicalItem->moveBy(itemPos.rx(), itemPos.ry());
    qDebug() << "Position: " << graphicalItem->pos();
    Scene->addItem(graphicalItem);

    ui->networkInterface->setScene(Scene);
    // ui->networkInterface->fitInView(rectScene, Qt::KeepAspectRatio);
    ui->networkInterface->show();
    ui->networkInterface->centerOn(0, 0);
    ui->networkInterface->resetTransform();
}

void MainWindow::on_pushButton_clicked()
{
    qDebug() << "Button Clicked";
    gridBus* newBus = myGrid.newBus();
    QString name = newBus->getName();
    ui->listWidget_3->addItem(name);
}

/*
// This function is for adding a new entry to the catalog.
// A new node is created based on the user specification
// void MainWindow::on_toolButton_4_clicked()
// {
//     QString boxTitle = "Define a New Catalog Entry";
//     QString boxText = "Select a Type of Grid Element to Create.";
//     QString boxInformativeText = "";
//     std::vector<QString> options = {"Bus", "Load", "Generator", "Energy Storage Module", "Filter"};
//     QString selection = customQuestionBox(boxTitle, boxText, boxInformativeText, options);
//     qDebug() << selection;

//     if (selection == "aborted_dlg_box"){
//         qDebug() << "Aborted Catalog Entry Creation";
//         return;
//     }


//     // Use the selection to create a gridNode of the corresponding type.
//     // the name is assigned in the construction function within the grid class
//     QString name;
//     gridNode* newCatalogEntry;
//     if (selection == "Bus"){
//         newCatalogEntry = myGrid.newBus();
//     } else if (selection == "Load"){
//         newCatalogEntry = myGrid.newLoad();
//     } else if (selection == "Generator") {
//         newCatalogEntry = myGrid.newSource();
//     } else if (selection == "Energy Storage Module"){
//         newCatalogEntry = myGrid.newESM();
//     } else if (selection == "Filter") {
//         newCatalogEntry = myGrid.newFilter();
//     } else {
//         qDebug() << "This shouldn't happen. New catalog entry was not valid.";
//         return;
//     }


//     if (newCatalogEntry == nullptr){ return; }
//     name = newCatalogEntry->getName();
//     newCatalogEntry->setCatalog(true);
//     //ui->listWidget_2->addItem(name);

// }
*/

// Procedure after selecting the define new catalog entry button. Creates new entry in the tree
void MainWindow::insertCatalogEntry(){
    QString boxTitle = "Define a New Catalog Entry";
    QString boxText = "Select a Type of Grid Element to Create.";
    QString boxInformativeText = "";
    std::vector<QString> options = {"Bus", "Load", "Generator", "Energy Storage Module", "Filter"};
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
    } else {
        qDebug() << "This shouldn't happen. New catalog entry was not valid.";
        return;
    }


    if (newCatalogEntry == nullptr){ return; }
    name = newCatalogEntry->getName();
    newCatalogEntry->setCatalog(true);

    // Update the catalog with the new entry
    const QModelIndex index = ui->catalogView->selectionModel()->currentIndex();

    if (!myGrid.catalog->insertRow(index.row()+1, index.parent()))
        return;

    updateActions_catalog();

    int column = 0; // The only column is the name
    // Get the index of the child's name
    const QModelIndex child = myGrid.catalog->index(index.row() + 1, column, index.parent());
    // Set the name of the entry
    myGrid.catalog->setData(child, QVariant(name), Qt::EditRole);
    // Save the node reference in the child
    myGrid.catalog->setNodeData(child, newCatalogEntry);

}




void MainWindow::updateActions_catalog()
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
    gridNode* selectedEntry = myGrid.catalog->getNodePtr(indexCatalog);
    gridNode* newInstance = new gridNode(*selectedEntry);

    // Update the catalog with the new entry
    const QModelIndex indexCompList = ui->componentsListView->selectionModel()->currentIndex();

    if (!myGrid.componentsList->insertRow(indexCompList.row()+1, indexCompList.parent())){
        delete newInstance;
        return;
    }

    updateActions_compList();

    QString name = newInstance->getName();
    int column = 0; // The only column is the name
    // Get the index of the child's name
    const QModelIndex child = myGrid.componentsList->index(indexCompList.row() + 1, column, indexCompList.parent());
    // Set the name of the entry
    myGrid.catalog->setData(child, QVariant(name), Qt::EditRole);
    // Save the node reference in the child
    myGrid.catalog->setNodeData(child, newInstance);
}


