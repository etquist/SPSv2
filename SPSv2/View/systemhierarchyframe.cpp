#include "systemhierarchyframe.h"

systemHierarchyFrame::systemHierarchyFrame(QWidget *parent) : QFrame(parent) {}

systemHierarchyFrame::~systemHierarchyFrame(){
    clearFrame();
}

void systemHierarchyFrame::renderView(){
    clearFrame();

    int numSystems = systemHierarchyTreeParent->childs.size();

    int numSubsystems = 0;
    for (auto it = systemHierarchyTreeParent->childs.begin(); it != systemHierarchyTreeParent->childs.end(); ++it) {
        numSubsystems = numSubsystems + (*it)->childs.size();
    }

    int width = QFrame::width();
    int height = QFrame::height();


    int systemSpacing_h = static_cast<int>(std::trunc(width / (numSystems+2)));
    int subSystemSpacing_h = static_cast<int>(std::trunc(width / (numSubsystems+2)));

    QPoint unassignedLoc;
    unassignedLoc.setX(width/2);    // In the center
    unassignedLoc.setY(height/10);  // 10% of the way down
    QLabel *unassignedLabel = new QLabel(this);
    activeLabels.insert(unassignedLabel);
    unassignedLabel->setText(systemHierarchyTreeParent->name);
    unassignedLabel->move(unassignedLoc);
    unassignedLabel->show();

    int i = 0;
    for (auto it = systemHierarchyTreeParent->childs.begin(); it != systemHierarchyTreeParent->childs.end(); ++it) {
        QPoint systemLoc;
        systemLoc.setX(systemSpacing_h*(i+1));    // In the center
        systemLoc.setY(3*height/10);  // 10% of the way down
        QLabel *systemLabel = new QLabel(this);
        activeLabels.insert(systemLabel);
        systemLabel->setText((*it)->name);
        systemLabel->move(systemLoc);
        systemLabel->show();


        int j = 0;
        for (auto it_2 = (*it)->childs.begin(); it_2 != (*it)->childs.end(); ++it_2) {
            QPoint subsystemLoc;
            subsystemLoc.setX(subSystemSpacing_h*(i+1));    // In the center
            subsystemLoc.setY(7*height/10);  // 10% of the way down
           QLabel *subsystemLabel = new QLabel(this);
            activeLabels.insert(subsystemLabel);
            subsystemLabel->setText((*it_2)->name);
            subsystemLabel->move(subsystemLoc);
            subsystemLabel->show();
            j++;
        }

    i++;
    }
}


void systemHierarchyFrame::clearFrame(){
    for (auto label = activeLabels.begin(); label != activeLabels.end(); label++){
        delete (*label);
        qDebug() << (*label)->text();
    }
    activeLabels.clear();
}




