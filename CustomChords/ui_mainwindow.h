/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Mar 25 09:19:08 2011
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
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
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
    QLabel *statusbar;
    QPushButton *chord_folder_button;
    QPushButton *inst_folder_button;
    QLineEdit *inst_folder_name;
    QLineEdit *chord_folder_name;
    QPushButton *del_inst_button;
    QPushButton *del_chord_button;
    QFrame *line;
    QFrame *line_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *inst_edit_label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *inst_name_label;
    QLineEdit *inst_name_field;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *inst_tuning_label;
    QLineEdit *inst_tuning_field;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_4;
    QLabel *inst_numstrings_label;
    QLineEdit *inst_numstrings_field;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *inst_cancel_button;
    QPushButton *inst_save_button;
    QPushButton *inst_create_button;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_4;
    QLabel *chord_edit_label;
    QHBoxLayout *horizontalLayout_5;
    QLabel *chord_name_label;
    QLineEdit *chord_name_field;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_6;
    QLabel *chord_tab_label;
    QLineEdit *chord_tab_field;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout_7;
    QLabel *chord_capo_label;
    QLineEdit *chord_capo_field;
    QCheckBox *chord_relcapo_checkbox;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *chord_cancel_button;
    QPushButton *chord_save_button;
    QPushButton *chord_create_button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(815, 654);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 330, 731, 231));
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
        InstrumentTree->header()->setVisible(true);
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

        statusbar = new QLabel(centralWidget);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        statusbar->setGeometry(QRect(40, 580, 731, 16));
        chord_folder_button = new QPushButton(centralWidget);
        chord_folder_button->setObjectName(QString::fromUtf8("chord_folder_button"));
        chord_folder_button->setGeometry(QRect(590, 260, 181, 31));
        inst_folder_button = new QPushButton(centralWidget);
        inst_folder_button->setObjectName(QString::fromUtf8("inst_folder_button"));
        inst_folder_button->setGeometry(QRect(220, 260, 181, 31));
        inst_folder_name = new QLineEdit(centralWidget);
        inst_folder_name->setObjectName(QString::fromUtf8("inst_folder_name"));
        inst_folder_name->setGeometry(QRect(50, 260, 161, 22));
        chord_folder_name = new QLineEdit(centralWidget);
        chord_folder_name->setObjectName(QString::fromUtf8("chord_folder_name"));
        chord_folder_name->setGeometry(QRect(420, 260, 161, 22));
        del_inst_button = new QPushButton(centralWidget);
        del_inst_button->setObjectName(QString::fromUtf8("del_inst_button"));
        del_inst_button->setGeometry(QRect(220, 290, 181, 31));
        del_chord_button = new QPushButton(centralWidget);
        del_chord_button->setObjectName(QString::fromUtf8("del_chord_button"));
        del_chord_button->setGeometry(QRect(590, 290, 181, 31));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(-10, 220, 831, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(390, -10, 20, 241));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 20, 331, 201));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        inst_edit_label = new QLabel(widget);
        inst_edit_label->setObjectName(QString::fromUtf8("inst_edit_label"));
        inst_edit_label->setLayoutDirection(Qt::LeftToRight);
        inst_edit_label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(inst_edit_label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        inst_name_label = new QLabel(widget);
        inst_name_label->setObjectName(QString::fromUtf8("inst_name_label"));

        horizontalLayout_2->addWidget(inst_name_label);

        inst_name_field = new QLineEdit(widget);
        inst_name_field->setObjectName(QString::fromUtf8("inst_name_field"));
        inst_name_field->setEnabled(false);

        horizontalLayout_2->addWidget(inst_name_field);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_2->addWidget(label_9);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        inst_tuning_label = new QLabel(widget);
        inst_tuning_label->setObjectName(QString::fromUtf8("inst_tuning_label"));

        horizontalLayout_3->addWidget(inst_tuning_label);

        inst_tuning_field = new QLineEdit(widget);
        inst_tuning_field->setObjectName(QString::fromUtf8("inst_tuning_field"));
        inst_tuning_field->setEnabled(false);

        horizontalLayout_3->addWidget(inst_tuning_field);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        inst_numstrings_label = new QLabel(widget);
        inst_numstrings_label->setObjectName(QString::fromUtf8("inst_numstrings_label"));

        horizontalLayout_4->addWidget(inst_numstrings_label);

        inst_numstrings_field = new QLineEdit(widget);
        inst_numstrings_field->setObjectName(QString::fromUtf8("inst_numstrings_field"));
        inst_numstrings_field->setEnabled(false);

        horizontalLayout_4->addWidget(inst_numstrings_field);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_4->addWidget(label_11);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        inst_cancel_button = new QPushButton(widget);
        inst_cancel_button->setObjectName(QString::fromUtf8("inst_cancel_button"));
        inst_cancel_button->setEnabled(true);

        horizontalLayout_8->addWidget(inst_cancel_button);

        inst_save_button = new QPushButton(widget);
        inst_save_button->setObjectName(QString::fromUtf8("inst_save_button"));
        inst_save_button->setEnabled(false);

        horizontalLayout_8->addWidget(inst_save_button);


        verticalLayout_3->addLayout(horizontalLayout_8);

        inst_create_button = new QPushButton(widget);
        inst_create_button->setObjectName(QString::fromUtf8("inst_create_button"));

        verticalLayout_3->addWidget(inst_create_button);

        widget1 = new QWidget(centralWidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(430, 20, 341, 206));
        verticalLayout_4 = new QVBoxLayout(widget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        chord_edit_label = new QLabel(widget1);
        chord_edit_label->setObjectName(QString::fromUtf8("chord_edit_label"));
        chord_edit_label->setLayoutDirection(Qt::LeftToRight);
        chord_edit_label->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(chord_edit_label);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        chord_name_label = new QLabel(widget1);
        chord_name_label->setObjectName(QString::fromUtf8("chord_name_label"));

        horizontalLayout_5->addWidget(chord_name_label);

        chord_name_field = new QLineEdit(widget1);
        chord_name_field->setObjectName(QString::fromUtf8("chord_name_field"));
        chord_name_field->setEnabled(false);

        horizontalLayout_5->addWidget(chord_name_field);

        label_12 = new QLabel(widget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_5->addWidget(label_12);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        chord_tab_label = new QLabel(widget1);
        chord_tab_label->setObjectName(QString::fromUtf8("chord_tab_label"));

        horizontalLayout_6->addWidget(chord_tab_label);

        chord_tab_field = new QLineEdit(widget1);
        chord_tab_field->setObjectName(QString::fromUtf8("chord_tab_field"));
        chord_tab_field->setEnabled(false);

        horizontalLayout_6->addWidget(chord_tab_field);

        label_13 = new QLabel(widget1);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_6->addWidget(label_13);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        chord_capo_label = new QLabel(widget1);
        chord_capo_label->setObjectName(QString::fromUtf8("chord_capo_label"));

        horizontalLayout_7->addWidget(chord_capo_label);

        chord_capo_field = new QLineEdit(widget1);
        chord_capo_field->setObjectName(QString::fromUtf8("chord_capo_field"));
        chord_capo_field->setEnabled(false);

        horizontalLayout_7->addWidget(chord_capo_field);

        chord_relcapo_checkbox = new QCheckBox(widget1);
        chord_relcapo_checkbox->setObjectName(QString::fromUtf8("chord_relcapo_checkbox"));
        chord_relcapo_checkbox->setEnabled(false);
        chord_relcapo_checkbox->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_7->addWidget(chord_relcapo_checkbox);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        chord_cancel_button = new QPushButton(widget1);
        chord_cancel_button->setObjectName(QString::fromUtf8("chord_cancel_button"));
        chord_cancel_button->setEnabled(true);

        horizontalLayout_9->addWidget(chord_cancel_button);

        chord_save_button = new QPushButton(widget1);
        chord_save_button->setObjectName(QString::fromUtf8("chord_save_button"));
        chord_save_button->setEnabled(false);

        horizontalLayout_9->addWidget(chord_save_button);


        verticalLayout_4->addLayout(horizontalLayout_9);

        chord_create_button = new QPushButton(widget1);
        chord_create_button->setObjectName(QString::fromUtf8("chord_create_button"));

        verticalLayout_4->addWidget(chord_create_button);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 815, 22));
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
        statusbar->setText(QString());
        chord_folder_button->setText(QApplication::translate("MainWindow", "Create Folder", 0, QApplication::UnicodeUTF8));
        inst_folder_button->setText(QApplication::translate("MainWindow", "Create Folder", 0, QApplication::UnicodeUTF8));
        del_inst_button->setText(QApplication::translate("MainWindow", "Delete Selected", 0, QApplication::UnicodeUTF8));
        del_chord_button->setText(QApplication::translate("MainWindow", "Delete Selected", 0, QApplication::UnicodeUTF8));
        inst_edit_label->setText(QApplication::translate("MainWindow", "Instrument Create/Edit", 0, QApplication::UnicodeUTF8));
        inst_name_label->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        label_9->setText(QString());
        inst_tuning_label->setText(QApplication::translate("MainWindow", "Tuning", 0, QApplication::UnicodeUTF8));
        label_10->setText(QString());
        inst_numstrings_label->setText(QApplication::translate("MainWindow", "Number of Strings", 0, QApplication::UnicodeUTF8));
        label_11->setText(QString());
        inst_cancel_button->setText(QApplication::translate("MainWindow", "Edit Instrument", 0, QApplication::UnicodeUTF8));
        inst_save_button->setText(QApplication::translate("MainWindow", "Save Instrument", 0, QApplication::UnicodeUTF8));
        inst_create_button->setText(QApplication::translate("MainWindow", "Create New Instrument", 0, QApplication::UnicodeUTF8));
        chord_edit_label->setText(QApplication::translate("MainWindow", "Chord Create/Edit", 0, QApplication::UnicodeUTF8));
        chord_name_label->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        label_12->setText(QString());
        chord_tab_label->setText(QApplication::translate("MainWindow", "Tab   ", 0, QApplication::UnicodeUTF8));
        label_13->setText(QString());
        chord_capo_label->setText(QApplication::translate("MainWindow", "Capo ", 0, QApplication::UnicodeUTF8));
        chord_relcapo_checkbox->setText(QApplication::translate("MainWindow", "Relative Capo?", 0, QApplication::UnicodeUTF8));
        chord_cancel_button->setText(QApplication::translate("MainWindow", "Edit Chord", 0, QApplication::UnicodeUTF8));
        chord_save_button->setText(QApplication::translate("MainWindow", "Save Instrument", 0, QApplication::UnicodeUTF8));
        chord_create_button->setText(QApplication::translate("MainWindow", "Create New Chord", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
