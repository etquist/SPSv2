#include "helperFunctions.h"


// Custom message box that gives users buttons to select
// Handles up to 7 inputs, returns the selected option string
QString customQuestionBox(QString boxTitle, QString boxText, QString boxInformativeText, std::vector<QString> choices){
    QMessageBox msgBox;
    msgBox.setWindowTitle(boxTitle);
    msgBox.setText(boxText);
    msgBox.setInformativeText(boxInformativeText);
    for(std::size_t i = 0; i < choices.size(); i++){
        if(i == 0){
            msgBox.addButton(choices[i], QMessageBox::AcceptRole);
        } else if (i == 1){
            msgBox.addButton(choices[i], QMessageBox::RejectRole);
        } else if (i == 2){
            msgBox.addButton(choices[i], QMessageBox::DestructiveRole);
        } else if (i == 3){
            msgBox.addButton(choices[i], QMessageBox::ActionRole);
        } else if (i == 4){
            msgBox.addButton(choices[i], QMessageBox::HelpRole);
        } else if (i == 5){
            msgBox.addButton(choices[i], QMessageBox::YesRole);
        } else if (i == 6){
            msgBox.addButton(choices[i], QMessageBox::NoRole);
        }

    }

    int ret = msgBox.exec();
    return choices[ret];
}

// Searches the referenced tree for all components that starts with the name
// "catalogName"
int checkNumComponentInstances(QString searchString, customNodeTree* tree, int colIdx, Qt::CaseSensitivity caseSensitivity){
    int numMatches = 0;

    for (size_t row = 0; row < tree->rowCount(); row++) {
        QModelIndex index = tree->index(row, colIdx);
        QVariant data = tree->data(index, Qt::DisplayRole);

        if (data.toString().contains(searchString, caseSensitivity)) {
            numMatches += 1;
        }
    }

    return numMatches;
}
