#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "qlistwidget.h"
#include <QMainWindow>
#include <QDir>
#include <QFileInfo>
#include <QString>
#include <QDebug>
#include <QCoreApplication>
#include <QPixmap>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <grid.h>
#include <QMessageBox>
#include <QInputDialog>
#include <QTreeView>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Grid myGrid;

public slots:
    void updateActions_catalog();
    void updateActions_compList();

private slots:
    void item_view_item_path_enter(QString itemPath, QPointF dropPos);
    void on_pushButton_clicked();

    //void on_toolButton_4_clicked();


    // -------------------------------------
    // Catalog Slots
    // -------------------------------------
    void insertCatalogEntry();
    // void insertChild();
    // bool insertColumn();
    // void insertRow();
    // bool removeColumn();
    // void removeRow();

    void on_catalogView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *Scene;

};
#endif // MAINWINDOW_H
