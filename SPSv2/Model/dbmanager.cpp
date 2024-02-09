#include "dbmanager.h"

dbManager::dbManager(const QString& path, QString dbNameInpt) {
    dbName = path;
    connectionName = dbNameInpt;

    my_db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    my_db.setDatabaseName(path);

    // Open the database and check if it successfully opened
    if (!my_db.open()){
        // The database didn't properly open
        qDebug() <<  "Database failed to open";
    }
    else{
        // The database opened just fine
        qDebug() <<  "Database opened successfully";
        qDebug() << my_db.connectionName();
        qDebug() << my_db.databaseName();

    }


}

dbManager::~dbManager(){
    my_db.close();
}

// Returns a lsit of the format <String Name, String Type, int uniqueID>
std::vector<QList<QVariant>> dbManager::getAllEntries_basicData(){
    if(!my_db.isOpen()){
        qDebug() << "Hey, I'm not open!" << Qt::endl;
    }

    if(!my_db.isValid()){
        qDebug() << "Hey, I'm not valid!" << Qt::endl;
    }
    qDebug() << my_db.tables();

    std::vector<QList<QVariant>> entries;
    if (my_db.isOpen()) {
        QSqlQuery query("SELECT Name, Type, UniqueID FROM main", my_db);
        if (!query.exec()) {
            qDebug() << "Error executing query:" << query.lastError().text();
        } else {
            int name_id = query.record().indexOf("Name");
            int type_id = query.record().indexOf("Type");
            int uniqueID_id = query.record().indexOf("UniqueID");

            while(query.next()){
                QString name = query.value(name_id).toString();
                QString type = query.value(type_id).toString();
                int uniqueID = query.value(uniqueID_id).toInt();

                QList<QVariant> entry;
                entry << name << type << uniqueID;
                entries.push_back(entry);
            }
        }
    }
    return entries;
}
