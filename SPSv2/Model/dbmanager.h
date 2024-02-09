#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QSqlDatabase>
#include <QtSql>
#include <QDebug>
#include <QSqlQuery>

class dbManager
{
public:
    dbManager(const QString& path, QString dbNameInpt);
    ~dbManager();

    // returns all of the entries in the database (typically used for catalog initialization)
    std::vector<QList<QVariant>> getAllEntries_basicData();

private:
    QSqlDatabase my_db;
    QString dbName;
    QString connectionName;

};

#endif // DBMANAGER_H
