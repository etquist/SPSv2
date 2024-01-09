#ifndef COMPONENT_H
#define COMPONENT_H

#include <QObject>
#include <QLabel>
#include <gridnode.h>

// This is a custom implementation of QLabel which will hold the relevant information needed for each component in the grid
class component : public QLabel
{
    Q_OBJECT
public:
    explicit component(QObject *parent = nullptr);

signals:


private:
    gridNode* componentTypeRef;  // Reference to the node which contains all the information for this type of component (catalogue entry)

};

#endif // COMPONENT_H