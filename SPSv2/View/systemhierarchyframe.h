#ifndef SYSTEMHIERARCHYFRAME_H
#define SYSTEMHIERARCHYFRAME_H

#include <QFrame>
#include <grid.h>
#include <QPoint>
#include <cmath>

class systemHierarchyFrame : public QFrame
{
public:
    explicit systemHierarchyFrame(QWidget *parent = nullptr);
    ~systemHierarchyFrame();

    void renderView();
    void clearFrame();


    Grid* myGridRef;
    Grid::systemHierNode* systemHierarchyTreeParent;

private:
    std::set<QLabel*> activeLabels;



};

#endif // SYSTEMHIERARCHYFRAME_H
