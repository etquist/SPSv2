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

    void addNewComponent(); // New components list entry
    void addNewCatalog();   // New catalogue entry

    // Functions for creating new grid objects
    gridBus* newBus();
    loadNode* newLoad();
    sourceNode* newSource();
    filterNode* newFilter();
    esmNode* newESM();


private:
    // Bus list, with each element including a bus node reference and the its voltage
    std::vector<busListElement*>* busList;
    std::vector<loadNode*>* loads;       // Loads in this microgrid
    std::vector<sourceNode*>* sources;   // Gensets in this microgrid
    std::vector<filterNode*>* filters;   // Filters in this microgrid
    std::vector<esmNode*>* ESMs;         // ESMs in this microgrid
    std::vector<gridEdge*>* edges;

    // A vector of references to the component instances. Component objects contain information to the specific instance of the grid element
    //  and are also a subset of QLabels so they can be easily placed on a drag and drop interface. This list can also be used in the "Rats list"
    // on the left side of the screen
    std::vector<int>* componentsList;
    std::vector<component*>* activeComponents;

    // Catalog
    // Catalog is a vector of serial numbers to lookup within an external data file
    std::vector<int>* Catalog;

    // Common mode equivalent model
    commonModeGrid* cmEqModel;

    int findNumCatalogEntries(std::string catalogFilepath);    // Looks for the catalog data file and returns the number of entries for initialization
    int findNumComponents(std::string componentsListFilepath); // Looks for the components list data file and returns the number of entries for initialization
};
#endif // GRID_H
