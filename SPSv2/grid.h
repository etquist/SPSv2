#ifndef GRID_H
#define GRID_H

#include <QLabel>
#include <component.h>
#include <gridnode.h>
#include <commonmodegrid.h>


class Grid
{
public:
    Grid(std::string catalogFilepath, std::string componentsListFilepath);

    ~Grid();    // must deal with the bus list

    struct busListElement{
        gridBus* bus;
        double busVoltage;
    };

    // Bus list, with each element including a bus node reference and the its voltage
    std::vector<busListElement> busList;


    // Active components placed in the microgrid
    // Vector of pointers to dynamic instances of components
    std::vector<component*> activeComponents;

    // Components list that appears on the left side of the screen that the user can select and filter from
    // A vector of serial numbers to the component instances
    std::vector<int> componentsList;

    // Catalog
    // Catalog is a vector of serial numbers to lookup within an external data file
    std::vector<int> Catalog;

    // Common mode equivalent model
    commonModeGrid* cmEqModel;


    void addNewComponent(); // New components list entry
    void addNewCatalog();   // New catalogue entry


private:
    int findNumCatalogEntries(std::string catalogFilepath);    // Looks for the catalog data file and returns the number of entries for initialization
    int findNumComponents(std::string componentsListFilepath); // Looks for the components list data file and returns the number of entries for initialization
};
#endif // GRID_H
