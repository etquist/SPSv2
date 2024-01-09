/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>
#include <customgraphicswidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionOpen_Documentation;
    QAction *actionNew;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QListWidget *listWidget_2;
    QFrame *Toolbar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton_6;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *toolButton_8;
    QToolButton *toolButton_7;
    QToolButton *toolButton_9;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer_4;
    customGraphicsWidget *networkInterface;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer;
    QLabel *label;
    QLabel *catalogueLabel;
    QTableWidget *tableWidget;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSave;
    QMenu *menuOpen;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(817, 483);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSave_As = new QAction(MainWindow);
        actionSave_As->setObjectName("actionSave_As");
        actionOpen_Documentation = new QAction(MainWindow);
        actionOpen_Documentation->setObjectName("actionOpen_Documentation");
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName("actionNew");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 3, 1, 1);

        listWidget_2 = new QListWidget(centralwidget);
        listWidget_2->setObjectName("listWidget_2");
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listWidget_2->sizePolicy().hasHeightForWidth());
        listWidget_2->setSizePolicy(sizePolicy);

        gridLayout->addWidget(listWidget_2, 4, 4, 1, 1);

        Toolbar = new QFrame(centralwidget);
        Toolbar->setObjectName("Toolbar");
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Toolbar->sizePolicy().hasHeightForWidth());
        Toolbar->setSizePolicy(sizePolicy1);
        Toolbar->setMinimumSize(QSize(0, 40));
        Toolbar->setFrameShape(QFrame::WinPanel);
        Toolbar->setFrameShadow(QFrame::Raised);
        Toolbar->setLineWidth(4);
        Toolbar->setMidLineWidth(2);
        horizontalLayout = new QHBoxLayout(Toolbar);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        toolButton_4 = new QToolButton(Toolbar);
        toolButton_4->setObjectName("toolButton_4");
        toolButton_4->setAutoRaise(false);

        horizontalLayout->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(Toolbar);
        toolButton_5->setObjectName("toolButton_5");

        horizontalLayout->addWidget(toolButton_5);

        toolButton_6 = new QToolButton(Toolbar);
        toolButton_6->setObjectName("toolButton_6");

        horizontalLayout->addWidget(toolButton_6);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        toolButton_8 = new QToolButton(Toolbar);
        toolButton_8->setObjectName("toolButton_8");

        horizontalLayout->addWidget(toolButton_8);

        toolButton_7 = new QToolButton(Toolbar);
        toolButton_7->setObjectName("toolButton_7");

        horizontalLayout->addWidget(toolButton_7);

        toolButton_9 = new QToolButton(Toolbar);
        toolButton_9->setObjectName("toolButton_9");

        horizontalLayout->addWidget(toolButton_9);


        gridLayout->addWidget(Toolbar, 0, 0, 1, 5);

        verticalSpacer_3 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 1, 0, 1, 5);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout->addItem(verticalSpacer_2, 5, 0, 1, 1);

        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        sizePolicy.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy);
        listWidget->setDragEnabled(true);
        listWidget->setDragDropMode(QAbstractItemView::DragDrop);

        gridLayout->addWidget(listWidget, 4, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout->addItem(verticalSpacer_4, 5, 4, 1, 1);

        networkInterface = new customGraphicsWidget(centralwidget);
        networkInterface->setObjectName("networkInterface");
        networkInterface->setLineWidth(3);
        networkInterface->setInteractive(true);
        networkInterface->setDragMode(QGraphicsView::NoDrag);

        gridLayout->addWidget(networkInterface, 3, 2, 3, 1);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout->addItem(verticalSpacer_5, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout->addItem(verticalSpacer, 2, 4, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label, 3, 0, 1, 1);

        catalogueLabel = new QLabel(centralwidget);
        catalogueLabel->setObjectName("catalogueLabel");
        catalogueLabel->setTextFormat(Qt::AutoText);
        catalogueLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        catalogueLabel->setWordWrap(false);

        gridLayout->addWidget(catalogueLabel, 3, 4, 1, 1);


        gridLayout_2->addLayout(gridLayout, 2, 0, 1, 1);

        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName("tableWidget");
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy2);

        gridLayout_2->addWidget(tableWidget, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 817, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuSave = new QMenu(menubar);
        menuSave->setObjectName("menuSave");
        menuOpen = new QMenu(menubar);
        menuOpen->setObjectName("menuOpen");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuSave->menuAction());
        menubar->addAction(menuOpen->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_As);
        menuFile->addAction(actionOpen_Documentation);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionSave_As->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        actionOpen_Documentation->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        toolButton_4->setText(QCoreApplication::translate("MainWindow", "Define New Catalogue Entry", nullptr));
        toolButton_5->setText(QCoreApplication::translate("MainWindow", "Import Components", nullptr));
        toolButton_6->setText(QCoreApplication::translate("MainWindow", "Import Catalogue", nullptr));
        toolButton_8->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_7->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toolButton_9->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Components", nullptr));
        catalogueLabel->setText(QCoreApplication::translate("MainWindow", "Catalogue", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuSave->setTitle(QCoreApplication::translate("MainWindow", "Save", nullptr));
        menuOpen->setTitle(QCoreApplication::translate("MainWindow", "Open", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
