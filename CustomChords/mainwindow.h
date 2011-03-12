#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "CustomGuitarChords.h"
#include <string>
#include <vector>
#include <cstdlib>
#include <QMainWindow>
#include <QFileSystemModel>
#include <QModelIndex>

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
    QDir inst_dir;
    QDir chord_dir;
    void printInstInfo();
    void printChordInfo();

private slots:

private slots:
    //void on_inst_folder_button_clicked();
    void on_ChordTree_clicked(QModelIndex index);
    void on_InstrumentTree_clicked(QModelIndex index);
};

#endif // MAINWINDOW_H
