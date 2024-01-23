#ifndef GRID_H
#define GRID_H


#include <component.h>
#include <gridnode.h>
#include <commonmodegrid.h>
#include "customnodetree.h"


class Grid
{
public:
    Grid();

    Grid(QString catalogFilepath, QString componentsListFilepath);

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

    int numBuses();
    int numLoads();
    int numSources();
    int numFilters();
    int numESMs();
    int numEdges();

    void addCatalogEntry(gridNode*);
    void deleteCatalogEntry(gridNode*);

    customNodeTree* catalog;
    customNodeTree* componentsList;



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
    std::vector<component*>* activeComponents;


    // Common mode equivalent model
    commonModeGrid* cmEqModel;

    int findNumCatalogEntries(QString catalogFilepath);    // Looks for the catalog data file and returns the number of entries for initialization
    int findNumComponents(QString componentsListFilepath); // Looks for the components list data file and returns the number of entries for initialization

    // Creates input dialog for the user to collect and return the name for a new element of type "type"
    QString newName(QString type);


};
#endif // GRID_H
