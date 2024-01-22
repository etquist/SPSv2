#include "grid.h"

// Default constructor
Grid::Grid(){
    qDebug() << "default constructor!!!!";


    Catalog = new std::vector<int>;
    componentsList = new std::vector<int>;

    busList = new std::vector<busListElement*>;
    loads = new std::vector<loadNode*>;
    sources = new std::vector<sourceNode*>;
    filters = new std::vector<filterNode*>;
    ESMs = new std::vector<esmNode*>;
    edges = new std::vector<gridEdge*>;

}

Grid::Grid(std::string catalogFilepath, std::string componentsListFilepath) {
    // Find the number of components and catalog entries based on the data files referenced by user
    int numCatalogEntries = findNumCatalogEntries(catalogFilepath);
    int numComponents = findNumComponents(componentsListFilepath);

    // Initiate the catalog and component list
    Catalog = new std::vector<int>(numCatalogEntries);
    componentsList = new std::vector<int>(numComponents);

}

Grid::~Grid(){
    delete Catalog;
    delete componentsList;

    // Active components is a vector of pointers to dynamic variables - delete all those
    for(int i = 0; i < activeComponents->size(); i++){
        delete (*activeComponents)[i];
    }
    delete activeComponents;

    // Stored in dynamic memory
    delete cmEqModel;

    // Properly delete the grid bus vector
    for(int i = 0; i < busList->size(); i++){
        delete (*busList)[i]->bus;
    }
    delete busList;


    // Delete all the dynamic grid nodes
    for(int i = 0; i < loads->size(); i++){
        delete (*loads)[i];
    }
    delete loads;

    for(int i = 0; i < sources->size(); i++){
        delete (*sources)[i];
    }
    delete sources;

    for(int i = 0; i < filters->size(); i++){
        delete (*filters)[i];
    }
    delete filters;

    for(int i = 0; i < ESMs->size(); i++){
        delete (*ESMs)[i];
    }
    delete ESMs;

    for(int i = 0; i < edges->size(); i++){
        delete (*edges)[i];
    }
    delete edges;

}

// New components list entry
void Grid::addNewComponent(){

}

// New catalogue entry
void Grid::addNewCatalog(){

}

// Looks for the catalog data file and returns the number of entries for initialization
int Grid::findNumCatalogEntries(std::string catalogFilepath){
    int sample = 0;
    return sample;
}

// Looks for the components list data file and returns the number of entries for initialization
int Grid::findNumComponents(std::string componentsListFilepath){
    int sample = 0;
    return sample;
}


// Function to create a new bus node in the grid.
// Adds it to the list of busses and returns the pointer
gridBus* Grid::newBus(){
    gridBus* myNewBus = new gridBus();  // Create a new dynamic instance of a bus

    busListElement* newBusListElement = new busListElement;   // Create a new struct and assign it's properties
    newBusListElement->bus = myNewBus;
    newBusListElement->busVoltage = myNewBus->getVoltage();

    if (busList){
        busList->push_back(newBusListElement);   // Add the bus struct to the vector of busses
    }
    else{
        qDebug() << "busList is a null pointer";
        delete newBusListElement;
        delete myNewBus;
    }

    return myNewBus;    // return the pointer to the new bus to the user
}


// Function to create a new Load in the grid.
// Adds it to the list of loads and returns the pointer
loadNode* Grid::newLoad(){
    loadNode* myNewLoad = new loadNode();   // Create a new load dynamically
    loads->push_back(myNewLoad); // Add to the list of loads
    return myNewLoad;   // return the pointer
}


// Function to create a new Source node in the grid.
// Adds it to the list of sourcess and returns the pointer
sourceNode* Grid::newSource(){
    sourceNode* myNewSource = new sourceNode();   // Create a new source dynamically
    sources->push_back(myNewSource); // Add to the list of Sources
    return myNewSource;
}


// Function to create a new filter node in the grid.
// Adds it to the list of filters and returns the pointer
filterNode* Grid::newFilter(){
    filterNode* myNewFilter = new filterNode();   // Create a new filter dynamically
    filters->push_back(myNewFilter); // Add to the list of filterss
    return myNewFilter;   // return the pointer
}


// Function to create a new ESM node in the grid.
// Adds it to the list of ESMs and returns the pointer
esmNode* Grid::newESM(){
    esmNode* myNewESM = new esmNode();   // Create a new ESM dynamically
    ESMs->push_back(myNewESM); // Add to the list of ESMs
    return myNewESM;   // return the pointer
}
