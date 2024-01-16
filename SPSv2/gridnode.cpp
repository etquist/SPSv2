#include "gridnode.h"

// Custom grid constructor
gridNode::gridNode() {

}

// Custom grid destructor
gridNode::~gridNode(){

}


// Default constructor for a bus
gridBus::gridBus(){
    numBreakers = 0;
    bus_Capacitance = 0;
    bus_Resistance = 0;
    bus_Inductance = 0;
    voltage = 0;
    name = "My New Bus!! :)";

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

// Custom load constructor
loadNode::~loadNode(){

}

// Custom load destructor
loadNode::loadNode(){

}
