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
#include <QMessageBox>
#include <QInputDialog>
#include <QTreeView>
#include <QDesktopServices>
#include <QUrl>
#include "dbManager.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QInputDialog>
#include <QCoreApplication>
#include "grideditwindow.h"



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
    void updateActions_netCompList();

private slots:
    // void item_view_item_path_enter(QString itemPath, QPointF dropPos);
    void on_pushButton_clicked();

    // -------------------------------------
    // Catalog Slots
    // -------------------------------------
    void newDatabaseEntryButton();
    void insertCatalogEntry(QString nameInpt = "default", QString typeInpt = "default", int uniqueIDInpt = -1);
    QModelIndex insertCatalogLabel(QString name = "[Edit Database Name]", bool promptForPath = false, bool initialization = false);

    void on_catalogView_doubleClicked(const QModelIndex &index);

    void newCatalogLabel_connector();

    // Changes the Properties label to reflect the selected item
    void updatePropertiesEditorLabel_input(QString name = "Item");

    void on_catalogView_1_clicked(const QModelIndex &index);

    // Opens the github for the project
    void launchGitHub();

    void databaseNetworkHelpButton();
    void databaseConstructorHelpButton();

    // Open the file explorer and allow the user to select a database for use within the SPS
    void importDatabase();


    void on_catalogView_1_doubleClicked(const QModelIndex &index);

    void deleteCatalogEntry();


    void on_pushButton_9_clicked();

    void on_pushButton_10_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *Scene;

};
#endif // MAINWINDOW_H
