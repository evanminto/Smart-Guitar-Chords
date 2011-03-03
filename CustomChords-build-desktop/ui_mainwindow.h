/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Feb 4 20:38:29 2011
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
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *chord1;
    QLineEdit *chord2;
    QLineEdit *chord3;
    QLineEdit *chord4;
    QLineEdit *chord5;
    QLineEdit *chord6;
    QPushButton *pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *tuning1;
    QLineEdit *tuning2;
    QLineEdit *tuning3;
    QLineEdit *tuning4;
    QLineEdit *tuning5;
    QLineEdit *tuning6;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *capo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(593, 285);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 130, 551, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        chord1 = new QLineEdit(layoutWidget);
        chord1->setObjectName(QString::fromUtf8("chord1"));

        horizontalLayout_2->addWidget(chord1);

        chord2 = new QLineEdit(layoutWidget);
        chord2->setObjectName(QString::fromUtf8("chord2"));

        horizontalLayout_2->addWidget(chord2);

        chord3 = new QLineEdit(layoutWidget);
        chord3->setObjectName(QString::fromUtf8("chord3"));

        horizontalLayout_2->addWidget(chord3);

        chord4 = new QLineEdit(layoutWidget);
        chord4->setObjectName(QString::fromUtf8("chord4"));

        horizontalLayout_2->addWidget(chord4);

        chord5 = new QLineEdit(layoutWidget);
        chord5->setObjectName(QString::fromUtf8("chord5"));

        horizontalLayout_2->addWidget(chord5);

        chord6 = new QLineEdit(layoutWidget);
        chord6->setObjectName(QString::fromUtf8("chord6"));

        horizontalLayout_2->addWidget(chord6);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 180, 114, 32));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 70, 551, 31));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        tuning1 = new QLineEdit(widget);
        tuning1->setObjectName(QString::fromUtf8("tuning1"));

        horizontalLayout->addWidget(tuning1);

        tuning2 = new QLineEdit(widget);
        tuning2->setObjectName(QString::fromUtf8("tuning2"));

        horizontalLayout->addWidget(tuning2);

        tuning3 = new QLineEdit(widget);
        tuning3->setObjectName(QString::fromUtf8("tuning3"));

        horizontalLayout->addWidget(tuning3);

        tuning4 = new QLineEdit(widget);
        tuning4->setObjectName(QString::fromUtf8("tuning4"));

        horizontalLayout->addWidget(tuning4);

        tuning5 = new QLineEdit(widget);
        tuning5->setObjectName(QString::fromUtf8("tuning5"));

        horizontalLayout->addWidget(tuning5);

        tuning6 = new QLineEdit(widget);
        tuning6->setObjectName(QString::fromUtf8("tuning6"));

        horizontalLayout->addWidget(tuning6);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(20, 20, 91, 24));
        horizontalLayout_3 = new QHBoxLayout(widget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        capo = new QLineEdit(widget1);
        capo->setObjectName(QString::fromUtf8("capo"));

        horizontalLayout_3->addWidget(capo);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 593, 22));
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
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Fingering", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Tuning", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Capo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
