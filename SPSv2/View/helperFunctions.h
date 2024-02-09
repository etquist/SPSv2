#ifndef HELPERFUNCTIONS_H
#define HELPERFUNCTIONS_H

#include <QMessageBox>
#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>
#include <QInputDialog>
#include "customnodetree.h"
#include <QFileInfo>


// Creates a custom dialog box that's displayed to the user and allows for the selection from an array of user-input values
QString customQuestionBox(QString boxTitle, QString boxText, QString boxInformativeText, std::vector<QString> choices);

// Checks the number of instances of the name by "searchString", in the customNodeTree "tree"
int checkNumComponentInstances(QString searchString, customNodeTree* tree, int colIdx, Qt::CaseSensitivity caseSensitivity = Qt::CaseSensitive);

// Creates a dialog box which asks the user to provide a name. A defualt can be specified.
QString promptForNewName(QString defaultName = "Enter a New Name");


// Extracts the filename from a whole path
QString extractFileName(const QString& filePath);



#endif // HELPERFUNCTIONS_H
