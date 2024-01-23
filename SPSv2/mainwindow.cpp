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

    QDir Image_Dir(QCoreApplication::applicationDirPath() + "/Images/");

    for (const QFileInfo &fileinfo : Image_Dir.entryInfoList(QDir::Files))
    {
        ui->listWidget->addItem(fileinfo.absoluteFilePath());
    }
    Scene = new QGraphicsScene(this);

    connect(ui->networkInterface, SIGNAL(itemDrop(QString, QPointF)), this, SLOT(item_view_item_path_enter(QString, QPointF)));
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


// This function is for adding a new entry to the catalog.
// A new node is created based on the user specification
void MainWindow::on_toolButton_4_clicked()
{
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
    ui->listWidget_2->addItem(name);

}






// Double clicking on the catalog should make a new instance of the item in the components list
void MainWindow::on_listWidget_2_itemDoubleClicked(QListWidgetItem *item)
{

}

