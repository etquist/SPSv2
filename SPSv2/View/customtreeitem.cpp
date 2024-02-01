#include "customTreeItem.h"

// Constructor Definition. data consists of [name, gridNode*]
customTreeItem::customTreeItem(const QList<QVariant> &data, customTreeItem* parent) {
    itemData = data;
    parentItem = parent;
}


// Destructor. Delete all the children
customTreeItem::~customTreeItem(){
    qDeleteAll(childItems);
}

// Get the specified child if it's a valid index
customTreeItem* customTreeItem::child(int number){
    if (number < 0 || number >= childItems.size())
        return nullptr;
    return childItems.at(number);
}


// // Serializer for mime Data
// QDataStream& operator<<(QDataStream &out, customTreeItem* item){
//     gridNode* nodeRef = item->returnRefNode();
//     out << nodeRef; // just send the pointer
//     return out;
// }

// QDataStream& operator>>(QDataStream &in, customTreeItem* item){
//     gridNode* nodeRef;
//     in >> nodeRef; // just send the pointer
//     item->setRefNode(nodeRef);
//     return in;
// }

// Count the number of children that this node has
int customTreeItem::childCount() const
{
    return childItems.count();
}

// Get the index of the referenced child
int customTreeItem::childNumber() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<customTreeItem*>(this));
    return 0;
}

// The number of columns of data
int customTreeItem::columnCount() const{
    return itemData.count();
}

// Get the data element of the specified column number, for the selected item
QVariant customTreeItem::data(int column) const {
    if (column < 0 || column >= itemData.size())
        return QVariant();
    return itemData.at(column);
}

// Add [count] new child at the specified location
bool customTreeItem::insertChildren(int position, int count, int columns)
{
    if (position < 0 || position > childItems.size())
        return false;

    for (int row = 0; row < count; ++row) {
        QList<QVariant> data(columns);
        customTreeItem *item = new customTreeItem(data, this);
        childItems.insert(position, item);
    }

    return true;
}

// Add new columns into the itemData container
bool customTreeItem::insertColumns(int position, int columns)
{
    if (position < 0 || position > itemData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        itemData.insert(position, QVariant());

    for (customTreeItem *child : std::as_const(childItems))
        child->insertColumns(position, columns);

    return true;
}

// Return the parent of the selected item
customTreeItem* customTreeItem::parent(){
    return parentItem;
}

// Delete the first selected number of children
bool customTreeItem::removeChildren(int position, int count)
{
    if (position < 0 || position + count > childItems.size())
        return false;

    for (int row = 0; row < count; ++row)
        delete childItems.takeAt(position);

    return true;
}

// remvoe columns from the data container
bool customTreeItem::removeColumns(int position, int columns)
{
    if (position < 0 || position + columns > itemData.size())
        return false;

    for (int column = 0; column < columns; ++column)
        itemData.remove(position);

    for (customTreeItem *child : std::as_const(childItems))
        child->removeColumns(position, columns);

    return true;
}

// Change the value of a data point within the selected item
bool customTreeItem::setData(int column, const QVariant &value)
{
    if (column < 0 || column >= itemData.size())
        return false;

    itemData[column] = value;
    return true;
}

// Returns the pointer to the contained grid node
gridNode* customTreeItem::returnRefNode(){
    return refNode;
}

void customTreeItem::setRefNode(gridNode* newNode){
    refNode = newNode;
    return;
}

void customTreeItem::setLabel(bool labelVal){
    label = labelVal;
}


bool customTreeItem::checkLabel(){
    return label;
}


