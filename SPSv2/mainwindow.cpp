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
}
