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
#include "customnodetree.h"

QString customQuestionBox(QString boxTitle, QString boxText, QString boxInformativeText, std::vector<QString> choices);
int checkNumComponentInstances(QString searchString, customNodeTree* tree, int colIdx, Qt::CaseSensitivity caseSensitivity = Qt::CaseSensitive);

#endif // HELPERFUNCTIONS_H
