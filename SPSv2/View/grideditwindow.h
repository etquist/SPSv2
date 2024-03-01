#ifndef GRIDEDITWINDOW_H
#define GRIDEDITWINDOW_H

#include <QFrame>
#include <grid.h>
#include <component.h>
#include <set>
#include <QStyledItemDelegate>
#include <componentsListViewer.h>



class gridEditWindow : public QFrame
{
public:
    explicit gridEditWindow(QWidget *parent = nullptr);

    void setGridRef(Grid* myGridRef);
    void setNetCompView(componentsListViewer* networkComponentsList_inpt);

signals:


protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;



private:
    Grid* myGridRef;
    std::set<int> SN_list;
    componentsListViewer* networkComponentsList;

};

#endif // GRIDEDITWINDOW_H
