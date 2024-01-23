#ifndef customTreeItem_H
#define customTreeItem_H

#include <QList>
#include <QVariant>
#include "gridnode.h"



class customTreeItem {

public:
    customTreeItem(const QList<QVariant> &data, customTreeItem* parent = nullptr);
    ~customTreeItem();

    customTreeItem *child(int number);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    bool insertChildren(int position, int count, int columns);
    bool insertColumns(int position, int columns);
    customTreeItem *parent();
    bool removeChildren(int position, int count);
    bool removeColumns(int position, int columns);
    int childNumber() const;
    bool setData(int column, const QVariant &value);

    gridNode* returnRefNode();
    void setRefNode(gridNode* newNode);

private:
    QList<customTreeItem*> childItems;
    QList<QVariant> itemData;   //[name, gridNode*]
    customTreeItem* parentItem;
    gridNode* refNode;
};

#endif // customTreeItem_H
