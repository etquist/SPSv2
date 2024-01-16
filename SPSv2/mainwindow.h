#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
    Grid *myGrid;

private slots:
    void item_view_item_path_enter(QString itemPath, QPointF dropPos);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *Scene;

};
#endif // MAINWINDOW_H
