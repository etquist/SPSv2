#include "customMessageBox.h"

customMessageBox::customMessageBox(QWidget *parent, QString boxTitle, QString msgLabel, std::vector<QString> choices)
    : QDialog{parent}
{
    setWindowTitle(boxTitle);

    QVBoxLayout* layout = new QVBoxLayout(this);

    QLabel* messageLabel = new QLabel(msgLabel, this);
    layout->addWidget(messageLabel);

    for (const QString& button : choices){
        QPushButton* customButton = new QPushButton(button, this);
        connect(customButton, &QPushButton::clicked, this, &customMessageBox::handleCustomChoice);
        layout->addWidget(customButton);
    }

    setLayout(layout);
}
