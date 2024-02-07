#ifndef GRIDEDITWINDOW_H
#define GRIDEDITWINDOW_H

#include <QFrame>
#include "customnodetree.h"



class gridEditWindow : public QFrame
{
public:
    explicit gridEditWindow(QWidget *parent = nullptr);

signals:


protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

};

#endif // GRIDEDITWINDOW_H
