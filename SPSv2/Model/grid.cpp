#include "grid.h"
#include <QLabel>
#include <QInputDialog>

// Default constructor
Grid::Grid(){


    busList = new std::vector<busListElement*>;
    loads = new std::vector<loadNode*>;
    sources = new std::vector<sourceNode*>;
    filters = new std::vector<filterNode*>;
    ESMs = new std::vector<esmNode*>;
    edges = new std::vector<gridEdge*>;

    activeComponents = new std::vector<component*>;


}

Grid::Grid(QString catalogFilepath, QString componentsListFilepath) {
    // Find the number of components and catalog entries based on the data files referenced by user
    int numCatalogEntries = findNumCatalogEntries(catalogFilepath);
    int numComponents = findNumComponents(componentsListFilepath);

    // Initiate the catalog and component list


}

Grid::~Grid(){
    delete catalog;
    delete componentsList;

    // Active components is a vector of pointers to dynamic variables - delete all those
    for(size_t i = 0; i < activeComponents->size(); i++){
        delete (*activeComponents)[i];
    }
    delete activeComponents;

    // Stored in dynamic memory
    delete cmEqModel;

    // Properly delete the grid bus vector
    for(size_t i = 0; i < busList->size(); i++){
        delete (*busList)[i]->bus;
    }
    delete busList;


    // Delete all the dynamic grid nodes
    for(size_t i = 0; i < loads->size(); i++){
        delete (*loads)[i];
    }
    delete loads;

    for(size_t i = 0; i < sources->size(); i++){
        delete (*sources)[i];
    }
    delete sources;

    for(size_t i = 0; i < filters->size(); i++){
        delete (*filters)[i];
    }
    delete filters;

    for(size_t i = 0; i < ESMs->size(); i++){
        delete (*ESMs)[i];
    }
    delete ESMs;

    for(size_t i = 0; i < edges->size(); i++){
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
int Grid::findNumCatalogEntries(QString catalogFilepath){
    int sample = 0;
    return sample;
}

// Looks for the components list data file and returns the number of entries for initialization
int Grid::findNumComponents(QString componentsListFilepath){
    int sample = 0;
    return sample;
}


// Function to create a new bus node in the grid.
// Adds it to the list of busses and returns the pointer
gridBus* Grid::newBus(){
    QString name = newName("Bus");
    if(name == "userCNCL-exit"){ return nullptr; }
    gridBus* myNewBus = new gridBus();  // Create a new dynamic instance of a bus
    myNewBus->setName(name);

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
    QString name = newName("Load");
    if(name == "userCNCL-exit"){ return nullptr; }
    loadNode* myNewLoad = new loadNode();   // Create a new load dynamically
    myNewLoad->setName(name);
    loads->push_back(myNewLoad); // Add to the list of loads
    return myNewLoad;   // return the pointer
}


// Function to create a new Source node in the grid.
// Adds it to the list of sourcess and returns the pointer
sourceNode* Grid::newSource(){
    QString name = newName("Genset");
    if(name == "userCNCL-exit"){ return nullptr; }
    sourceNode* myNewSource = new sourceNode();   // Create a new source dynamically
    myNewSource->setName(name);
    sources->push_back(myNewSource); // Add to the list of Sources
    return myNewSource;
}


// Function to create a new filter node in the grid.
// Adds it to the list of filters and returns the pointer
filterNode* Grid::newFilter(){
    QString name = newName("Filter");
    if(name == "userCNCL-exit"){ return nullptr; }
    filterNode* myNewFilter = new filterNode();   // Create a new filter dynamically
    myNewFilter->setName(name);
    filters->push_back(myNewFilter); // Add to the list of filterss
    return myNewFilter;   // return the pointer
}


// Function to create a new ESM node in the grid.
// Adds it to the list of ESMs and returns the pointer
esmNode* Grid::newESM(){
    QString name = newName("ESM");
    if(name == "userCNCL-exit"){ return nullptr; }
    esmNode* myNewESM = new esmNode();   // Create a new ESM dynamically
    myNewESM->setName(name);
    ESMs->push_back(myNewESM); // Add to the list of ESMs
    return myNewESM;   // return the pointer
}

int Grid::numBuses(){
    return busList->size();
}

int Grid::numLoads(){
    return loads->size();
}

int Grid::numSources(){
    return sources->size();
}

int Grid::numFilters(){
    return filters->size();
}

int Grid::numESMs(){
    return ESMs->size();
}

int Grid::numEdges(){
    return edges->size();
}


QString Grid::newName(QString type){
    int numExisting = 0;
    if (type == "Bus"){
        numExisting = numBuses();
    } else if (type == "Load"){
        numExisting = numLoads();
    } else if (type == "Genset") {
        numExisting = numSources();
    } else if (type == "ESM"){
        numExisting = numESMs();
    } else if (type == "Filter") {
        numExisting = numFilters();
    }

    bool ok;
    QString defaultTxt = type + QString::number(numExisting);
    QString prompt = "Enter the " + type + "'s name.";
    QString name = QInputDialog::getText(nullptr, "Item Name", prompt, QLineEdit::Normal, defaultTxt, &ok);

    if (ok && !name.isEmpty()) {
        return name;
    } else {
        return "userCNCL-exit"; // Abort the creation
    }
}
