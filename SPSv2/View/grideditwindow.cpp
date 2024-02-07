#include "grideditwindow.h"
#include <QtWidgets>


gridEditWindow::gridEditWindow(QWidget *parent) : QFrame(parent){
    setAcceptDrops(true);
}

void gridEditWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void gridEditWindow::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void gridEditWindow::dropEvent(QDropEvent *event)
{

    // if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
    //     QByteArray itemData = event->mimeData()->data("application/x-dnditemdata");
    //     QDataStream dataStream(&itemData, QIODevice::ReadOnly);

    //     QPixmap pixmap;
    //     QPoint offset;
    //     dataStream >> pixmap >> offset;

    //     QLabel *newIcon = new QLabel(this);
    //     newIcon->setPixmap(pixmap);
    //     newIcon->move(event->position().toPoint() - offset);
    //     newIcon->show();
    //     newIcon->setAttribute(Qt::WA_DeleteOnClose);

    //     if (event->source() == this) {
    //         event->setDropAction(Qt::MoveAction);
    //         event->accept();
    //     } else {
    //         event->acceptProposedAction();
    //     }
    // } else {
    //     event->ignore();
    // }
}

//! [1]
void gridEditWindow::mousePressEvent(QMouseEvent *event)
{
    //customNodeTree* sourceTree =  event->;

    QLabel *child = static_cast<QLabel*>(childAt(event->position().toPoint()));
    if (!child)
        return;

    QPixmap pixmap = child->pixmap();

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream << pixmap << QPoint(event->position().toPoint() - child->pos());
    //! [1]

    //! [2]
    QMimeData *mimeData = new QMimeData;
    mimeData->setData("application/x-dnditemdata", itemData);
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
        child->close();
    } else {
        child->show();
        child->setPixmap(pixmap);
    }
}
