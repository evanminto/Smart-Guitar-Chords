#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "functions.h"
#include <QFileSystemModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // SET UP QFILESYSTEMMODEL

    readPreferences();

    QFileSystemModel *fileModel = new QFileSystemModel;
    QString library(QDir::homePath());
    library.append("/Library/SmartGuitarChords");
    fileModel->setRootPath(library);

    ui->InstrumentTree->setModel(fileModel);
    ui->InstrumentTree->setRootIndex(fileModel->index(library));
}

MainWindow::~MainWindow()
{
    delete ui;
}
