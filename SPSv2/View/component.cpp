#include "component.h"

component::component(QWidget *parent)
    : QLabel{parent}
{}

component::component(QWidget *parent, Grid* myGridRef_Inpt, int SN_Inpt)
    : QLabel{parent}
{
    myGridRef = myGridRef_Inpt;
    SN = SN_Inpt;

    node = myGridRef->findNode(SN);

    name = node->getName();
    type = node->getType();

    // Set the thumbnail based on the type of node, and add the
    if (type == "Bus")          { thumbnail = QPixmap(":/images/bus.png");}
    else if (type == "Load")    { thumbnail = QPixmap(":/images/load.png");}
    else if (type == "ESM")     { thumbnail = QPixmap(":/images/esm.png");}
    else if (type == "Filter")  { thumbnail = QPixmap(":/images/filter.png");}
    else if (type == "Line")    { thumbnail = QPixmap(":/images/line.png");}
    else if (type == "Generator")  { thumbnail = QPixmap(":/images/generator.png");}
    else if (type == "Converter")  { thumbnail = QPixmap(":/images/converter.jpeg");}
    else if (type == "Transformer")  { thumbnail = QPixmap(":/images/transformer.png");}
    else                        { thumbnail = QPixmap(":/images/blank.png");}


    QSize newSize(50, 50);    // resize to consistent size
    thumbnail = thumbnail.scaled(newSize, Qt::KeepAspectRatio);
}

component::~component(){

}



QString component::checkNodeType(){
    // Returns the type of Node that the element is

    QString type;
    return type;
}

void component::updateThumbnail(){

}

QPixmap component::getThumbnail(){
    return thumbnail;
}

int component::getSN(){
    return SN;
}

gridNode* component::getNodeRef(){
    return node;
}
