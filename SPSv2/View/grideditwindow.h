#ifndef GRIDEDITWINDOW_H
#define GRIDEDITWINDOW_H

#include <QFrame>
#include <grid.h>
#include <component.h>
#include <set>
#include <QStyledItemDelegate>



class gridEditWindow : public QFrame
{
public:
    explicit gridEditWindow(QWidget *parent = nullptr);

    void setGridRef(Grid* myGridRef);

signals:


protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;



private:
    Grid* myGridRef;
    std::set<int> SN_list;

};

#endif // GRIDEDITWINDOW_H
