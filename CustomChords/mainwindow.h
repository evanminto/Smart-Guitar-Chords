#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CustomGuitarChords.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <QMainWindow>
#include <QFileSystemModel>
#include <QModelIndex>
#include <QMessageBox>

using namespace std;

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void loadInstruments(string const &file, Instrument &in);
    void loadChords(string const &file, Chord &ch);

private:
    Ui::MainWindow *ui;
    Instrument current_inst;
    Chord current_chord;
    std::string base_tab;
    QDir inst_dir;
    QDir chord_dir;
    void printInstInfo();
    void printChordInfo();
    void enableChordForm();
    void enableInstForm();
    void disableChordForm();
    void disableInstForm();
    void wipeChordForm();
    void wipeInstForm();
    void handleTabChange();

    string findInst(string search, QDir d);

private slots:

private slots:
    void on_suggestions_activated(QString );
    void on_chord_tab_field_editingFinished();
    void on_chord_tab_field_textEdited(QString );
    void on_chord_tab_field_textChanged(QString );
    void on_chord_cancel_button_clicked();
    void on_inst_cancel_button_clicked();
    void on_chord_create_button_clicked();
    void on_inst_create_button_clicked();
    void on_chord_save_button_clicked();
    void on_inst_save_button_clicked();
    void on_del_chord_button_clicked();
    void on_del_inst_button_clicked();
    void on_chord_folder_button_clicked();
    void on_inst_folder_button_clicked();
    void on_ChordTree_clicked(QModelIndex index);
    void on_InstrumentTree_clicked(QModelIndex index);
};

#endif // MAINWINDOW_H
