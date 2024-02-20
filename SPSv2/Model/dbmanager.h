#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QSqlQuery>
#include <filesystem>
#include "helperFunctions.h"

class dbManager
{
public:
    dbManager();
    dbManager(const QString& path, QString dbNameInpt);
    ~dbManager();

    // returns all of the entries in the database (typically used for catalog initialization)
    std::vector<QList<QVariant>> getAllEntries_basicData();

    // Creates an empty maint table with all the required headers
    bool createNewMainTable();

    // Attempts to change the database name. Returns 1 if unsuccessful
    bool changeDBName(QString newName);

    // Change the name assocated with uniqueID in the table
    void setEntryName(int uniqueID, QString name);

    // Returns the uniqueID of the new entry
    int newEntry(QString nameInpt, QString typeInpt);

    // Returns true if successfully deleted.
    bool deleteEntry(int uniqueID);

    // Returns -1 if an entry with the queried name exists
    int queryEntry(QString nameQuery);

    QString getDBPath();
    QString getConnectionName();
private:
    QSqlDatabase my_db;
    QString dbName; // Assigned as the file path during creation
    QString connectionName; // Assigned as the filename



    bool openDB();
};

#endif // DBMANAGER_H
