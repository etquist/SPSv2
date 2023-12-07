#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser_1->setText("Hi, I'm SPSv2");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_textEdit_textChanged()
{
    QString newText;
    newText = "Boat: " +  ui->textEdit->toPlainText();
    ui->textBrowser_1->setText(newText);
}

