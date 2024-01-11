#ifndef GRIDNODE_H
#define GRIDNODE_H

#include<QObject>

// Highest level of class hierarchy that describes the components of a microgrid
class gridNode
{
public:
    gridNode();
    ~gridNode();
    int serialNumber;
    std::string thumbnailImagePath;  // This is the image that will appear in the grid
    bool validityCheck();

private:
    void loadFromDatafile(std::string filepath);    // Populate the node instance from a datafile


};

// Derived class from gridNode, with specific info relevant to grid edges.
// Grid edges contain information on transmission cabling, power converters, etc.
class gridEdge : public gridNode{
    // General
    double voltageA;    //  "Input" voltage to the A side. B side determined by edge properties
    int numPhasesA;    // Valid between 1-3
    int numPhasesB;    // ditto
    double breakerRating;   // (Amps)

    // Conduit Properties
    double conduit_Diameter; // (mm) - diameter of each single conduit (i.e., for one of the 3/4 conduits in a 3-Phase system)
    double conduit_Capacitance;  // (F)
    double conduit_Resistance;   // (Ohm)
    double conduit_Inductance;   // (H)

    // Converter Properties
    bool typeA;     // 0 = DC, 1 = AC
    bool typeB;
    double converter_Capacitance;  // (F)
    double converter_Resistance;   // (Ohm)
    double converter_Inductance;   // (H)

    // Transformer Properties
    bool transformer_3pTypeA;       // 0 = Delta, 1 = Wye
    bool transformer_3pTypeB;
    double transformer_windingRatio;    // (-) Winding ratio
    double transformer_Capacitance;  // (F)
    double transformer_Resistance;   // (Ohm)
    double transformer_Inductance;   // (H)

    // Functions
    bool validityCheck();

private:
    void loadFromDatafile(std::string filepath);    // Populate the node instance from a datafile


};

// Derived class from gridNode, with specific info relevant to elements within a microgrid.
// Elements are components like AC machines, energy storage modules, resistive heaters, etc.
class gridElement : public gridNode{

    bool validityCheck();

private:
    void loadFromDatafile(std::string filepath);    // Populate the node instance from a datafile

};

// Derived class from gridElement, with specific info relevant to sources (gensets)
class sourceNode : public gridElement{

    bool validityCheck();
};

// Derived class from gridElement, with specific info relevant to loads
class loadNode : public gridElement{
    ~loadNode();    // CUSTOM: need to delete the dynamic transient table

    // vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    // Load General Info
    bool powerType;     // 0 = DC, 1 = AC

    double voltage;       // (V) nominal voltage of the load
    double constPowerDemand;    // (W) nominal power draw

    bool numPhases;     // accepted 1, 2, or 3 (if AC), 1 (if DC)
    bool phaseA;        // validity check needs to make sure the numPhases aligns with boolean selection
    bool phaseB;
    bool phaseC;
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


    // vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    // Profile Information
    int profileType; // 0: Trace, 1: Function



    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


    // vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    // Transients
    struct transientElement{
        int type;   // 0: , 1: , 2:

        // Type 0: (null)


        // Type 1: (trace)


        // Type 2: (function)

    };

    // pointer to dynamic instance of transient matrix.
    // Each entry in the matrix refers to a dynamic transientElement
    int transientMatrixSize;    // The number of states
    std::vector<std::vector<transientElement*>>* transientMatrix;
    // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    bool validityCheck();

private:
    void loadFromDatafile(std::string filepath);    // Populate the node instance from a datafile

};

// Derived class from gridElement, with specific info relevant to energy storage modules
class esmNode : public gridElement{

    bool validityCheck();

private:
    void loadFromDatafile(std::string filepath);    // Populate the node instance from a datafile

};

// Derived class from gridElement, with specific info relevant to filters
class filterNode : public gridElement{

    bool validityCheck();

private:
    void loadFromDatafile(std::string filepath);    // Populate the node instance from a datafile

};


// Derived class from grid node, with information relevent to busses
class gridBus : public gridNode{
    int numBreakers;    //  (-) number of connection points available
    double bus_Capacitance;  // (F)     Expected impediance of bus
    double bus_Resistance;   // (Ohm)
    double bus_Inductance;   // (H)

    std::vector<loadNode*> loads;       // Loads which are directly connected to this bus
    std::vector<sourceNode*> gensets;   // Gensets which provide power directly to this bus
    std::vector<gridBus*> childSWBDs;   // Busses which receieve power from this bus
    std::vector<gridBus*> equalSWBDs;   // Busses which are share power with this bus (Equal voltage with bi-directional power sharing ability in connecting edge)
    std::vector<gridBus*> parentSWBDs;  // Busses which give power to this bus
    std::vector<filterNode*> filters;   // Filters which are directly connected to this bus
    std::vector<esmNode*> ESMs;         // Energy storage modules which are directly connected to this bus


    bool validityCheck();

private:
    void loadFromDatafile(std::string filepath);    // Populate the node instance from a datafile

    std::vector<double>* busTrace;
    std::vector<double>* exportTrace;


};

#endif // GRIDNODE_H
