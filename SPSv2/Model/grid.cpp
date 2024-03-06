#include "grid.h"
#include <QLabel>
#include <QInputDialog>

// Default constructor
Grid::Grid(){
    unassignedName = "UNASSIGNED";
}

Grid::Grid(QString catalogFilepath, QString componentsListFilepath) {
    // Find the number of components and catalog entries based on the data files referenced by user
    int numCatalogEntries = findNumCatalogEntries(catalogFilepath);
    int numComponents = findNumComponents(componentsListFilepath);

    // Initiate the catalog and component list


    unassignedName = "UNASSIGNED";

}

Grid::~Grid(){
    delete catalog;
    delete componentsList;
    delete networkComponents;


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

// Function to create a new generic node in the grid.
// Adds it to the list of all nodes and returns the pointer
gridNode* Grid::newNode(QString inptType, bool prompt, QString inptName){
    QString name;
    if (prompt){
        name = newName(inptType, inptName);
    } else{
        name = inptName;
    }

    if(name == "userCNCL-exit"){ return nullptr; }

    gridNode* myNewNode = new gridNode();  // Create a new dynamic instance of a bus
    myNewNode->setName(name);
    myNewNode->setType(inptType);

    myNewNode->setSN(++lastSN);
    allNodes[myNewNode->getSN()] = myNewNode;   // Add the bus struct to the vector of busses

    return myNewNode;    // return the pointer to the new bus to the user
}


// Function to create a new bus node in the grid.
// Adds it to the list of busses and returns the pointer
gridNode* Grid::newBus(QString inptName){
    QString name = newName("Bus", inptName);
    if(name == "userCNCL-exit"){ return nullptr; }
    gridNode* myNewBus = new gridNode();  // Create a new dynamic instance of a bus
    myNewBus->setName(name);
    myNewBus->setType("Bus");

    busListElement* newBusListElement = new busListElement;   // Create a new struct and assign it's properties
    newBusListElement->bus = myNewBus;
    newBusListElement->busVoltage = myNewBus->getBusVoltage();

    myNewBus->setSN(++lastSN);
    busList[myNewBus->getSN()] = newBusListElement;   // Add the bus struct to the vector of busses

    return myNewBus;    // return the pointer to the new bus to the user
}


// Function to create a new Load in the grid.
// Adds it to the list of loads and returns the pointer
gridNode* Grid::newLoad(QString inptName){
    QString name = newName("Load", inptName);
    if(name == "userCNCL-exit"){ return nullptr; }
    gridNode* myNewLoad = new gridNode();   // Create a new load dynamically
    myNewLoad->setName(name);
    myNewLoad->setType("Load");
    myNewLoad->setSN(++lastSN);
    loads[myNewLoad->getSN()] = myNewLoad; // Add it to the Grid's container
    return myNewLoad;   // return the pointer
}


// Function to create a new Source node in the grid.
// Adds it to the list of sourcess and returns the pointer
gridNode* Grid::newSource(QString inptName){
    QString name = newName("Genset", inptName);
    if(name == "userCNCL-exit"){ return nullptr; }
    gridNode* myNewSource = new gridNode();   // Create a new source dynamically
    myNewSource->setName(name);
    myNewSource->setType("Generator");
    myNewSource->setSN(++lastSN);
    sources[myNewSource->getSN()] = myNewSource; // Add it to the Grid's container
     return myNewSource;
}


// Function to create a new filter node in the grid.
// Adds it to the list of filters and returns the pointer
gridNode* Grid::newFilter(QString inptName){
    QString name = newName("Filter", inptName);
    if(name == "userCNCL-exit"){ return nullptr; }
    gridNode* myNewFilter = new gridNode();   // Create a new filter dynamically
    myNewFilter->setName(name);
    myNewFilter->setType("Filter");
    myNewFilter->setSN(++lastSN);
    filters[myNewFilter->getSN()] = myNewFilter; // Add it to the Grid's container
    return myNewFilter;   // return the pointer
}


// Function to create a new ESM node in the grid.
// Adds it to the list of ESMs and returns the pointer
gridNode* Grid::newESM(QString inptName){
    QString name = newName("ESM", inptName);
    if(name == "userCNCL-exit"){ return nullptr; }
    gridNode* myNewESM = new gridNode();   // Create a new ESM dynamically
    myNewESM->setName(name);
    myNewESM->setType("ESM");
    myNewESM->setSN(++lastSN);
    ESMs[myNewESM->getSN()] = myNewESM; // Add it to the Grid's container
    return myNewESM;   // return the pointer
}

// Function to create a new ESM node in the grid.
// Adds it to the list of ESMs and returns the pointer
gridNode* Grid::newTransformer(QString inptName){
    QString name = newName("Transformer", inptName);
    if(name == "userCNCL-exit"){ return nullptr; }
    gridNode* myNewTransformer = new gridNode();   // Create a new ESM dynamically
    myNewTransformer->setName(name);
    myNewTransformer->setType("Transformer");
    myNewTransformer->setSN(++lastSN);
    transformers[myNewTransformer->getSN()] = myNewTransformer; // Add it to the Grid's container
    return myNewTransformer;   // return the pointer
}


// Function to create a new ESM node in the grid.
// Adds it to the list of ESMs and returns the pointer
gridNode* Grid::newConverter(QString inptName){
    QString name = newName("Converter", inptName);
    if(name == "userCNCL-exit"){ return nullptr; }
    gridNode* myNewConverter = new gridNode();   // Create a new ESM dynamically
    myNewConverter->setName(name);
    myNewConverter->setType("Converter");
    myNewConverter->setSN(++lastSN);
    converters[myNewConverter->getSN()] = myNewConverter; // Add it to the Grid's container
    return myNewConverter;   // return the pointer
}

// Function to create a new ESM node in the grid.
// Adds it to the list of ESMs and returns the pointer
gridNode* Grid::newLine(bool autoCreation, QString inptName){
    QString name = newName("Line", inptName);
    if(name == "userCNCL-exit"){ return nullptr; }
    gridNode* myNewLine = new gridNode();   // Create a new ESM dynamically
    myNewLine->setName(name);
    myNewLine->setType("Line");
    myNewLine->setSN(++lastSN);
    lines[myNewLine->getSN()] = myNewLine; // Add it to the Grid's container
    if (autoCreation){
        // If this is an automatic creation due to dropping an element in graphics window,
        //      add it to the list of all nodes too
        allNodes[myNewLine->getSN()] = myNewLine;
    }
    return myNewLine;   // return the pointer
}


int Grid::numBuses(){
    return busList.size();
}

int Grid::numLoads(){
    return loads.size();
}

int Grid::numSources(){
    return sources.size();
}

int Grid::numFilters(){
    return filters.size();
}

int Grid::numESMs(){
    return ESMs.size();
}

int Grid::numLines(){
    return lines.size();
}

int Grid::numTransformers(){
    return transformers.size();
}

int Grid::numConverters(){
    return converters.size();
}


QString Grid::newName(QString type, QString inptName){
    if (inptName != "no_name_provided - def"){
        return inptName;
    }

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
        numExisting = numTransformers();
    } else if (type == "Transformer") {
        numExisting = numTransformers();
    } else if (type == "Converter") {
        numExisting = numConverters();
    }

    numExisting++;
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

// Returns the corresponding node
gridNode* Grid::findNode(int SN){
    if (allNodes.find(SN) == allNodes.end()){
        qDebug() << "The queried serial number does not exist: " << QString::number(SN);
        return nullptr;
    }
    return allNodes[SN];
}

// Add a new system to the hierarchy
Grid::systemHierNode* Grid::insertSystem(QString name_inpt){
    Grid::systemHierNode* newSys = new Grid::systemHierNode();
    newSys->name = name_inpt;

    systemHierarchyTreeParent->childs.insert(newSys);
    newSys->parent = systemHierarchyTreeParent;


    QString subsysName = name_inpt + "_Shared";
    insertSubSystem(subsysName, newSys);



    return newSys;
}

// Add a new subsystem to the hierarchy
Grid::systemHierNode* Grid::insertSubSystem(QString name_inpt, Grid::systemHierNode* selectedSys){
    Grid::systemHierNode* newSys = new Grid::systemHierNode();
    newSys->name = name_inpt;

    selectedSys->childs.insert(newSys);
    newSys->parent = selectedSys;

    return newSys;
}

// -----
// These two functions find the exact match by looking for a matching pointer to the same system node

Grid::systemHierNode* Grid::findSystem(Grid::systemHierNode* name){
    if (name == systemHierarchyTreeParent){
        return systemHierarchyTreeParent;
    }

    for (auto it = systemHierarchyTreeParent->childs.begin(); it != systemHierarchyTreeParent->childs.end(); ++it) {
        if (*it == name){
            return(*it);
        }
    }
    qDebug() << "Error: Could not find system";
    return nullptr;
}


Grid::systemHierNode* Grid::findSubSystem(Grid::systemHierNode* systemName, Grid::systemHierNode* subsystemName){
    for (auto it = systemHierarchyTreeParent->childs.begin(); it != systemHierarchyTreeParent->childs.end(); ++it) {
        if (*it != systemName){
            continue;
        }

        for (auto it_2 = (*it)->childs.begin(); it_2 != (*it)->childs.end(); ++it_2) {
            if (*it_2 == subsystemName){
                return (*it_2);
            }
        }
    }
    qDebug() << "Error: Could not find subsystem";
    return nullptr;
}



// -----
// These two functions find a match by looking for matching names. They rely on the assumption that system names are not duplicated
Grid::systemHierNode* Grid::findSystem(QString name){
    if (name == systemHierarchyTreeParent->name){
        return systemHierarchyTreeParent;
    }

    for (auto it = systemHierarchyTreeParent->childs.begin(); it != systemHierarchyTreeParent->childs.end(); ++it) {
        if ((*it)->name == name){
            return(*it);
        }
    }
    qDebug() << "Error: Could not find system";
    return nullptr;
}


Grid::systemHierNode* Grid::findSubSystem(QString systemName, QString subsystemName){
    for (auto it = systemHierarchyTreeParent->childs.begin(); it != systemHierarchyTreeParent->childs.end(); ++it) {
        if ((*it)->name != systemName){
            continue;
        }

        for (auto it_2 = (*it)->childs.begin(); it_2 != (*it)->childs.end(); ++it_2) {
            if ((*it_2)->name == subsystemName){
                return (*it_2);
            }
        }
    }
    qDebug() << "Error: Could not find subsystem";
    return nullptr;
}


