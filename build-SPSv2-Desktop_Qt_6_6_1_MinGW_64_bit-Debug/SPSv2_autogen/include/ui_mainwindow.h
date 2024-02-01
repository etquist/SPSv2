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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

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
    QTabWidget *tabWidget;
    QWidget *tab_5;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QPushButton *newDatabaseName_tab1;
    QLabel *label_2;
    QTreeView *catalogView_1;
    QPushButton *newCatalogEntry_tab1;
    QPushButton *importDatabase_tab1;
    QLabel *label_3;
    QTabWidget *databaseEditor;
    QWidget *tab_8;
    QGridLayout *gridLayout_9;
    QLineEdit *lineEdit_3;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QLabel *label_6;
    QLabel *label_4;
    QSpacerItem *verticalSpacer;
    QWidget *tab_10;
    QGridLayout *gridLayout_11;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_6;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QSpacerItem *verticalSpacer_5;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *label_13;
    QWidget *tab_9;
    QGridLayout *gridLayout_10;
    QLabel *label_14;
    QTableView *tableView;
    QFrame *frame_2;
    QLabel *label_16;
    QLabel *label_15;
    QWidget *tab_11;
    QGridLayout *gridLayout_12;
    QLabel *label_10;
    QLineEdit *lineEdit_7;
    QLabel *label_11;
    QLineEdit *lineEdit_8;
    QLabel *label_12;
    QLineEdit *lineEdit_9;
    QSpacerItem *verticalSpacer_6;
    QWidget *tab_12;
    QWidget *tab_13;
    QWidget *tab;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *catalogueLabel;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_2;
    QFrame *Toolbar;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *verticalSpacer_4;
    QTreeView *catalogView;
    QFrame *gridEditWindow;
    QTableWidget *tableWidget;
    QTreeView *componentsListView;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QWidget *tab_4;
    QWidget *tab_3;
    QWidget *tab_6;
    QWidget *tab_7;
    QWidget *tab_2;
    QGridLayout *gridLayout_4;
    QListWidget *listWidget_3;
    QListWidget *listWidget_5;
    QPushButton *pushButton_2;
    QListWidget *listWidget_6;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_6;
    QListWidget *listWidget_9;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QListWidget *listWidget_7;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *horizontalSpacer_8;
    QSpacerItem *horizontalSpacer_5;
    QListWidget *listWidget_8;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuSave;
    QMenu *menuOpen;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1130, 627);
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
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        QFont font;
        font.setPointSize(9);
        tabWidget->setFont(font);
        tabWidget->setAutoFillBackground(true);
        tab_5 = new QWidget();
        tab_5->setObjectName("tab_5");
        gridLayout_6 = new QGridLayout(tab_5);
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName("gridLayout_5");
        newDatabaseName_tab1 = new QPushButton(tab_5);
        newDatabaseName_tab1->setObjectName("newDatabaseName_tab1");

        gridLayout_5->addWidget(newDatabaseName_tab1, 1, 0, 1, 1);

        label_2 = new QLabel(tab_5);
        label_2->setObjectName("label_2");
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_2, 0, 0, 1, 2);

        catalogView_1 = new QTreeView(tab_5);
        catalogView_1->setObjectName("catalogView_1");
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(catalogView_1->sizePolicy().hasHeightForWidth());
        catalogView_1->setSizePolicy(sizePolicy);
        catalogView_1->setMaximumSize(QSize(500, 16777215));
        catalogView_1->setDragEnabled(true);
        catalogView_1->setDragDropOverwriteMode(true);
        catalogView_1->setDragDropMode(QAbstractItemView::InternalMove);
        catalogView_1->setDefaultDropAction(Qt::MoveAction);
        catalogView_1->setSortingEnabled(true);

        gridLayout_5->addWidget(catalogView_1, 3, 0, 1, 2);

        newCatalogEntry_tab1 = new QPushButton(tab_5);
        newCatalogEntry_tab1->setObjectName("newCatalogEntry_tab1");

        gridLayout_5->addWidget(newCatalogEntry_tab1, 1, 1, 1, 1);

        importDatabase_tab1 = new QPushButton(tab_5);
        importDatabase_tab1->setObjectName("importDatabase_tab1");

        gridLayout_5->addWidget(importDatabase_tab1, 2, 0, 1, 2);

        label_3 = new QLabel(tab_5);
        label_3->setObjectName("label_3");
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout_5->addWidget(label_3, 0, 2, 1, 1);

        databaseEditor = new QTabWidget(tab_5);
        databaseEditor->setObjectName("databaseEditor");
        databaseEditor->setAutoFillBackground(true);
        tab_8 = new QWidget();
        tab_8->setObjectName("tab_8");
        gridLayout_9 = new QGridLayout(tab_8);
        gridLayout_9->setObjectName("gridLayout_9");
        lineEdit_3 = new QLineEdit(tab_8);
        lineEdit_3->setObjectName("lineEdit_3");

        gridLayout_9->addWidget(lineEdit_3, 3, 1, 1, 1);

        label_5 = new QLabel(tab_8);
        label_5->setObjectName("label_5");

        gridLayout_9->addWidget(label_5, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(tab_8);
        lineEdit_2->setObjectName("lineEdit_2");

        gridLayout_9->addWidget(lineEdit_2, 2, 1, 1, 1);

        lineEdit = new QLineEdit(tab_8);
        lineEdit->setObjectName("lineEdit");

        gridLayout_9->addWidget(lineEdit, 0, 1, 1, 1);

        label_6 = new QLabel(tab_8);
        label_6->setObjectName("label_6");

        gridLayout_9->addWidget(label_6, 3, 0, 1, 1);

        label_4 = new QLabel(tab_8);
        label_4->setObjectName("label_4");

        gridLayout_9->addWidget(label_4, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_9->addItem(verticalSpacer, 4, 1, 1, 1);

        databaseEditor->addTab(tab_8, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        gridLayout_11 = new QGridLayout(tab_10);
        gridLayout_11->setObjectName("gridLayout_11");
        lineEdit_4 = new QLineEdit(tab_10);
        lineEdit_4->setObjectName("lineEdit_4");

        gridLayout_11->addWidget(lineEdit_4, 0, 1, 1, 1);

        lineEdit_6 = new QLineEdit(tab_10);
        lineEdit_6->setObjectName("lineEdit_6");

        gridLayout_11->addWidget(lineEdit_6, 2, 1, 1, 1);

        label_9 = new QLabel(tab_10);
        label_9->setObjectName("label_9");

        gridLayout_11->addWidget(label_9, 2, 0, 1, 1);

        label_8 = new QLabel(tab_10);
        label_8->setObjectName("label_8");

        gridLayout_11->addWidget(label_8, 1, 0, 1, 1);

        label_7 = new QLabel(tab_10);
        label_7->setObjectName("label_7");

        gridLayout_11->addWidget(label_7, 0, 0, 1, 1);

        lineEdit_5 = new QLineEdit(tab_10);
        lineEdit_5->setObjectName("lineEdit_5");

        gridLayout_11->addWidget(lineEdit_5, 1, 1, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_11->addItem(verticalSpacer_5, 3, 0, 1, 1);

        frame = new QFrame(tab_10);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        label_13 = new QLabel(frame);
        label_13->setObjectName("label_13");
        label_13->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_13);


        gridLayout_11->addWidget(frame, 3, 1, 1, 2);

        databaseEditor->addTab(tab_10, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName("tab_9");
        gridLayout_10 = new QGridLayout(tab_9);
        gridLayout_10->setObjectName("gridLayout_10");
        label_14 = new QLabel(tab_9);
        label_14->setObjectName("label_14");

        gridLayout_10->addWidget(label_14, 0, 0, 1, 1);

        tableView = new QTableView(tab_9);
        tableView->setObjectName("tableView");

        gridLayout_10->addWidget(tableView, 1, 0, 1, 1);

        frame_2 = new QFrame(tab_9);
        frame_2->setObjectName("frame_2");
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        label_16 = new QLabel(frame_2);
        label_16->setObjectName("label_16");
        label_16->setGeometry(QRect(120, 160, 63, 20));

        gridLayout_10->addWidget(frame_2, 1, 1, 1, 1);

        label_15 = new QLabel(tab_9);
        label_15->setObjectName("label_15");

        gridLayout_10->addWidget(label_15, 0, 1, 1, 1);

        databaseEditor->addTab(tab_9, QString());
        tab_11 = new QWidget();
        tab_11->setObjectName("tab_11");
        gridLayout_12 = new QGridLayout(tab_11);
        gridLayout_12->setObjectName("gridLayout_12");
        label_10 = new QLabel(tab_11);
        label_10->setObjectName("label_10");

        gridLayout_12->addWidget(label_10, 0, 0, 1, 1);

        lineEdit_7 = new QLineEdit(tab_11);
        lineEdit_7->setObjectName("lineEdit_7");

        gridLayout_12->addWidget(lineEdit_7, 0, 1, 1, 1);

        label_11 = new QLabel(tab_11);
        label_11->setObjectName("label_11");

        gridLayout_12->addWidget(label_11, 1, 0, 1, 1);

        lineEdit_8 = new QLineEdit(tab_11);
        lineEdit_8->setObjectName("lineEdit_8");

        gridLayout_12->addWidget(lineEdit_8, 1, 1, 1, 1);

        label_12 = new QLabel(tab_11);
        label_12->setObjectName("label_12");

        gridLayout_12->addWidget(label_12, 2, 0, 1, 1);

        lineEdit_9 = new QLineEdit(tab_11);
        lineEdit_9->setObjectName("lineEdit_9");

        gridLayout_12->addWidget(lineEdit_9, 2, 1, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_12->addItem(verticalSpacer_6, 3, 1, 1, 1);

        databaseEditor->addTab(tab_11, QString());
        tab_12 = new QWidget();
        tab_12->setObjectName("tab_12");
        databaseEditor->addTab(tab_12, QString());
        tab_13 = new QWidget();
        tab_13->setObjectName("tab_13");
        databaseEditor->addTab(tab_13, QString());

        gridLayout_5->addWidget(databaseEditor, 1, 2, 3, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 0, 1, 1);

        tabWidget->addTab(tab_5, QString());
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout_3 = new QGridLayout(tab);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 1, 1, 1);

        catalogueLabel = new QLabel(tab);
        catalogueLabel->setObjectName("catalogueLabel");
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        catalogueLabel->setFont(font2);
        catalogueLabel->setTextFormat(Qt::AutoText);
        catalogueLabel->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);
        catalogueLabel->setWordWrap(false);

        gridLayout->addWidget(catalogueLabel, 2, 4, 2, 1);

        verticalSpacer_3 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_3, 1, 0, 1, 5);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout->addItem(verticalSpacer_2, 5, 0, 1, 1);

        Toolbar = new QFrame(tab);
        Toolbar->setObjectName("Toolbar");
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Toolbar->sizePolicy().hasHeightForWidth());
        Toolbar->setSizePolicy(sizePolicy2);
        Toolbar->setMinimumSize(QSize(0, 40));
        Toolbar->setFrameShape(QFrame::WinPanel);
        Toolbar->setFrameShadow(QFrame::Raised);
        Toolbar->setLineWidth(2);
        Toolbar->setMidLineWidth(1);
        horizontalLayout = new QHBoxLayout(Toolbar);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout->addWidget(Toolbar, 0, 0, 1, 5);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Maximum);

        gridLayout->addItem(verticalSpacer_4, 5, 4, 1, 1);

        catalogView = new QTreeView(tab);
        catalogView->setObjectName("catalogView");
        sizePolicy.setHeightForWidth(catalogView->sizePolicy().hasHeightForWidth());
        catalogView->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setPointSize(10);
        catalogView->setFont(font3);
        catalogView->setSortingEnabled(false);

        gridLayout->addWidget(catalogView, 4, 4, 1, 1);

        gridEditWindow = new QFrame(tab);
        gridEditWindow->setObjectName("gridEditWindow");
        sizePolicy1.setHeightForWidth(gridEditWindow->sizePolicy().hasHeightForWidth());
        gridEditWindow->setSizePolicy(sizePolicy1);
        gridEditWindow->setMinimumSize(QSize(200, 200));
        gridEditWindow->setAutoFillBackground(false);
        gridEditWindow->setStyleSheet(QString::fromUtf8("background-color:  white"));
        gridEditWindow->setFrameShape(QFrame::Box);
        gridEditWindow->setFrameShadow(QFrame::Plain);

        gridLayout->addWidget(gridEditWindow, 2, 2, 3, 1);

        tableWidget = new QTableWidget(tab);
        tableWidget->setObjectName("tableWidget");
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tableWidget->sizePolicy().hasHeightForWidth());
        tableWidget->setSizePolicy(sizePolicy3);
        tableWidget->setFont(font3);

        gridLayout->addWidget(tableWidget, 6, 0, 1, 5);

        componentsListView = new QTreeView(tab);
        componentsListView->setObjectName("componentsListView");
        sizePolicy.setHeightForWidth(componentsListView->sizePolicy().hasHeightForWidth());
        componentsListView->setSizePolicy(sizePolicy);
        componentsListView->setFont(font3);
        componentsListView->setDragEnabled(true);
        componentsListView->setDragDropMode(QAbstractItemView::DragDrop);

        gridLayout->addWidget(componentsListView, 4, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 4, 3, 1, 1);

        label = new QLabel(tab);
        label->setObjectName("label");
        label->setFont(font2);
        label->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        gridLayout->addWidget(label, 2, 0, 2, 1);


        gridLayout_3->addLayout(gridLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        tabWidget->addTab(tab_3, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName("tab_7");
        tabWidget->addTab(tab_7, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_4 = new QGridLayout(tab_2);
        gridLayout_4->setObjectName("gridLayout_4");
        listWidget_3 = new QListWidget(tab_2);
        listWidget_3->setObjectName("listWidget_3");

        gridLayout_4->addWidget(listWidget_3, 0, 4, 1, 1);

        listWidget_5 = new QListWidget(tab_2);
        listWidget_5->setObjectName("listWidget_5");

        gridLayout_4->addWidget(listWidget_5, 0, 10, 1, 1);

        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout_4->addWidget(pushButton_2, 1, 6, 1, 1);

        listWidget_6 = new QListWidget(tab_2);
        listWidget_6->setObjectName("listWidget_6");

        gridLayout_4->addWidget(listWidget_6, 0, 8, 1, 1);

        pushButton_5 = new QPushButton(tab_2);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout_4->addWidget(pushButton_5, 1, 12, 1, 1);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_6, 0, 7, 1, 1);

        listWidget_9 = new QListWidget(tab_2);
        listWidget_9->setObjectName("listWidget_9");

        gridLayout_4->addWidget(listWidget_9, 0, 12, 1, 1);

        pushButton_4 = new QPushButton(tab_2);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout_4->addWidget(pushButton_4, 1, 10, 1, 1);

        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout_4->addWidget(pushButton_3, 1, 8, 1, 1);

        listWidget_7 = new QListWidget(tab_2);
        listWidget_7->setObjectName("listWidget_7");

        gridLayout_4->addWidget(listWidget_7, 0, 6, 1, 1);

        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName("pushButton");

        gridLayout_4->addWidget(pushButton, 1, 4, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_7, 0, 9, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_8, 0, 11, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_5, 0, 5, 1, 1);

        listWidget_8 = new QListWidget(tab_2);
        listWidget_8->setObjectName("listWidget_8");

        gridLayout_4->addWidget(listWidget_8, 0, 13, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_2->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1130, 26));
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

        tabWidget->setCurrentIndex(1);
        databaseEditor->setCurrentIndex(0);


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
        newDatabaseName_tab1->setText(QCoreApplication::translate("MainWindow", "New Database", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Database", nullptr));
        newCatalogEntry_tab1->setText(QCoreApplication::translate("MainWindow", "New Database Entry", nullptr));
        importDatabase_tab1->setText(QCoreApplication::translate("MainWindow", "Import Database", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Item Properties", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Voltage", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Name", nullptr));
        databaseEditor->setTabText(databaseEditor->indexOf(tab_8), QCoreApplication::translate("MainWindow", "General", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Trace Preview", nullptr));
        databaseEditor->setTabText(databaseEditor->indexOf(tab_10), QCoreApplication::translate("MainWindow", "Steady State", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Trace Editor", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Trace Editor", nullptr));
        databaseEditor->setTabText(databaseEditor->indexOf(tab_9), QCoreApplication::translate("MainWindow", "Transient", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        databaseEditor->setTabText(databaseEditor->indexOf(tab_11), QCoreApplication::translate("MainWindow", "Common Mode", nullptr));
        databaseEditor->setTabText(databaseEditor->indexOf(tab_12), QCoreApplication::translate("MainWindow", "Vibration Steady State", nullptr));
        databaseEditor->setTabText(databaseEditor->indexOf(tab_13), QCoreApplication::translate("MainWindow", "...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("MainWindow", "Database Editor", nullptr));
        catalogueLabel->setText(QCoreApplication::translate("MainWindow", "Database", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Active Components", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Network Design", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "System Definition", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Mission Definition", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Timeline", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QCoreApplication::translate("MainWindow", "Results", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "New Load", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "New Filter", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "New Genset", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "New ESM", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "New Bus", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Debugging", nullptr));
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
