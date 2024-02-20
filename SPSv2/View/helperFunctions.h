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
#include <QDirIterator>

// Creates a custom dialog box that's displayed to the user and allows for the selection from an array of user-input values
QString customQuestionBox(QString boxTitle, QString boxText, QString boxInformativeText, std::vector<QString> choices);

// Checks the number of instances of the name by "searchString", in the customNodeTree "tree"
int checkNumComponentInstances(QString searchString, customNodeTree* tree, int colIdx, Qt::CaseSensitivity caseSensitivity = Qt::CaseSensitive);

// Creates a dialog box which asks the user to provide a name. A defualt can be specified.
QString promptForText(QString defaultName = "Enter a New Name", QString msgPrompt = "Enter the new name.");



// Extracts the filename from a whole path
QString extractFileName(const QString& filePath);

// Extracts the file path, excluding the filename and ending in a slash, from a whole path
QString extractFilePath(const QString& filePath);

// Returns 1 if the filename query is in the specified directory
bool isInDirectory(const QString& path, const QString& filename);


#endif // HELPERFUNCTIONS_H
