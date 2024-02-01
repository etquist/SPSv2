#include "customNodeTree.h"

customNodeTree::customNodeTree(const QStringList &headers, QObject *parent)
    : QAbstractItemModel(parent)
{
    QList<QVariant> rootData;
    for (const QString &header : headers){
        rootData << header;
    }
    rootItem = new customTreeItem(rootData);
    externalDragEnabled = false;
}


customNodeTree::~customNodeTree()
{
    delete rootItem;
}


int customNodeTree::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return rootItem->columnCount();
}


QVariant customNodeTree::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole && role != Qt::EditRole)
        return QVariant();

    customTreeItem *item = getItem(index);

    return item->data(index.column());
}

gridNode* customNodeTree::getNodePtr(const QModelIndex &index){
    if (!index.isValid())
        return nullptr;

    customTreeItem *item = getItem(index);

    return item->returnRefNode();
}

void customNodeTree::setNodeData(const QModelIndex &index, gridNode* node){
    if (!index.isValid())
        return;

    customTreeItem *item = getItem(index);

    item->setRefNode(node);
    return;
}


Qt::ItemFlags customNodeTree::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable | QAbstractItemModel::flags(index);
}



customTreeItem *customNodeTree::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
        customTreeItem *item = static_cast<customTreeItem*>(index.internalPointer());
        if (item)
            return item;
    }
    return rootItem;
}



QVariant customNodeTree::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}


QModelIndex customNodeTree::index(int row, int column, const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() != 0)
        return QModelIndex();

    customTreeItem *parentItem = getItem(parent);
    if (!parentItem)
        return QModelIndex();

    customTreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    return QModelIndex();
}


bool customNodeTree::insertColumns(int position, int columns, const QModelIndex &parent)
{
    beginInsertColumns(parent, position, position + columns - 1);
    const bool success = rootItem->insertColumns(position, columns);
    endInsertColumns();

    return success;
}

bool customNodeTree::insertRows(int position, int rows, const QModelIndex &parent)
{
    customTreeItem *parentItem = getItem(parent);
    if (!parentItem)
        return false;

    beginInsertRows(parent, position, position + rows - 1);
    const bool success = parentItem->insertChildren(position,
                                                    rows,
                                                    rootItem->columnCount());
    endInsertRows();

    return success;
}


QModelIndex customNodeTree::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    customTreeItem *childItem = getItem(index);
    customTreeItem *parentItem = childItem ? childItem->parent() : nullptr;

    if (parentItem == rootItem || !parentItem)
        return QModelIndex();

    return createIndex(parentItem->childNumber(), 0, parentItem);
}


bool customNodeTree::removeColumns(int position, int columns, const QModelIndex &parent)
{
    beginRemoveColumns(parent, position, position + columns - 1);
    const bool success = rootItem->removeColumns(position, columns);
    endRemoveColumns();

    if (rootItem->columnCount() == 0)
        removeRows(0, rowCount());

    return success;
}


bool customNodeTree::removeRows(int position, int rows, const QModelIndex &parent)
{
    customTreeItem *parentItem = getItem(parent);
    if (!parentItem)
        return false;

    beginRemoveRows(parent, position, position + rows - 1);
    const bool success = parentItem->removeChildren(position, rows);
    endRemoveRows();

    return success;
}


int customNodeTree::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid() && parent.column() > 0)
        return 0;

    const customTreeItem *parentItem = getItem(parent);

    return parentItem ? parentItem->childCount() : 0;
}


bool customNodeTree::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Qt::EditRole)
        return false;

    customTreeItem *item = getItem(index);
    bool result = item->setData(index.column(), value);

    if (result)
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

    return result;
}


bool customNodeTree::setHeaderData(int section, Qt::Orientation orientation,
                              const QVariant &value, int role)
{
    if (role != Qt::EditRole || orientation != Qt::Horizontal)
        return false;

    const bool result = rootItem->setData(section, value);

    if (result)
        emit headerDataChanged(orientation, section, section);

    return result;
}

bool customNodeTree::setFullData(const QModelIndex &index, const QList<QVariant> &data, int role){

    if (role != Qt::EditRole)
        return false;

    customTreeItem *item = getItem(index);
    bool result;
    for(size_t i = 0; i < data.size(); i++){
        result = item->setData(i, data.at(i));
        if (!result){
            break;
        }
    }
    bool label = false;
    item->setLabel(label);  // This is an actual catalog entry

    if (result)
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

    return result;
}

QMimeData* customNodeTree::mimeData(const QModelIndex &index) const {
    QMimeData* mimeData = new QMimeData();
    QByteArray encodedData;
    QDataStream dataStream(&encodedData, QIODevice::WriteOnly);
    //encodedData << getItem(index)->returnRefNode();

    mimeData->setData("componentList_networkEditor_type", encodedData);;
    return mimeData;
}

bool customNodeTree::setCatalogLabel(const QModelIndex &index, QString labelName, int role){
    if (role != Qt::EditRole)
        return false;

    customTreeItem *item = getItem(index);
    bool result = item->setData(0, labelName);

    bool label = true;
    item->setLabel(label);  // This is a just a header in the catalog. no associated

    if (result)
        emit dataChanged(index, index, {Qt::DisplayRole, Qt::EditRole});

    return result;

}

// Check if the row at the specified index is a label
bool customNodeTree::checkLabel(const QModelIndex &index){

    customTreeItem *item = getItem(index);
    if (!item){ return false; }
    return item->checkLabel();
}

// Returns the root item. That is all. Thank you for stopping by.
customTreeItem* customNodeTree::getRoot(){
    return rootItem;
}


// Returns true if the passed index is the root node
bool customNodeTree::isRoot(const QModelIndex &index){
    const customTreeItem *item = getItem(index);

    if (item == rootItem){
        return true;
    } else{
        return false;
    }
}

void customNodeTree::setExtDrag(bool draggable){
    externalDragEnabled = draggable;
}


bool customNodeTree::checkExtDrag(){
    return externalDragEnabled;
}


// This is residual from the example implementation. May be later useful for initializing from a saved datafile, however.
void customNodeTree::setupModelData(const QStringList &lines, customTreeItem *parent)
{
    QList<customTreeItem *> parents;
    QList<int> indentations;
    parents << parent;
    indentations << 0;

    int number = 0;

    while (number < lines.count()) {
        int position = 0;
        while (position < lines[number].length()) {
            if (lines[number].at(position) != ' ')
                break;
            ++position;
        }

        const QString lineData = lines[number].mid(position).trimmed();

        if (!lineData.isEmpty()) {
            // Read the column data from the rest of the line.
            const QStringList columnStrings =
                lineData.split(QLatin1Char('\t'), Qt::SkipEmptyParts);
            QList<QVariant> columnData;
            columnData.reserve(columnStrings.size());
            for (const QString &columnString : columnStrings)
                columnData << columnString;

            if (position > indentations.last()) {
                // The last child of the current parent is now the new parent
                // unless the current parent has no children.

                if (parents.last()->childCount() > 0) {
                    parents << parents.last()->child(parents.last()->childCount()-1);
                    indentations << position;
                }
            } else {
                while (position < indentations.last() && parents.count() > 0) {
                    parents.pop_back();
                    indentations.pop_back();
                }
            }

            // Append a new item to the current parent's list of children.
            customTreeItem *parent = parents.last();
            parent->insertChildren(parent->childCount(), 1, rootItem->columnCount());
            for (int column = 0; column < columnData.size(); ++column)
                parent->child(parent->childCount() - 1)->setData(column, columnData[column]);
        }
        ++number;
    }
}

