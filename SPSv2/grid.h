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


    // Connectivity Table between components
    // Note - likely shouldn't be a connectivity table because that will get very large very fast (O(n^2)).
    //          A general tree should work well for this, but may require a custom implementation.


    // Components list
    std::vector<component*> componentsList;

    // Catalogue
    std::vector<gridNode*> Catalogue;



    // Common mode equivalent model
    commonModeGrid* cmEqModel;



private:

};
#endif // GRID_H
