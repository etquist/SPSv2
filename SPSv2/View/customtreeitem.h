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
    void setLabel(bool labelVal);
    bool checkLabel();

    // This operator is used for serializing the node pointer, and can therefore be used
    //      to pass information between the component tree and the network editor
    friend QDataStream &operator<<(QDataStream &out, customTreeItem ptr);
    friend QDataStream &operator>>(QDataStream &in, customTreeItem ptr);


private:
    QList<customTreeItem*> childItems;
    QList<QVariant> itemData;   //[name, type]
    customTreeItem* parentItem;
    gridNode* refNode;
    bool label = true;
};

#endif // customTreeItem_H
