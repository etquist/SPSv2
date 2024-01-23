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
    setType(original.type);
    serialNumber = original.serialNumber;
    setCatalog(original.catalog);
    setName("Copy of " + original.getName());
}

const QString& gridNode::getType() const{
    return type;
}

void gridNode::setType(QString newType){
    type = newType;
    return;
}


const QString& gridNode::getName() const{
    return name;
}

void gridNode::setName(QString newName){
    name = newName;
    return;
}

const bool& gridNode::checkCatalog() const{
    return catalog;
}

void gridNode::setCatalog(bool set){
    catalog = set;
    return;
}




//--------------------------------------------------
// Grid Element functions
//--------------------------------------------------

gridElement::gridElement(){

}

gridElement::~gridElement(){

}




//--------------------------------------------------
// Edge Node functions
//--------------------------------------------------

gridEdge::gridEdge(){
    setType("edge");
}

gridEdge::~gridEdge(){

}





//--------------------------------------------------
// Source Node functions
//--------------------------------------------------

sourceNode::sourceNode(){
    setType("source");
}

sourceNode::~sourceNode(){

}



//--------------------------------------------------
// Load Node functions
//--------------------------------------------------


// Custom load contructor
loadNode::loadNode(){
    setType("load");
}

// Custom load destructor
loadNode::~loadNode(){

}

loadNode::loadNode(const loadNode &original){
    setName("Copy of " + original.getName());
    setCatalog(original.checkCatalog());
    setType(original.getType());


    powerType = original.powerType;
    voltage = original.voltage;
    constPowerDemand = original.constPowerDemand;
    numPhases = original.numPhases;
    phaseA = original.phaseA;
    phaseB = original.phaseB;
    phaseC = original.phaseC;

    profileType = original.profileType;

    transientMatrixSize = original.transientMatrixSize;

    // Create a deep copy of the transient matrix
    transientMatrix = new std::vector<std::vector<transientElement*>>;
    for(size_t i = 0; i < transientMatrix->size(); i++){
        for(size_t j = 0; j < transientMatrix[i].size(); j++){
            transientElement* newTransEl = new transientElement;
            newTransEl->type = original.transientMatrix->at(i).at(j)->type;
            transientMatrix->at(i).at(j) = newTransEl;
        }
    }

}


//--------------------------------------------------
// ESM Node functions
//--------------------------------------------------
esmNode::esmNode(){
    setType("esm");
}

esmNode::~esmNode(){

}


//--------------------------------------------------
// ESM Node functions
//--------------------------------------------------
filterNode::filterNode(){
    setType("filter");
}

filterNode::~filterNode(){

}


//--------------------------------------------------
// Bus Node functions
//--------------------------------------------------

// Default constructor for a bus
gridBus::gridBus(){
    setType("bus");

    numBreakers = 0;
    bus_Capacitance = 0;
    bus_Resistance = 0;
    bus_Inductance = 0;
    voltage = 0;
    setName("My New Bus!! :)");

}

// Default destructor
gridBus::~gridBus(){
    // Delete dynamically allocated resources

    // Don't delete the pointers in the structural containers because
    //      they will be deleted when the whole grid is deleted
}

gridBus::gridBus(const gridBus &original) {
    setName("Copy of " + original.getName());
    setCatalog(original.checkCatalog());
    setType(original.getType());

    numBreakers = original.numBreakers;
    bus_Capacitance = original.bus_Capacitance;
    bus_Inductance = original.bus_Inductance;
    bus_Resistance = original.bus_Resistance;
    voltage = original.voltage;

    // We don't want the same bus connections for the copy
    loads = std::vector<loadNode*>();
    gensets = std::vector<sourceNode*>();
    childSWBDs = std::vector<gridBus*>();
    equalSWBDs = std::vector<gridBus*>();
    parentSWBDs = std::vector<gridBus*>();
    filters = std::vector<filterNode*>();
    ESMs = std::vector<esmNode*>();



}

double gridBus::getVoltage(){
    return voltage;
}
