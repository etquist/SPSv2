#include "dbmanager.h"

dbManager::dbManager(){
    dbName = "unPathed";
    connectionName = "unNamed";
}

dbManager::dbManager(const QString& path, QString dbNameInpt) {
    dbName = path;
    connectionName = dbNameInpt;

    my_db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    my_db.setDatabaseName(path);

    if (openDB()){
        // Unsuccessful opening
        return;
    }

    QStringList currentTables = my_db.tables();
    if (!currentTables.contains("main")){
        // The database does not have a main table
        createNewMainTable();
    }


}

dbManager::~dbManager(){
    my_db.close();
}

// Returns a lsit of the format <String Name, String Type, int uniqueID>
std::vector<QList<QVariant>> dbManager::getAllEntries_basicData(){
    // Check if the databse is open and valid
    my_db.open();
    if(!my_db.isOpen()){
        qDebug() << "Hey, I'm not open!" << Qt::endl;
    }

    if(!my_db.isValid()){
        qDebug() << "Hey, I'm not valid!" << Qt::endl;
    }
    qDebug() << my_db.tables();

    // For each of the entries, retrieve the name, type, and ID of the element
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



// Creates an empty main table with all the required headers
// Returns 0 if successful
bool dbManager::createNewMainTable(){
    if(!my_db.isOpen()){
        qDebug() << "Hey, I'm not open!" << Qt::endl;
    }

    if(!my_db.isValid()){
        qDebug() << "Hey, I'm not valid!" << Qt::endl;
    }
    qDebug() << my_db.tables();

    std::vector<QList<QVariant>> entries;
    if (my_db.isOpen()) {


        // Create the main table. This code may need to be edited as columns change.
        QSqlQuery query(my_db);
        query.exec("CREATE TABLE main ("
                   "UniqueID INTEGER PRIMARY KEY AUTOINCREMENT,"
                   "Name TEXT NOT NULL,"
                   "Type TEXT NOT NULL,"
                   "Power_TypeA INTEGER,"
                   "Power_TypeB INTEGER,"
                   "Num_PhasesA INTEGER,"
                   "Num_PhasesB INTEGER,"
                   "PhaseA INTEGER,"
                   "PhaseB INTEGER,"
                   "PhaseC INTEGER,"
                   "V_A REAL,"
                   "V_B REAL,"
                   "MCR REAL,"
                   "Droop_Slope REAL,"
                   "Nom_Frequency REAL,"
                   "Conduit_Diameter REAL,"
                   "Conduit_Length REAL,"
                   "Conduit_Conductivity REAL,"
                   "transformer_3pTypeA INTEGER,"
                   "transformer_3pTypeB INTEGER,"
                   "Resistance REAL,"
                   "Capacitance REAL,"
                   "Inductance REAL,"
                   "Transformer_windingRatio REAL,"
                   "Num_Breakers INTEGER"
                   ")");
        // End potential edit region
        return 0;
    }
    return 1;
}


// Changes the filename to the requested name by the user
// Returns 0 if successful
bool dbManager::changeDBName(QString newName){
    if (isInDirectory(extractFilePath(dbName), newName)){
        return 1;
    }

    QString oldConnectionName = connectionName;   // original file name
    QString newConnectionName = newName;          // new file name

    QString oldDBName = dbName;   // original filepath
    QString temp = extractFilePath(oldDBName) + "/" + newConnectionName + ".db";
    QString newDBName = temp;

    // Close the existing database if it's open
    if (my_db.isOpen()){
        my_db.close();
    }

    // Attempt to rename the file
    try {
        std::filesystem::path oldPath = oldDBName.toStdString();
        QFile old(oldPath);
        if (old.rename(newConnectionName)){
            qDebug() << "Successful Renaming";
        } else{
            qDebug() << " Renaming Unsuccessful. The new filename already exists.";
        }
    } catch (const std::exception& e) {
        qDebug() << "Exception caught while trying to rename the dabase (" << connectionName << ") to (" << newConnectionName << ").";
        return 1;
    }

    // Change the dbManager variables holding the names
    dbName = newDBName;
    connectionName = newConnectionName;

    //Reset the database connection
    my_db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
    my_db.setDatabaseName(dbName);

    // Attempt to open the new connection
    if (openDB()){
        // Unsuccessful opening
        return 1;
    }


    return 0;
}


// Returns 0 if successful
bool dbManager::openDB(){
    // Open the database and check if it successfully opened
    if (!my_db.open()){
        // The database didn't properly open
        qDebug() <<  "Database failed to open";
        return 1;
    }
    else{
        // The database opened just fine
        qDebug() <<  "Database opened successfully";
        qDebug() << my_db.connectionName();
        qDebug() << my_db.databaseName();
        return 0;
    }

}


QString dbManager::getDBPath(){
    return dbName;
}


QString dbManager::getConnectionName(){
    return connectionName;
}


void dbManager::setEntryName(int uniqueID, QString name){
    // Check if the databse is open and valid
    my_db.open();
    if(!my_db.isOpen()){
        qDebug() << "Hey, I'm not open!" << Qt::endl;
    }

    // Update the database
    QSqlQuery query(my_db);
    QString uniqueID_str = QString::number(uniqueID);
    // Prepare the query with placeholders
    query.prepare("UPDATE main SET Name = :name WHERE UniqueID = :uniqueID");

    // Bind values to placeholders
    query.bindValue(":name", name);
    query.bindValue(":uniqueID", uniqueID_str);

    query.exec();

    return;
}

// Returns the uniqueID if successful. Return -1 if unsuccessful
int dbManager::newEntry(QString nameInpt, QString typeInpt){
    my_db.open();
    if(!my_db.isOpen()){
        qDebug() << "Hey, I'm not open!" << Qt::endl;
    }

    QSqlQuery query(my_db);
    // Prepare the query with placeholders
    query.prepare("INSERT INTO main (Name, Type) VALUES (:name, :type)");

    // Bind values to placeholders
    query.bindValue(":name", nameInpt);
    query.bindValue(":type", typeInpt);

    if(!query.exec()){
        qDebug() << "Error executing query 1:" << query.lastError().text();
    }

    QSqlQuery query2("SELECT UniqueID FROM main ORDER BY UniqueID DESC LIMIT 1", my_db);
    if (!query2.exec()) {
        qDebug() << "Error executing query 2:" << query2.lastError().text();
    } else {
        int uniqueID_id = query2.record().indexOf("UniqueID");

        while(query2.next()){
            int uniqueID = query2.value(uniqueID_id).toInt();
            return uniqueID;
        }
    }
    return -1;

}


// Returns true if successfully deleted.
bool dbManager::deleteEntry(int uniqueID){
    my_db.open();
    if(!my_db.isOpen()){
        qDebug() << "Hey, I'm not open!" << Qt::endl;
    }

    QSqlQuery deleteQuery(my_db);
    deleteQuery.prepare("DELETE FROM main WHERE UniqueID = ?");
    deleteQuery.addBindValue(uniqueID);

    if (!deleteQuery.exec()) {
        qDebug() << "Error deleting entry:" << deleteQuery.lastError().text();
        return false;
    } else {
        qDebug() << "Entry with UniqueID" << uniqueID << "deleted successfully.";
        return true;
    }
}

// Returns -1 if not found, returns UniqueId if it is found
int dbManager::queryEntry(QString nameQuery){
    my_db.open();
    if(!my_db.isOpen()){
        qDebug() << "Hey, I'm not open!" << Qt::endl;
    }

    if (my_db.isOpen()) {
        QSqlQuery query("SELECT Name, UniqueID FROM main", my_db);
        if (!query.exec()) {
            qDebug() << "Error executing query:" << query.lastError().text();
        } else {
            int name_id = query.record().indexOf("Name");
            int type_id = query.record().indexOf("Type");
            int uniqueID_id = query.record().indexOf("UniqueID");

            while(query.next()){
                QString name = query.value(name_id).toString();
                int uniqueID = query.value(uniqueID_id).toInt();
                if (name == nameQuery){
                    return uniqueID; // If found, return the ID
                }
            }
        }
    }
    return -1;  // If not found, return -1
}
