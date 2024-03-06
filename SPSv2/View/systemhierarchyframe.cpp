#include "systemhierarchyframe.h"

systemHierarchyFrame::systemHierarchyFrame(QWidget *parent) : QFrame(parent) {
    selectedNode = nullptr;
}

systemHierarchyFrame::~systemHierarchyFrame(){
    clearFrame();
    selectedNode = nullptr;
}


// This takes the hierarchy, and creates a new label for each subsystem and system with even spacing
// Future improvements need to make the sizing better for expanding windows and avoid overlapping labels
void systemHierarchyFrame::renderView(){
    clearFrame();

    int numSystems = systemHierarchyTreeParent->childs.size(); // don't want to consider the unassigned system

    int width = QFrame::width();
    int height = QFrame::height();


    int systemSpacing_h;
    if (numSystems != 0){
        systemSpacing_h = static_cast<int>(std::trunc(width / (numSystems)));
    } else {
        systemSpacing_h = 0;
    }



    QPoint universalLoc;
    universalLoc.setX(width/2);    // In the center
    universalLoc.setY(height/10);  // 10% of the way down
    systemLabel *universalLabel = new systemLabel(this);
    activeLabels.insert(universalLabel);
    universalLabel->setText(systemHierarchyTreeParent->name);
    universalLabel->move(universalLoc);
    universalLabel->setAlignment(Qt::AlignHCenter);
    universalLabel->refSystemNode = systemHierarchyTreeParent;
    universalLabel->show();


    int i = 0;
    for (auto it = systemHierarchyTreeParent->childs.begin(); it != systemHierarchyTreeParent->childs.end(); ++it) {
        if ((*it)->name == "UNASSIGNED"){
            continue;
        }

        QPoint systemLoc;
        systemLoc.setX(systemSpacing_h*(i+1));    // In the center
        systemLoc.setY(3*height/10);  // 10% of the way down
        systemLabel *SystemLabel = new systemLabel(this);
        activeLabels.insert(SystemLabel);
        SystemLabel->setText((*it)->name);
        SystemLabel->move(systemLoc);
        SystemLabel->setAlignment(Qt::AlignHCenter);
        SystemLabel->refSystemNode = (*it);
        SystemLabel->show();


        int j = 0;
        int prevSize = 0;
        int runningOffset = 0;
        for (auto it_2 = (*it)->childs.begin(); it_2 != (*it)->childs.end(); ++it_2) {

            int subSystemSpacing_h = static_cast<int>(std::trunc(systemSpacing_h / ((*it)->childs.size()+1)));

            // Set the "bounding box" for the subsystem labels
            QPoint leftBound;

            int lb_x = static_cast<int>(std::trunc(systemLoc.x() - 1*systemSpacing_h/4));
            leftBound.setX(lb_x);
            leftBound.setY(5*height/10);

            QPoint subsystemLoc;
            subsystemLoc.setX(leftBound.x());    // In the center
            subsystemLoc.setY(leftBound.y() + runningOffset + prevSize);
            systemLabel *subsystemLabel = new systemLabel(this);
            activeLabels.insert(subsystemLabel);
            subsystemLabel->setText((*it_2)->name);
            subsystemLabel->move(subsystemLoc);
            subsystemLabel->setAlignment(Qt::AlignHCenter);
            subsystemLabel->refSystemNode = (*it_2);
            subsystemLabel->show();

            runningOffset = runningOffset + prevSize;
            prevSize = SystemLabel->height();
            j++;
        }

    i++;
    }
}


void systemHierarchyFrame::clearFrame(){
    for (auto label = activeLabels.begin(); label != activeLabels.end(); label++){
        qDebug() << (*label)->text();
        delete (*label);
    }
    activeLabels.clear();
}


void systemHierarchyFrame::mousePressEvent(QMouseEvent *event)
{
    // First, get the selected item
    systemLabel *child = static_cast<systemLabel*>(childAt(event->position().toPoint()));
    if (!child)
        return;


    // Find the new selection
    Grid::systemHierNode* newSelection = findSystem(child->refSystemNode);

    setSelection(newSelection);

    // Update the list of components within the system
    updateSystemList(newSelection);

}

// This function returns the systems according to the queried name
Grid::systemHierNode* systemHierarchyFrame::findSystem(Grid::systemHierNode* systemRef){
    // Check if it's the parent
    if (systemRef == systemHierarchyTreeParent){
        return systemHierarchyTreeParent;
    }

    // Check for each system, and each of it's subsystems
    for (auto it = systemHierarchyTreeParent->childs.begin(); it != systemHierarchyTreeParent->childs.end(); ++it) {
        if (*it == systemRef){
            return (*it);
        }


        for (auto it_2 = (*it)->childs.begin(); it_2 != (*it)->childs.end(); ++it_2) {
            if (*it_2 == systemRef){
                return (*it_2);
            }
        }
    }

    qDebug() << "Error: Was not able to find selected node in the system hierarchy";
    return nullptr;
}

// Returns the associated systemLabel for the queried name
systemLabel* systemHierarchyFrame::findLabel(Grid::systemHierNode* systemRef){
    for (auto it = activeLabels.begin(); it != activeLabels.end(); it++){
        if ((*it)->refSystemNode == systemRef){
            return (*it);
        }
    }

    qDebug() << "Error: Was not able to find queried label in the active labels";
    return nullptr;
}

// Returns the selected Node
Grid::systemHierNode* systemHierarchyFrame::getSelection(){
    return selectedNode;
}


void systemHierarchyFrame::setSelection(Grid::systemHierNode* newSelection){
    // Remove background shading on original selection
    if (selectedNode != nullptr){
        systemLabel *oldLabel = findLabel(selectedNode);

        if (oldLabel != nullptr){
           oldLabel->setStyleSheet("systemLabel { background-color : white; color : black; }");
        }
    }

    // Update background color for new selection
    systemLabel *newLabel = findLabel(newSelection);
    newLabel->setStyleSheet("systemLabel { background-color : yellow; color : black; }");

    selectedNode = newSelection;
}


// This function updates the list of components in the selected system
void systemHierarchyFrame::updateSystemList(Grid::systemHierNode* newSelection){
    QStringList currentList;
    for (int SN : newSelection->SNs){
        if (myGridRef->findNode(SN) != nullptr){
            QString name = myGridRef->findNode(SN)->getName();
            currentList << name;
        }
    }

    if (currentList.empty()){
        currentList << "<No Components in the System>";
    }
    myGridRef->systemComponentsList->setStringList(currentList);
}


void systemHierarchyFrame::deleteSystem(Grid::systemHierNode* deletionQuery){
    // First, reassign all of the nodes within the to-be-deleted system to the unassigned system
    Grid::systemHierNode* unassigned = myGridRef->findSystem(myGridRef->unassignedName);

    // Delet ethe serial numbers from the query, transfer them to unassigned, and change the name in the network components list
    for (int SN : deletionQuery->SNs){
        unassigned->SNs.insert(SN);

        // If this is a subsystem, delete from the parent system too
        if (deletionQuery->parent != myGridRef->systemHierarchyTreeParent){
            deletionQuery->parent->SNs.erase(SN);
        }

        // Just snag the root index
        QModelIndex rootIndex = myGridRef->networkComponents->index(1, 1).parent();

        // Get the index for the selection corresponding to the current serial number
        QModelIndex currentSelection = myGridRef->networkComponents->findChildInDB(myGridRef->findNode(SN)->getName(), rootIndex);

        myGridRef->networkComponents->setSystem(currentSelection, unassigned->name);
        myGridRef->networkComponents->setSubSystem(currentSelection, "");
    }
    deletionQuery->SNs.clear();


    // Delete all of the child systems
    for (auto it = deletionQuery->childs.begin(); it != deletionQuery->childs.end(); it++){
        // Find each label for the child and delete them from the frame and activeLabels set
        systemLabel* childLabel = findLabel(*it);
        activeLabels.erase(childLabel);
        delete (childLabel);

        delete (*it);
    }
    // Erase the link between the parent and the deletion query
    Grid::systemHierNode* parent = deletionQuery->parent;
    parent->childs.erase(deletionQuery);

    systemLabel* label = findLabel(deletionQuery);
    activeLabels.erase(label);
    delete label;

    delete deletionQuery;
}
