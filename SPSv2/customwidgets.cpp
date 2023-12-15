#include "customwidgets.h"

customWidgets::customWidgets() {}


// This is a custom class to allow drag & drop interaction
//      with the graphics interface instance
customGraphicsInterface::customGraphicsInterface(QWidget *widget) : QGraphicsView(widget)
{
    setAcceptDrops(true);
}

void customGraphicsInterface::dropEvent(QDropEvent *event)
{
    if (event->source() == this) return;

    QListWidget *listwidget = qobject_cast<QListWidget*>(event->source());

    QString itemPath = listwidget->currentItem()->text();
    emit itemDrop(itemPath);
}

void customGraphicsInterface::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
    event->acceptProposedAction();
}

void customGraphicsInterface::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void customGraphicsInterface::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
    event->acceptProposedAction();
}
