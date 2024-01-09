#include "customgraphicswidget.h"

// This is a custom class to allow drag & drop interaction
//      with the graphics interface instance
customGraphicsWidget::customGraphicsWidget(QWidget *widget) : QGraphicsView(widget)
{
    setAcceptDrops(true);
}

void customGraphicsWidget::dropEvent(QDropEvent *event)
{
    if (event->source() == this) return;

    QListWidget *listwidget = qobject_cast<QListWidget*>(event->source());

    QString itemPath = listwidget->currentItem()->text();
    QPointF dropPosition = event->position();

    emit itemDrop(itemPath, dropPosition);
}

void customGraphicsWidget::dragEnterEvent(QDragEnterEvent *event)
{
    event->accept();
    event->acceptProposedAction();
}

void customGraphicsWidget::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void customGraphicsWidget::dragMoveEvent(QDragMoveEvent *event)
{
    event->accept();
    event->acceptProposedAction();
}
