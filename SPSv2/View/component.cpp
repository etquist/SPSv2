#include "component.h"

component::component(QLabel *parent)
    : QLabel{parent}
{}

component::~component(){

}

component::component(gridNode* inputNodeRef){

    nodeRef = inputNodeRef;
    name = nodeRef->getName();
    QString type = nodeRef->getType();


    // Set the thumbnail based on the type of node
    if (type == "bus")          { thumbnail = QPixmap(":/thumbnailImages/bus.png");}
    else if (type == "load")    { thumbnail = QPixmap(":/thumbnailImages/load.png");}
    else if (type == "esm")     { thumbnail = QPixmap(":/thumbnailImages/esm.png");}
    else if (type == "filter")  { thumbnail = QPixmap(":/thumbnailImages/filter.png");}
    else if (type == "edge")    { thumbnail = QPixmap(":/thumbnailImages/edge.png");}
    else if (type == "source")  { thumbnail = QPixmap(":/thumbnailImages/source.png");}
    else                        { thumbnail = QPixmap(":/thumbnailImages/blank.png");}

}

QString component::checkNodeType(){
    // Returns the type of Node that the element is

    QString type;
    type = nodeRef->getType();
    return type;
}

gridNode* component::getNodeData(){
    return nodeRef;
}
