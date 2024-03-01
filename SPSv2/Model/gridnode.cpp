#include "gridnode.h"
//--------------------------------------------------
// Base Grid Node functions
//--------------------------------------------------
// Custom grid constructor
gridNode::gridNode() {
    type = "generic";
}

// Custom grid destructor
gridNode::~gridNode(){

}

// Copy Constructor
gridNode::gridNode(const gridNode &original) {
    setType(original.getType());
    uniqueID = original.uniqueID;
    dbName = original.dbName;
    setName("Copy of " + original.getName());
}





const QString& gridNode::getType() const{
    return type;
}

void gridNode::setType(QString newType){
    type = newType;
    return;
}

int gridNode::getSN(){
    return nodeSN;
}

void gridNode::setSN(int newSN){
    nodeSN = newSN;
    return;
}


int gridNode::getUniqueID(){
    return uniqueID;
}

void gridNode::setUniqueID(int newUniqueID){
    uniqueID = newUniqueID;
    return;
}


const QString& gridNode::getName() const{
    return name;
}

void gridNode::setName(QString newName){
    name = newName;
    return;
}

void gridNode::insertConnection(gridNode* newConnect){
    connections.insert(newConnect);
}



//--------------------------------------------------
// Grid Element functions
//--------------------------------------------------






//--------------------------------------------------
// Edge Node functions
//--------------------------------------------------





//--------------------------------------------------
// Transformer Node functions
//--------------------------------------------------




//--------------------------------------------------
// Converter Node functions
//--------------------------------------------------







//--------------------------------------------------
// Source Node functions
//--------------------------------------------------





//--------------------------------------------------
// Load Node functions
//--------------------------------------------------





//--------------------------------------------------
// ESM Node functions
//--------------------------------------------------



//--------------------------------------------------
// ESM Node functions
//--------------------------------------------------



//--------------------------------------------------
// Bus Node functions
//--------------------------------------------------

double gridNode::getBusVoltage(){
    if (type != "Bus"){
        return -1;
    }
    else{
        // Function to retrieve voltage from SQLite
        return -1;
    }

}
