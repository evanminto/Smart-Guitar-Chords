/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Mar 11 20:30:17 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTreeView *InstrumentTree;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QTreeView *ChordTree;
    QLabel *filepath;
    QLabel *filepath2;
    QLabel *statusbar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(796, 536);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 60, 731, 361));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        InstrumentTree = new QTreeView(layoutWidget);
        InstrumentTree->setObjectName(QString::fromUtf8("InstrumentTree"));
        InstrumentTree->header()->setVisible(false);
        InstrumentTree->header()->setDefaultSectionSize(150);
        InstrumentTree->header()->setStretchLastSection(true);

        verticalLayout->addWidget(InstrumentTree);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        ChordTree = new QTreeView(layoutWidget);
        ChordTree->setObjectName(QString::fromUtf8("ChordTree"));
        ChordTree->header()->setDefaultSectionSize(150);

        verticalLayout_2->addWidget(ChordTree);


        horizontalLayout->addLayout(verticalLayout_2);

        filepath = new QLabel(centralWidget);
        filepath->setObjectName(QString::fromUtf8("filepath"));
        filepath->setGeometry(QRect(40, 0, 451, 16));
        filepath2 = new QLabel(centralWidget);
        filepath2->setObjectName(QString::fromUtf8("filepath2"));
        filepath2->setGeometry(QRect(40, 30, 451, 16));
        statusbar = new QLabel(centralWidget);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setGeometry(QRect(30, 430, 731, 16));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 796, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Smart Guitar Chords", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Instruments", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Chords", 0, QApplication::UnicodeUTF8));
        filepath->setText(QString());
        filepath2->setText(QString());
        statusbar->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
