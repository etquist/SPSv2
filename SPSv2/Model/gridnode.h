#ifndef GRIDNODE_H
#define GRIDNODE_H

#include <QObject>
#include <set>

// Highest level of class hierarchy that describes the components of a microgrid
class gridNode
{
public:
    gridNode();
    ~gridNode();
    gridNode(const gridNode &original);

    const QString& getType() const;
    void setType(QString  newType);

    const QString& getName() const;
    void setName(QString  newName);

    int getSN();
    void setSN(int newSN);

    int getUniqueID();
    void setUniqueID(int newUniqueID);

    bool validityCheck();

    void setCatalog(bool set);  // set the node as either a catalog entry (template) or a full-use node
    const bool& checkCatalog() const;        // Check if the node is a catalog

    double getBusVoltage(); // Returns -1 if not a bus

    void insertConnection(gridNode* newConnect);


private:
    int uniqueID;   //  Unique ID for the SQLite database
    int nodeSN;     // serial number of this node
    QString dbName;
    QString name;
    QString type;

    // This is a list of all the connected nodes to this one
    std::set<gridNode*> connections;

};




#endif // GRIDNODE_H
