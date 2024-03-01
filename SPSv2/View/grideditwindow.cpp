#include "grideditwindow.h"
#include <QtWidgets>


gridEditWindow::gridEditWindow(QWidget *parent) : QFrame(parent){
    setAcceptDrops(true);
}

void gridEditWindow::dragEnterEvent(QDragEnterEvent *event)
{
    qDebug() << "dragEnterEvent";
    event->accept();

}

//     if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
//         if (event->source() == this) {
//             event->setDropAction(Qt::MoveAction);
//             event->accept();
//         } else {
//             event->acceptProposedAction();
//         }
//     } else {
//         event->ignore();
//     }
// }

void gridEditWindow::dragMoveEvent(QDragMoveEvent *event)
{
    qDebug() << "dragMoveEvent";
    qDebug() << event->mimeData()->formats();
    if (event->mimeData()->hasFormat("compExport")) {
        qDebug() << "From Tree";
        event->setDropAction(Qt::MoveAction);
        event->accept();
    } else {
        qDebug() << "Not from tree";
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->ignore();    // Don't accept other dataformats that arent from this window
        }
    }

}
    // if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
    //     if (event->source() == this) {
    //         event->setDropAction(Qt::MoveAction);
    //         event->accept();
    //     } else {
    //         event->acceptProposedAction();
    //     }
    // } else {
    //     event->ignore();
    // }
// }

void gridEditWindow::dropEvent(QDropEvent *event)
{
    qDebug() << "dropEvent";
    if (event->mimeData()->hasFormat("compExport")) {
        qDebug() << "From Tree";
        // This is coming from the Components List Tree
        QByteArray itemData = event->mimeData()->data("compExport");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        int SN;
        QString type;
        dataStream >> SN >> type;
        qDebug() << "Node retrieved: SN =  " << SN << ", Type = " << type;

        // Check if the drop was made onto an existing component.
        component *droppedOnIcon = static_cast<component*>(childAt(event->position().toPoint()));
        bool validDropPoint = true;
        QString dropType = "Null";
        if (droppedOnIcon){
            dropType = droppedOnIcon->getNodeRef()->getType();
            if (dropType == "Line"){
                // You cannot drop a node onto an existing line (cable)
                validDropPoint = false;
            }
        } else{
            // It wasn't dropped on anything
            validDropPoint = false;
        }


        // check if this already exists in the edit window
        if (SN_list.find(SN) != SN_list.end()){
            // The node has already been placed
            event->ignore();
            return;
        } else if (SN_list.empty() && type != "Bus"){
            // The first node placed MUST be a bus
            event->ignore();
            return;
        } else{
            // Otherwise, add it to the list and carry on. No connection has been made, so the network is temporarily invalid.
            SN_list.insert(SN);
        }

        // Create a new icon to visually represent the node in the graphics viewer
        component* newIcon = new component(this, myGridRef, SN);

        // Create a new entry in the network components list for the component
        if (type != "Line"){
            const QModelIndex indexNetList = networkComponentsList->selectionModel()->currentIndex();
            myGridRef->networkComponents->insertRow(indexNetList.row()+1, indexNetList.parent());
            QModelIndex newEntry = myGridRef->networkComponents->index(indexNetList.row() + 1, 0, indexNetList.parent());
            QList<QVariant> inptData;
            inptData << QVariant(newIcon->getNodeRef()->getName()) << QVariant(newIcon->getNodeRef()->getType()) << QVariant(newIcon->getNodeRef()->getSN()) << QVariant("UNASSIGNED");;
            myGridRef->networkComponents->setFullData(newEntry, inptData, Qt::EditRole);
            myGridRef->networkComponents->setNodeData(newEntry, newIcon->getNodeRef());

            myGridRef->systemHierarchyTreeParent->SNs.insert(newIcon->getSN());
        }

        bool newLineCreated = false;
        gridNode* newLine; // Remains un-initialized if newLineCreated is false

        if (SN_list.size() == 1){
            // If this is the first node to be placed, make it the root for the grid.
            myGridRef->rootNode = newIcon->getNodeRef();
        } else if (validDropPoint){
            // Make a new line, and use it to connect the new node to the dropped on node
            gridNode* droppedOnNode = droppedOnIcon->getNodeRef();

            QString autoName = droppedOnNode->getName() + " - " + newIcon->getNodeRef()->getName();
            newLine = myGridRef->newLine(true, autoName);
            SN_list.insert(newLine->getSN());


            // Create a new entry in the components list for the new line
            const QModelIndex index = myGridRef->componentsList->findChildInDB(newIcon->getNodeRef()->getName(), myGridRef->componentsList->index(1, 0));
            myGridRef->componentsList->insertRow(index.row()+1, index.parent());

            int column = 0; // The only column is the name
            // Get the index of the child's name
            QModelIndex child = myGridRef->componentsList->index(index.row() + 1, column, index.parent());
            // Set the name of the entry
            QList<QVariant> lineInptData;
            lineInptData << QVariant(newLine->getName()) << QVariant(newLine->getType()) << QVariant(newLine->getSN());
            myGridRef->componentsList->setFullData(child, lineInptData, Qt::EditRole);
            // Save the node reference in the child
            myGridRef->componentsList->setNodeData(child, newLine);


            // Not going to include lines in the network components

            // // Create a new entry in the network components list for the new line
            // const QModelIndex net_index = myGridRef->networkComponents->findChildInDB(newIcon->getNodeRef()->getName(), myGridRef->networkComponents->index(1, 0));
            // myGridRef->networkComponents->insertRow(net_index.row()+1, net_index.parent());
            // // Get the index of the child's name
            // lineInptData << QVariant("UNASSIGNED");
            // child = myGridRef->networkComponents->index(net_index.row() + 1, column, net_index.parent());
            // myGridRef->networkComponents->setFullData(child, lineInptData, Qt::EditRole);
            // myGridRef->networkComponents->setNodeData(child, newLine);


            // Connect 'em all
            newIcon->getNodeRef()->insertConnection(newLine);
            newLine->insertConnection(droppedOnNode);
            droppedOnNode->insertConnection(newLine);
            newLine->insertConnection(newIcon->getNodeRef());

            newLineCreated = true;
        } else {
            // Don't make a conneciton to anything
        }



        // Set the pixmap representation as the thumbnail
        newIcon->setPixmap(newIcon->getThumbnail());


        QPoint newIconOffset;  // offset point based on the size of the pixmap
        // Set offset based on the pixmap
        newIconOffset.setX(newIcon->pixmap().size().width() / 2);
        newIconOffset.setY(newIcon->pixmap().size().height() / 2);


        if (newLineCreated){
            // Now make an icon for the new line
            component* newLineIcon = new component(this, myGridRef, newLine->getSN());
            // Set the pixmap representation as the thumbnail
            newLineIcon->setPixmap(newLineIcon->getThumbnail());

            // First, we want to move the icon off of the element it was placed on.
            // For now, this is just horizontally...
            newIconOffset.setX(newIconOffset.x() + (droppedOnIcon->pixmap().width()/2 + newLineIcon->pixmap().width())*1.1);



            QPoint newLineOffset;  // offset point based on the size of the pixmap
            newLineOffset.setX((droppedOnIcon->pos().x() - newIcon->pos().x()) / 2 - newLineIcon->pixmap().size().width()/2);
            newLineOffset.setY(newLineIcon->pixmap().size().height() / 2);



            // Move the icon to the location of the mouse drop
            newLineIcon->move(event->position().toPoint() - newLineOffset);
            newLineIcon->show();
            newLineIcon->setAttribute(Qt::WA_DeleteOnClose);
        }

        // Move the icon to the location of the mouse drop
        newIcon->move(event->position().toPoint() - newIconOffset);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

        event->acceptProposedAction();
    }
    else if (event->mimeData()->hasFormat("compInternalSelect")) {
        // This is coming from elsewhere in the edit window
        if (event->source() == this) {
            QByteArray itemData = event->mimeData()->data("compInternalSelect");
            QDataStream dataStream(&itemData, QIODevice::ReadOnly);

            QPixmap pixmap;
            QPoint offset;
            int SN;
            dataStream >> pixmap >> offset >> SN;

            // Create a new
            component* newIcon = new component(this, myGridRef, SN);
            newIcon->setPixmap(pixmap);
            newIcon->move(event->position().toPoint() - offset);
            newIcon->show();
            newIcon->setAttribute(Qt::WA_DeleteOnClose);

            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->ignore();
        }
    } else {
        qDebug() << "Not from tree or edit window";
        event->ignore();
    }
}

//
//     } else if (event->mimeData()->hasFormat("fromTree")) {
//         // This is coming from the Components List Tree
//         QByteArray itemData = event->mimeData()->data("fromTree");
//         QDataStream dataStream(&itemData, QIODevice::ReadOnly);

//         int SN;
//         dataStream >> SN;

//         component* newIcon = new component(this, myGridRef, SN);
//         newIcon->setPixmap(newIcon->getThumbnail());
//         newIcon->move(event->position().toPoint());
//         newIcon->show();
//         newIcon->setAttribute(Qt::WA_DeleteOnClose);

//         event->acceptProposedAction();
//     } else {
//         event->ignore();
//     }

// }

//! [1]
void gridEditWindow::mousePressEvent(QMouseEvent *event)
{

    component *child = static_cast<component*>(childAt(event->position().toPoint()));
    if (!child)
        return;

    QPixmap pixmap = child->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    int SN = child->getSN();
    dataStream << pixmap << QPoint(event->position().toPoint() - child->pos()) << SN;
    //! [1]

    //! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("compInternalSelect", itemData);
    //! [2]

    //! [3]
    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->position().toPoint() - child->pos());
    //! [3]

    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();

    child->setPixmap(tempPixmap);

    if (drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction) {
        qDebug() << "Executed move action";
        child->close();
    } else {
        child->show();
        child->setPixmap(pixmap);
    }
}


void gridEditWindow::setGridRef(Grid* myGridRef_inpt){
    myGridRef = myGridRef_inpt;
    return;
}


void gridEditWindow::setNetCompView(componentsListViewer* networkComponentsList_inpt){
    networkComponentsList = networkComponentsList_inpt;
}
