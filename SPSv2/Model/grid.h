#ifndef GRID_H
#define GRID_H


#include <component.h>
#include <gridnode.h>
#include <commonmodegrid.h>
#include "customnodetree.h"
#include <dbmanager.h>


class Grid
{
public:
    Grid();

    Grid(QString catalogFilepath, QString componentsListFilepath);

    ~Grid();    // must deal with the bus and element lists

    struct busListElement{
        gridNode* bus;
        double busVoltage;
    };

    void addNewComponent(); // New components list entry
    void addNewCatalog();   // New catalogue entry

    // Functions for creating new grid objects
    gridNode* newBus(QString inptName = "no_name_provided - def");
    gridNode* newLoad(QString inptName = "no_name_provided - def");
    gridNode* newSource(QString inptName = "no_name_provided - def");
    gridNode* newFilter(QString inptName = "no_name_provided - def");
    gridNode* newESM(QString inptName = "no_name_provided - def");
    gridNode* newTransformer(QString inptName = "no_name_provided - def");
    gridNode* newConverter(QString inptName = "no_name_provided - def");
    gridNode* newLine(QString inptName = "no_name_provided - def");
    gridNode* newNode(QString inptType, bool prompt, QString inptName = "no_name_provided - def");

    int numBuses();
    int numLoads();
    int numSources();
    int numFilters();
    int numESMs();
    int numTransformers();
    int numLines();
    int numConverters();

    void addCatalogEntry(gridNode*);
    void deleteCatalogEntry(gridNode*);

    customNodeTree* catalog;
    customNodeTree* componentsList;


    // Custom DB Manager map from name to class here
    std::unordered_map<QString, dbManager> dbList;
    std::unordered_map<QString, QString> dbPathList;

private:
    // Bus list, with each element including a bus node reference and the its voltage
    std::unordered_map<int, busListElement*> busList;
    std::unordered_map<int, gridNode*> loads;       // Loads in this microgrid
    std::unordered_map<int, gridNode*> sources;   // Gensets in this microgrid
    std::unordered_map<int, gridNode*> filters;   // Filters in this microgrid
    std::unordered_map<int, gridNode*> ESMs;         // ESMs in this microgrid
    std::unordered_map<int, gridNode*> lines;      // Edges (conduits) in the microgrid
    std::unordered_map<int, gridNode*> transformers;      // Transformers in the microgrid
    std::unordered_map<int, gridNode*> converters;      // Converters in the microgrid

    std::unordered_map<int, gridNode*> allNodes;    // A hash table of everything for reference
    int lastSN = 0; // Every time you create a new grid node, increment this by 1


    // Common mode equivalent model
    commonModeGrid* cmEqModel;

    int findNumCatalogEntries(QString catalogFilepath);    // Looks for the catalog data file and returns the number of entries for initialization
    int findNumComponents(QString componentsListFilepath); // Looks for the components list data file and returns the number of entries for initialization

    // Creates input dialog for the user to collect and return the name for a new element of type "type"
    QString newName(QString type, QString inptName = "no_name_provided - def");


};
#endif // GRID_H
