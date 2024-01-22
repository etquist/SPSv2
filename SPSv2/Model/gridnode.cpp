#include "gridnode.h"

// Custom grid constructor
gridNode::gridNode() {
    type = "generic";
}

// Custom grid destructor
gridNode::~gridNode(){

}

std::string gridNode::getType(){
    return type;
}

void gridNode::setType(std::string newType){
    type = newType;
    return;
}


std::string gridNode::getName(){
    return name;
}

void gridNode::setName(std::string newName){
    name = newName;
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

    busTrace = nullptr;
    exportTrace = nullptr;

}

// Default destructor
gridBus::~gridBus(){
    // Delete dynamically allocated resources
    delete busTrace;
    delete exportTrace;

    // Don't delete the pointers in the structural containers because
    //      they will be deleted when the whole grid is deleted
}

double gridBus::getVoltage(){
    return voltage;
}
