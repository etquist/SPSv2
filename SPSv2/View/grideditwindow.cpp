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
        dataStream >> SN;

        // check if this already exists in the edit window
        if (SN_list.find(SN) != SN_list.end()){
            // The node has already been placed
            event->ignore();
            return;
        } else{
            // If it hasn't been placed, add it to the list and carry on.
            SN_list.insert(SN);
        }

        component* newIcon = new component(this, myGridRef, SN);
        newIcon->setPixmap(newIcon->getThumbnail());

        QPoint offset;  // offset point based on the size of the pixmap
        offset.setX(newIcon->pixmap().size().width() / 2);
        offset.setY(newIcon->pixmap().size().height() / 2);


        newIcon->move(event->position().toPoint() - offset);
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
