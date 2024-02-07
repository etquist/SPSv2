#include "helperFunctions.h"


// Custom message box that gives users buttons to select
// Handles unlimited, returns the selected option string
QString customQuestionBox(QString boxTitle, QString boxText, QString boxInformativeText, std::vector<QString> choices){
    QString selection = "valid";
    QMessageBox msgBox;
    msgBox.setWindowTitle(boxTitle);
    msgBox.setText(boxText);
    msgBox.setInformativeText(boxInformativeText);
    for(std::size_t i = 0; i < choices.size(); i++){
        QPushButton* customButton1 = msgBox.addButton(choices[i], QMessageBox::AcceptRole);
        customButton1->setProperty("customRole", 0);
    }


    // Connect the rejected signal to a slot
    QObject::connect(&msgBox, &QMessageBox::rejected, [&]() {
        qDebug() << "User closed the message box using the close button (X). Handling close logic...";
        selection = "aborted_dlg_box";
    });

    int ret = msgBox.exec();

    if (selection == "aborted_dlg_box"){
        return "aborted_dlg_box";
    }

    qDebug() << "Valid selection: " << choices[ret];
    return choices[ret];
}

// Searches the referenced tree for all components that starts with the name
// "searchString"
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

QString promptForNewName(QString defaultName){
    QString defaultTxt = defaultName;
    QString prompt = "Enter the new name.";
    bool ok;
    QString name = QInputDialog::getText(nullptr, "Item Name", prompt, QLineEdit::Normal, defaultTxt, &ok);

    if (ok && !name.isEmpty()) {
        return name;
    } else {
        return "userCNCL-exit"; // Abort the creation
    }
}
