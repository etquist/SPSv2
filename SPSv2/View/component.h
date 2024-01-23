#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>
#include <QLabel>
#include <gridnode.h>
#include <QGraphicsPixmapItem>
#include <QDir>
#include <QCoreApplication>

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
    explicit component(QLabel *parent = nullptr);
    ~component();

    component(gridNode* nodeRef);   // Construct an instance with a node object.

    QString checkNodeType();    // Returns whether the node is a bus, esm, load, etc.

    gridNode* getNodeData(); // Returns all of the data for the referenced node
    void updateThumbnail();
    void updateName();

signals:


private:
    gridNode* nodeRef;  // Reference to the node which contains all the information for this type of component (catalogue entry)
    QString name; // name of the component
    QPixmap thumbnail; // A reference to the QGraphicsPixmapItem (image) that will appear on the screen of the microgrid simulator



};

#endif // COMPONENT_H
