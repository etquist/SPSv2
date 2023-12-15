#include "mainwindow.h"
#include "ui_mainwindow.h"

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

    connect(ui->networkInterface, SIGNAL(itemDrop(QString)), this, SLOT(item_view_item_path_enter(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::item_view_item_path_enter(QString itemPath){
    qDebug() << itemPath;

    if (Scene->items().count() > 0) Scene->clear();
    QPixmap Image(itemPath);
    Scene->addPixmap(Image);
    Scene->setSceneRect(Image.rect());
    ui->networkInterface->setScene(Scene);
    ui->networkInterface->setSceneRect(Scene->sceneRect());
    ui->networkInterface->fitInView(Scene->sceneRect(), Qt::KeepAspectRatio);
    ui->networkInterface->viewport()->update();
    ui->networkInterface->update();
    ui->networkInterface->show();
}
