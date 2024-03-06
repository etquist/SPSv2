#include <QApplication>
#include <QStandardItemModel>
#include <QTreeView>
#include <QStandardItem>
#include <QDrag>
#include <QMimeData>
#include <QMouseEvent>
#include <QMimeData>
#include "customNodeTree.h"
#include <QStyledItemDelegate>

#ifndef COMPONENTSLISTVIEWER_H
#define COMPONENTSLISTVIEWER_H

#include <QObject>
#include <QTreeView>

class componentsListViewer : public QTreeView
{
    Q_OBJECT
public:
    componentsListViewer();
    componentsListViewer(QWidget* parent = nullptr);


protected:
    void mousePressEvent(QMouseEvent* event) override;

    void startDrag(Qt::DropActions supportedActions) override;


private:
    QPoint startPos;
    // customNodeTree* model;
};

#endif // COMPONENTSLISTVIEWER_H
