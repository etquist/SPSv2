#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->textBrowser_1->setText("Type Something Into the Box Above!");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_textEdit_textChanged()
{
    QString newText;
    newText = ui->textEdit->toPlainText();
    ui->textBrowser_1->setText(newText);
}

