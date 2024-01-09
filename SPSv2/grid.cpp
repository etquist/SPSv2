#include "grid.h"

Grid::Grid(std::string catalogFilepath, std::string componentsListFilepath) {
    // Find the number of components and catalog entries based on the data files referenced by user
    int numCatalogEntries = findNumCatalogEntries(catalogFilepath);
    int numComponents = findNumComponents(componentsListFilepath);

    // Initiate the catalog and component list
    Catalog = std::vector<int>(numCatalogEntries);
    componentsList = std::vector<int>(numComponents);

}

Grid::~Grid(){
    // Active components is a vector of pointers to dynamic variables - delete all those
    for(int i = 0; i < activeComponents.size(); i++){
        delete activeComponents[i];
    }

    // Stored in dynamic memory
    delete cmEqModel;
}

// New components list entry
void addNewComponent(){

}

// New catalogue entry
void addNewCatalog(){

}

// Looks for the catalog data file and returns the number of entries for initialization
int findNumCatalogEntries(std::string catalogFilepath){
    return NULL;
}

// Looks for the components list data file and returns the number of entries for initialization
int findNumComponents(std::string componentsListFilepath){
    return NULL;
}

