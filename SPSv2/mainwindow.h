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
#include <QDesktopServices>
#include <QUrl>



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

    void insertCatalogEntry_shorePower();

public slots:
    void updateActions_catalogNetwork();
    void updateActions_catalogConst();
    void updateActions_compList();

private slots:
    // void item_view_item_path_enter(QString itemPath, QPointF dropPos);
    void on_pushButton_clicked();

    // -------------------------------------
    // Catalog Slots
    // -------------------------------------
    void insertCatalogEntry();
    QModelIndex insertCatalogLabel(QString name = "[Edit Database Name]", bool initialization = false);

    void on_catalogView_doubleClicked(const QModelIndex &index);

    void newCatalogLabel_connector();

    // Changes the Properties label to reflect the selected item
    void updatePropertiesEditorLabel_input(QString name = "Item");

    void on_catalogView_1_clicked(const QModelIndex &index);

    // Opens the github for the project
    void launchGitHub();

    void databaseNetworkHelpButton();
    void databaseConstructorHelpButton();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *Scene;

};
#endif // MAINWINDOW_H
