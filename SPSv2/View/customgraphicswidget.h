#ifndef CUSTOMGRAPHICSWIDGET_H
#define CUSTOMGRAPHICSWIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QListView>
#include <QListWidget>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>

class customGraphicsWidget : public QGraphicsView
{
Q_OBJECT

signals:
    void itemDrop(QString, QPointF);

public:
    explicit customGraphicsWidget(QWidget *widget = nullptr);

protected:
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;

    using QGraphicsView::QGraphicsView;
};

#endif // CUSTOMGRAPHICSWIDGET_H
