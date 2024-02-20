#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QCoreApplication>
#include <grid.h>

// This is a custom implementation of QLabel which will
//      hold the relevant information needed for each
//      component in the grid
// The purpose of this is to have a QLabel object which
//      can be used in a drag and drop interface, and contain
//      the information of the nodes while visualizing the
//      microgrid structure
class component : public QLabel
{
    Q_OBJECT
public:
    explicit component(QWidget *parent = nullptr);
    explicit component(QWidget *parent = nullptr, Grid* myGridRef_Inpt = nullptr, int SN = -1);
    ~component();

    QString checkNodeType();    // Returns whether the node is a bus, esm, load, etc.

    gridNode* getNodeData(); // Returns all of the data for the referenced node
    void updateThumbnail();
    void updateName();
    QPixmap getThumbnail();
    int getSN();

signals:


private:
    QString type;
    QString name; // name of the component -- Used to look up the corresponding gridNode in the database hash table
    QPixmap thumbnail; // A reference to the QGraphicsPixmapItem (image) that will appear on the screen of the microgrid simulator
    int SN; // Serial number reference to the gridNode storage container in myGrid
    gridNode* node;

    Grid* myGridRef;
};

#endif // COMPONENT_H
