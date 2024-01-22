#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "grid.h"
#include "gridnode.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    Grid* myGrid = new Grid();

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
    gridBus* newBus = myGrid->newBus();
    QString name = QString::fromStdString(newBus->getName());
    ui->listWidget_3->addItem(name);
}

