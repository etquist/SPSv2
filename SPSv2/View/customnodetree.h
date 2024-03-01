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

    // returns the flags corresponding to the type of behavior that the model can accomodate
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    Qt::ItemFlags dropFlags(const QModelIndex &index) const;


    // Returns the types of mime data the model can export
    QStringList mimeTypes() const override;

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


    bool setFullData(QModelIndex &index, const QList<QVariant> &data, int role = Qt::EditRole);

    bool checkLabel(const QModelIndex &index);

    // Returns the data in column 1 or 0
    QString getType(const QModelIndex &index);  // Col 1
    QString getName(const QModelIndex &index);  // Col 0

    // Returns the root item for the tree. For initialization
    customTreeItem* getRoot();
    bool isRoot(const QModelIndex &index);

    // Get and set the unique ID
    int getUniqueID(const QModelIndex &index);
    void setUniqueID(QModelIndex &index, int inputID);

    // Get and set the database Name
    QString get_dbName(const QModelIndex &index);
    void set_dbName(QModelIndex &index, QString inputName);

    // Get and set this node's status as catalog or components list
    bool checkCatalog(const QModelIndex &index);
    void setCatalog(QModelIndex &index, bool setVal);

    // Setter and getter functions for database name and ID
    void setExtDrag(bool draggable);
    bool checkExtDrag();

    // These two are viable only for components list items (catalog == false)
    int getSN(const QModelIndex &index) const;
    void setSN(QModelIndex &index, int newSN);


    // Find the child ("Name") within the database (index) specified
    // Note. If two entries exist with the same name, this will only return the first one.
    QModelIndex findChildInDB(QString queryName, QModelIndex indexInpt);
    QMimeData* mimeData(const QModelIndex &index) const;

    QModelIndex getRootIndex();

private:
    void setupModelData(const QStringList &lines, customTreeItem *parent);
    customTreeItem *getItem(const QModelIndex &index) const;

    customTreeItem *rootItem;
    bool externalDragEnabled;



protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // customNodeTree_H
