#ifndef customNodeTree_H
#define customNodeTree_H

#include <QObject>
#include <QAbstractItemModel>
#include <QString>
#include "customtreeitem.h"
#include "gridnode.h"
#include <QMimeData>
#include <QIODevice>
#include <QDragMoveEvent>


// Note, this implementation is the same as the editable tree model example file from QT.
// Documentation can be found there.


class customNodeTree : public QAbstractItemModel {
    Q_OBJECT



public:

    customNodeTree(const QStringList &headers, QObject *parent = nullptr);
    ~customNodeTree();

    QVariant data(const QModelIndex &index, int role) const override;
    gridNode* getNodePtr(const QModelIndex &index);
    void setNodeData(const QModelIndex &index, gridNode* node);
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;


    Qt::ItemFlags flags(const QModelIndex &index) const override;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;
    bool setHeaderData(int section, Qt::Orientation orientation,
                       const QVariant &value, int role = Qt::EditRole) override;

    bool insertColumns(int position, int columns,
                       const QModelIndex &parent = QModelIndex()) override;
    bool removeColumns(int position, int columns,
                       const QModelIndex &parent = QModelIndex()) override;
    bool insertRows(int position, int rows,
                    const QModelIndex &parent = QModelIndex()) override;
    bool removeRows(int position, int rows,
                    const QModelIndex &parent = QModelIndex()) override;

    // This custom function makes a new header for entries to be grouped under
    bool setCatalogLabel(const QModelIndex &index, QString labelName, int role);


    bool setFullData(const QModelIndex &index, const QList<QVariant> &data, int role = Qt::EditRole);

    bool checkLabel(const QModelIndex &index);

    // Returns the root item for the tree. For initialization
    customTreeItem* getRoot();
    bool isRoot(const QModelIndex &index);

    // Setter and getter functions for checking dragability
    void setExtDrag(bool draggable);
    bool checkExtDrag();

private:
    void setupModelData(const QStringList &lines, customTreeItem *parent);
    customTreeItem *getItem(const QModelIndex &index) const;

    customTreeItem *rootItem;
    bool externalDragEnabled;

    QMimeData* mimeData(const QModelIndex &index) const;
};

#endif // customNodeTree_H
