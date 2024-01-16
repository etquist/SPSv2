#ifndef GRID_H
#define GRID_H

#include <QLabel>
#include <component.h>
#include <gridnode.h>
#include <commonmodegrid.h>


class Grid
{
public:
    Grid();

    Grid(std::string catalogFilepath, std::string componentsListFilepath);

    ~Grid();    // must deal with the bus and element lists

    struct busListElement{
        gridBus* bus;
        double busVoltage;
    };

    // Bus list, with each element including a bus node reference and the its voltage
    std::vector<busListElement*>* busList;
    std::vector<loadNode*>* loads;       // Loads in this microgrid
    std::vector<sourceNode*>* sources;   // Gensets in this microgrid
    std::vector<filterNode*>* filters;   // Filters in this microgrid
    std::vector<esmNode*>* ESMs;         // ESMs in this microgrid


    // Active components placed in the microgrid
    // Vector of pointers to dynamic instances of components
    std::vector<component*>* activeComponents;

    // Components list that appears on the left side of the screen that the user can select and filter from
    // A vector of serial numbers to the component instances
    std::vector<int>* componentsList;

    // Catalog
    // Catalog is a vector of serial numbers to lookup within an external data file
    std::vector<int>* Catalog;

    // Common mode equivalent model
    commonModeGrid* cmEqModel;


    void addNewComponent(); // New components list entry
    void addNewCatalog();   // New catalogue entry

    // Functions for creating new grid objects
    gridBus* newBus();
    loadNode* newLoad();
    sourceNode* newSource();
    filterNode* newFilter();
    esmNode* newESM();


private:
    int findNumCatalogEntries(std::string catalogFilepath);    // Looks for the catalog data file and returns the number of entries for initialization
    int findNumComponents(std::string componentsListFilepath); // Looks for the components list data file and returns the number of entries for initialization
};
#endif // GRID_H
