#ifndef CUSTOMMESSAGEBOX_H
#define CUSTOMMESSAGEBOX_H

#include <QObject>
#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QMessageBox>
#include <QLabel>

class customMessageBox : public QDialog
{
    Q_OBJECT
public:
    explicit customMessageBox(QWidget *parent = nullptr, QString boxTitle = "default", QString msgLabel = "default", std::vector<QString> choices = {"hello", "default"});

signals:
    void customChoiceSelected();

private slots:
    void handleCustomChoice(){
        emit customChoiceSelected();
        accept();
    }
};

#endif // NEWCATALOGENTRYMESSAGE_H
