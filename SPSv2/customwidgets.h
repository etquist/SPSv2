#ifndef CUSTOMWIDGETS_H
#define CUSTOMWIDGETS_H


#include <QGraphicsView>
#include <QListView>
#include <QListWidget>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>


class customWidgets
{
public:
    customWidgets();
};


class customGraphicsInterface : public QGraphicsView
{
    Q_OBJECT

signals:
    void itemDrop(QString);

public:
    explicit customGraphicsInterface(QWidget *widget = nullptr);

protected:
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;

    using QGraphicsView::QGraphicsView;
};

#endif // CUSTOMWIDGETS_H
