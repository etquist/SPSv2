#ifndef SYSTEMHIERARCHYFRAME_H
#define SYSTEMHIERARCHYFRAME_H

#include <QFrame>
#include <grid.h>
#include <QPoint>
#include <cmath>
#include "systemlabel.h"

class systemHierarchyFrame : public QFrame
{
public:
    explicit systemHierarchyFrame(QWidget *parent = nullptr);
    ~systemHierarchyFrame();

    void renderView();
    void clearFrame();


    Grid* myGridRef;
    Grid::systemHierNode* systemHierarchyTreeParent;

    Grid::systemHierNode* getSelection();
    void setSelection(Grid::systemHierNode* newSelection);

    void updateSystemList(Grid::systemHierNode* newSelection);

    void deleteSystem(Grid::systemHierNode* newSelection);
protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    std::set<systemLabel*> activeLabels;
    Grid::systemHierNode* selectedNode;

    Grid::systemHierNode* findSystem(Grid::systemHierNode* systemRef);
    systemLabel* findLabel(Grid::systemHierNode* systemRef);


};

#endif // SYSTEMHIERARCHYFRAME_H
