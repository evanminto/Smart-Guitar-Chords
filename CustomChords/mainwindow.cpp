#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions.h"
#include <QFileSystemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    startup();

    // SET UP INSTRUMENT DISPLAY

    QFileSystemModel *fileModel = new QFileSystemModel;
    QString library(QDir::homePath());
    library.append("/Library/SmartGuitarChords/Instruments");
    fileModel->setRootPath(library);

    ui->InstrumentTree->setModel(fileModel);
    ui->InstrumentTree->setRootIndex(fileModel->index(library));

    // SET UP CHORD DISPLAY

    library = QDir::homePath();
    library.append("/Library/SmartGuitarChords/Chords");
    fileModel->setRootPath(library);

    ui->ChordTree->setModel(fileModel);
    ui->ChordTree->setRootIndex(fileModel->index(library));
}

MainWindow::~MainWindow()
{
    delete ui;
}
