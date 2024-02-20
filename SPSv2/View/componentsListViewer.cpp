#include "componentsListViewer.h"

componentsListViewer::componentsListViewer() {}

componentsListViewer::componentsListViewer(QWidget* parent) : QTreeView(parent) {
    setDragEnabled(true);
    setDragDropMode(QAbstractItemView::DragOnly);
    setSelectionMode(QAbstractItemView::SingleSelection);

}


void componentsListViewer::mousePressEvent(QMouseEvent* event) {
    /*
        To do:
            - This mousePressEvent needs to be implemented properly for all types of clicks now. (drag, single click, etc.)
    */


    if (event->button() == Qt::LeftButton) {
        QPoint dragStartPosition = event->pos();
        Qt::DropActions supportedActions = model()->supportedDropActions();

        startDrag(supportedActions);
    }
    QTreeView::mousePressEvent(event);
}

void componentsListViewer::startDrag(Qt::DropActions supportedActions) {
    const QModelIndex index = currentIndex();


    if (!index.isValid()) {
        return;
    }

    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);

    // Swap the index to the column which contains the serial number
    const QModelIndex SN_index = model()->index(index.row(), 2, index.parent());

    dataStream << model()->data(SN_index).toInt();
    qDebug() << "SN: " << model()->data(SN_index).toInt();

    QMimeData *mimeData = new QMimeData;
    mimeData->setData("compExport", itemData);

    QDrag* drag = new QDrag(this);
    drag->setMimeData(mimeData);

    Qt::DropAction action = drag->exec(supportedActions, Qt::CopyAction);
    if (action == Qt::CopyAction){
        qDebug() << "Successful Copy";
    }


}
