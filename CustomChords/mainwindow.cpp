#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    inst_dir = QDir(library);

    // SET UP CHORD DISPLAY

    library = QDir::homePath();
    library.append("/Library/SmartGuitarChords/Chords");
    fileModel->setRootPath(library);

    ui->ChordTree->setModel(fileModel);
    ui->ChordTree->setRootIndex(fileModel->index(library));
    chord_dir = QDir(library);

    Chord c;
    Instrument i;

    current_chord = c;
    current_inst = i;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadInstruments(const string& file, Instrument &in)
{
    std::string inst_name, temp;
    std::vector <int> tuning;
    int strings_num = 0;
    int id = 0;

    std::ifstream infile(file.c_str());

    if (!infile.is_open())
        return;

    ui->statusbar->setText(QString::fromStdString("Loading instrument file..."));

    infile>>id;
    ui->statusbar->setText(QString::fromStdString("Reading instrument ID..."));

    infile>>temp;

    if (temp[0] == '"' && temp[temp.length()-1] != '"')
    {
        inst_name = temp + " ";
        while (temp[temp.length()-1] != '"')
        {
            infile>>temp;
            inst_name += temp;
            inst_name += " ";
        }
    }

    else if (temp[0] == '"' && temp[temp.length()-1] == '"')
        inst_name = temp;

    inst_name = trim(inst_name);

    if (inst_name.length() > 1)
        inst_name = inst_name.substr(1, inst_name.size()-2);

    ui->statusbar->setText(QString::fromStdString("Reading instrument name..."));

    infile>>strings_num;

    ui->statusbar->setText(QString::fromStdString("Reading instrument string number..."));

    infile>>temp;

    if (temp[0] == '{')
    {
        for (int i=0; i<strings_num; i++)
        {
            infile>>temp;
            tuning.push_back(atoi(temp.c_str()));
        }
    }
    infile>>temp;		// Catch last }

    ui->statusbar->setText(QString::fromStdString("Reading instrument tuning..."));

    /*
    Instrument i(inst_name, strings_num, tuning);
    i.setID(id);
    if (inst_name != "") *in = i;
    */

    Instrument temp_inst(inst_name, strings_num, tuning);
    temp_inst.setID(id);

    ui->statusbar->setText(QString::fromStdString("Creating instrument..."));

    in = temp_inst;

    ui->statusbar->setText(QString::fromStdString("Setting instrument..."));

    tuning.clear();
    inst_name = "";
    strings_num = 0;

    infile.close();

    current_chord.invalidate();

    ui->statusbar->setText(QString::fromStdString("Wiping chord display..."));

    ui->statusbar->setText(QString::fromStdString(""));
}

void MainWindow::loadChords(const string& file, Chord &ch)
{
    std::string inst_name, chord_name, temp;
    std::vector <std::string> tab;
    int capo_num = 0;
    bool rel_capo;
    int id = 0;

    int strings_num;

    std::ifstream infile(file.c_str());

    if (!infile.is_open())
        return;

    ui->statusbar->setText(QString::fromStdString("Loading chord file..."));

    infile>>id;
    ui->statusbar->setText(QString::fromStdString("Reading chord ID..."));

    infile>>temp;

    // GET CHORD NAME

    if (temp[0] == '"' && temp[temp.length()-1] != '"')
    {
        chord_name = temp + " ";
        while (temp[temp.length()-1] != '"')
        {
            infile>>temp;
            chord_name += temp;
            chord_name += " ";
        }
    }

    else if (temp[0] == '"' && temp[temp.length()-1] == '"')
        chord_name = temp;

    chord_name = trim(chord_name);

    if (chord_name.length() > 1)
        chord_name = chord_name.substr(1, chord_name.size()-2);

    ui->statusbar->setText(QString::fromStdString("Reading chord name..."));

    // GET INSTRUMENT

    infile>>temp;

    if (temp[0] == '"' && temp[temp.length()-1] != '"')
    {
        inst_name = temp + " ";
        while (temp[temp.length()-1] != '"')
        {
            infile>>temp;
            inst_name += temp;
            inst_name += " ";
        }
    }

    else if (temp[0] == '"' && temp[temp.length()-1] == '"')
        inst_name = temp;

    inst_name = trim(inst_name);

    if (inst_name.length() > 1)
        inst_name = inst_name.substr(1, inst_name.size()-2);

    //string inst_loc = findInst();

    loadInstruments(QDir::homePath().toStdString()+"/Library/SmartGuitarChords/Instruments/"+inst_name+".txt", current_inst);

    //ui->filepath->setText(QString::fromStdString("/Library/SmartGuitarChords/Instruments/"+inst_name+".txt"));

    strings_num = current_inst.getNumStrings();

    ui->statusbar->setText(QString::fromStdString("Reading number of strings..."));

    // GET CAPO AND RELATIVITY

    infile>>capo_num;
    ui->statusbar->setText(QString::fromStdString("Reading chord capo..."));

    infile>>temp;

    if (temp == "1")	rel_capo = true;
    else		rel_capo = false;

    ui->statusbar->setText(QString::fromStdString("Reading chord capo relativity..."));

    // GET TABLATURE

    infile>>temp;

    if (temp[0] == '{')
    {
        for (int i=0; i<strings_num; i++)
        {
            infile>>temp;
            tab.push_back(temp);
        }
    }
    infile>>temp;		// Catch last }

    ui->statusbar->setText(QString::fromStdString("Reading chord tab..."));

    /*
    Chord c(current_inst, chord_name, tab, capo_num, rel_capo);
    c.setID(id);
    if (chord_name != "") *ch = c;
    */

    Chord temp_chord(&current_inst, chord_name, tab, capo_num, rel_capo);
    temp_chord.setID(id);

    ui->statusbar->setText(QString::fromStdString("Creating chord..."));

    ch = temp_chord;

    ui->statusbar->setText(QString::fromStdString("Setting chord..."));

    tab.clear();
    inst_name = chord_name = temp = "";
    capo_num = 0;
    rel_capo = false;

    infile.close();

    ui->statusbar->setText(QString::fromStdString(""));
}

void MainWindow::on_InstrumentTree_clicked(QModelIndex index)
{
    QString path = "";
    QModelIndex i(index);

    while (i.parent().data().toString() != "Instruments")
    {
        path = i.parent().data().toString() + "/" + path;
        i = i.parent();
    }

    inst_dir = QDir(QDir::homePath()+"/Library/SmartGuitarChords/Instruments/"+path+index.data().toString());

    if (inst_dir.exists())
    {
        if (inst_dir.count() > 2)
            ui->del_inst_button->setEnabled(false);

        else
            ui->del_inst_button->setEnabled(true);

        ui->statusbar->setText("\"" + index.data().toString() + "\" is a folder containing "+QString::number(inst_dir.count()-2)+" item(s).");
    }

    else if (inst_dir.exists(inst_dir.absolutePath()))
    {
        ui->del_inst_button->setEnabled(true);

        string old_linked_inst_name;

        if (current_chord.isInstrumentSet())
            old_linked_inst_name = current_chord.getInstrument().getName();

        loadInstruments(inst_dir.absolutePath().toStdString(), current_inst);

        if (old_linked_inst_name != current_inst.getName())
        {
            Chord c;
            current_chord = c;
            printChordInfo();
        }

        printInstInfo();

        ui->statusbar->setText(index.data().toString() + " is a valid instrument.");
    }

    else
    {
        ui->del_inst_button->setEnabled(false);
        ui->statusbar->setText("No valid file/folder selected. ("+path+")");
    }

}

void MainWindow::on_ChordTree_clicked(QModelIndex index)
{
    QString path = "";
    QModelIndex i(index);

    while (i.parent().data().toString() != "Chords")
    {
        path = i.parent().data().toString() + "/" + path;
        i = i.parent();
    }

    chord_dir = QDir(QDir::homePath()+"/Library/SmartGuitarChords/Chords/"+path+index.data().toString());

    if (chord_dir.exists())
    {
        if (chord_dir.count() > 2)
            ui->del_chord_button->setEnabled(false);

        else
            ui->del_chord_button->setEnabled(true);

        ui->statusbar->setText("\"" + index.data().toString() + "\" is a folder containing "+QString::number(chord_dir.count()-2)+" chord(s).");
    }

    else if (chord_dir.exists(chord_dir.absolutePath()))
    {
        ui->del_chord_button->setEnabled(true);

        loadChords(chord_dir.absolutePath().toStdString(), current_chord);
        printInstInfo();
        printChordInfo();

        ui->statusbar->setText(index.data().toString() + " is a valid chord.");
    }

    else
    {
        ui->del_inst_button->setEnabled(false);
        ui->statusbar->setText("No valid file/folder selected.");
    }



/*

    QString path = "";
    QModelIndex i(index);

    while (i.parent().data().toString() != "Chords")
    {
        path = path + i.parent().data().toString() + "/";
        i = i.parent();
    }

    chord_dir = QDir(QDir::homePath()+"/Library/SmartGuitarChords/Chords/"+path+index.data().toString());

    if (chord_dir.exists())
    {
        ui->del_chord_button->setEnabled(false);
        ui->statusbar->setText("\"" + index.data().toString() + "\" is a folder.");
    }

    else if (chord_dir.exists(chord_dir.absolutePath()))
    {
        ui->del_chord_button->setEnabled(true);

        loadChords(chord_dir.absolutePath().toStdString(), current_chord);
        printInstInfo();
        printChordInfo();

        ui->statusbar->setText(index.data().toString() + " is a valid file.");
    }

    else
    {
        ui->del_chord_button->setEnabled(false);
        ui->statusbar->setText("No valid file/folder selected.");
    }

    */
}

void MainWindow::printInstInfo()
{
    vector <int> tuning = current_inst.getTuning();

    QString tuningStr;

    for (unsigned int i=0; i<tuning.size(); i++)
    {
        tuningStr.append(QString::fromStdString(tuningIntToStr(tuning[i], 'b')));
        tuningStr.append(" ");
    }

    ui->inst_name_field->setText(QString::fromStdString(current_inst.getName()));
    ui->inst_tuning_field->setText(tuningStr);
    ui->inst_numstrings_field->setText(QString::number(current_inst.getNumStrings()));
}

void MainWindow::printChordInfo()
{
    if (current_chord.isValid() == 0)
    {
        ui->chord_name_field->setText("");
        ui->chord_tab_field->setText("");
        ui->chord_capo_field->setText("");
        ui->chord_relcapo_checkbox->setChecked(false);

        return;
    }

    vector <string> tab = current_chord.getTab();

    QString tabStr;

    for (unsigned int i=0; i<tab.size(); i++)
    {
        tabStr.append(QString::fromStdString(tab[i]));
        tabStr.append(" ");
    }

    ui->chord_name_field->setText(QString::fromStdString(current_chord.getName()));
    ui->chord_tab_field->setText(tabStr);
    ui->chord_capo_field->setText(QString::number(current_chord.getCapo()));
    ui->chord_relcapo_checkbox->setChecked(current_chord.isRelativeCapo());
}


void MainWindow::on_inst_folder_button_clicked()
{
    bool success = false;

    QDir parent = inst_dir;

    if (!parent.exists())
        parent.cdUp();

    if (ui->inst_folder_name->text() != "" &&
        !parent.exists(ui->inst_folder_name->text()))
     {
        success = parent.mkdir( ui->inst_folder_name->text() );

        if (success)
        {
            ui->statusbar->setText("Saved folder " + ui->inst_folder_name->text() + " in Instruments.");
            ui->inst_folder_name->setText("");
        }

        else
            ui->statusbar->setText("Failed to save folder.");
     }
}

void MainWindow::on_chord_folder_button_clicked()
{
    bool success = false;

    QDir parent = chord_dir;

    if (!parent.exists())
        parent.cdUp();

    if (ui->chord_folder_name->text() != "" &&
        !parent.exists(ui->chord_folder_name->text()))
     {
        success = parent.mkdir( ui->chord_folder_name->text() );

        if (success)
        {
            ui->statusbar->setText("Saved folder " + ui->chord_folder_name->text() + " in Chords.");
            ui->chord_folder_name->setText("");
        }

        else
            ui->statusbar->setText("Failed to save folder.");
     }
}

void MainWindow::on_del_inst_button_clicked()
{
    bool success = false;

    if (inst_dir.exists() && inst_dir.count() <= 2)
    {
        success = inst_dir.rmdir(inst_dir.absolutePath());

        if (success)
            ui->statusbar->setText("Successfully deleted folder.");
        else
            ui->statusbar->setText("Folder deletion failed!");

        return;
    }

    if (QMessageBox::question(this,
                              tr("Delete file?"),
                              tr("Are you sure you want to delete this file? This cannot be undone."),
                              QMessageBox::Yes,
                              QMessageBox::No,
                              QMessageBox::NoButton) == QMessageBox::Yes)
    {
        success = inst_dir.remove(inst_dir.absolutePath());
    }

    if (success)
        ui->statusbar->setText("Successfully deleted file.");
    else
        ui->statusbar->setText("File deletion failed!");
}


void MainWindow::on_del_chord_button_clicked()
{
    bool success = false;

    if (chord_dir.exists() && chord_dir.count() <= 2)
    {
        success = chord_dir.rmdir(chord_dir.absolutePath());

        if (success)
            ui->statusbar->setText("Successfully deleted folder.");
        else
            ui->statusbar->setText("Folder deletion failed!");

        return;
    }

    if (QMessageBox::question(this,
                              tr("Delete file?"),
                              tr("Are you sure you want to delete this file? This cannot be undone."),
                              QMessageBox::Yes,
                              QMessageBox::No,
                              QMessageBox::NoButton) == QMessageBox::Yes)
    {
        success = chord_dir.remove(chord_dir.absolutePath());
    }

    if (success)
        ui->statusbar->setText("Successfully deleted file.");
    else
        ui->statusbar->setText("File deletion failed!");
}

void MainWindow::on_inst_save_button_clicked()
{
    string name = ui->inst_name_field->text().toStdString();
    int numstrings = ui->inst_numstrings_field->text().toInt();
    string tuning = ui->inst_tuning_field->text().toStdString();
    vector <string> tuningVec;

    if (name.length() <= 0)
    {
        ui->statusbar->setText("FAILED: The Name field is empty.");
        return;
    }

    unsigned int i = 0;

    while (i < tuning.length())
    {
        if (tuning[i] == ' ' && i == tuning.length()-1)
            break;

        if (tuning[i] == ' ')
            tuningVec.push_back("");

        else if (i == 0)
        {
            tuningVec.push_back("");
            tuningVec[0] += tuning[i];
        }

        else
            tuningVec[tuningVec.size()-1] += tuning[i];

        i++;
    }

    tuning = "";

    for (i=0; i<tuningVec.size(); i++)
    {
        tuning += QString::number(tuningStrToInt(tuningVec[i])).toStdString();
        tuning += " ";
    }

    string current_dir = inst_dir.dirName().toStdString();
    bool is_dir = inst_dir.exists();

    inst_dir.cdUp();

    string path = inst_dir.absolutePath().toStdString();

    if (is_dir)
    {
        path += "/";
        path += current_dir;
    }

    path += "/";
    path += name;
    path += ".txt";

    ofstream outfile;
    outfile.open(path.c_str());

    outfile<<"0 \""<<name<<"\" "<<numstrings<<" { "<<tuning<<"}\n";

    outfile.close();

    inst_dir.cd(QString::fromStdString(current_dir));

    ui->statusbar->setText("Successfully saved instrument \""+QString::fromStdString(name)+"\".");
}

void MainWindow::on_chord_save_button_clicked()
{
    if (current_inst.getName() == "" && current_inst.getNumStrings() == 0)
    {
        ui->statusbar->setText("FAILED: Please select an instrument to create your chord on.");
        return;
    }

    string name = ui->chord_name_field->text().toStdString();
    string tab_temp = ui->chord_tab_field->text().toStdString();
    int capo = ui->chord_capo_field->text().toInt();
    bool relcapo = ui->chord_relcapo_checkbox->isChecked();

    if (name.length() <= 0)
    {
        ui->statusbar->setText("FAILED: The Name field is empty.");
        return;
    }

    string inst_name = current_inst.getName();

    string tab;

    for (unsigned int i=0; i<tab_temp.size(); i++)
    {
        if (tab_temp[i] != ' ')
            tab += tab_temp[i];

        else
            tab += " ";
    }

    string current_dir = chord_dir.dirName().toStdString();
    bool is_dir = chord_dir.exists();

    chord_dir.cdUp();

    string path = chord_dir.absolutePath().toStdString();

    if (is_dir)
    {
        path += "/";
        path += current_dir;
    }

    path += "/";
    path += name;
    path += ".txt";

    ofstream outfile;
    outfile.open(path.c_str());

    outfile<<"0 \""<<name<<"\" \""<<inst_name<<"\" "<<capo<<" "<<relcapo<<" { "<<tab<<" }\n";

    outfile.close();

    chord_dir.cd(QString::fromStdString(current_dir));

    ui->statusbar->setText("Successfully saved chord \""+QString::fromStdString(name)+"\".");
}

void MainWindow::on_inst_create_button_clicked()
{
    enableInstForm();
    wipeInstForm();

    ui->inst_cancel_button->setText("Cancel");
}

void MainWindow::on_chord_create_button_clicked()
{
    enableChordForm();
    wipeChordForm();

    ui->chord_cancel_button->setText("Cancel");
}

void MainWindow::enableInstForm()
{
    ui->inst_name_field->setEnabled(true);
    ui->inst_tuning_field->setEnabled(true);
    ui->inst_numstrings_field->setEnabled(true);

    ui->inst_save_button->setEnabled(true);
}

void MainWindow::disableInstForm()
{
    ui->inst_name_field->setEnabled(false);
    ui->inst_tuning_field->setEnabled(false);
    ui->inst_numstrings_field->setEnabled(false);

    ui->inst_save_button->setEnabled(false);
}

void MainWindow::enableChordForm()
{
    ui->chord_name_field->setEnabled(true);
    ui->chord_tab_field->setEnabled(true);
    ui->chord_capo_field->setEnabled(true);
    ui->chord_relcapo_checkbox->setEnabled(true);

    ui->chord_save_button->setEnabled(true);
}

void MainWindow::disableChordForm()
{
    ui->chord_name_field->setEnabled(false);
    ui->chord_tab_field->setEnabled(false);
    ui->chord_capo_field->setEnabled(false);
    ui->chord_relcapo_checkbox->setEnabled(false);

    ui->chord_save_button->setEnabled(false);
}

void MainWindow::wipeInstForm()
{
    ui->inst_name_field->setText("");
    ui->inst_tuning_field->setText("");
    ui->inst_numstrings_field->setText("");
}

void MainWindow::wipeChordForm()
{
    ui->chord_name_field->setText("");
    ui->chord_tab_field->setText("");
    ui->chord_capo_field->setText("");
    ui->chord_relcapo_checkbox->setText("");
}

string MainWindow::findInst(string search, QDir d)
{
    QStringList files = d.entryList(QStringList(QString::fromStdString(search)),
                                    QDir::Files | QDir::NoSymLinks);

    for (int i=0; i<files.size(); i++)
    {
        if (files[i] == QString::fromStdString(search))
        {
            return (search + ".txt");
        }
    }

    for (int i=0; i<files.size(); i++)
    {
        d.cd(files[i]);

        if (d.exists())
        {
            string result = findInst(search, d);

            if (result != "")
                return d.absolutePath().toStdString()+"/"+result;
        }

        d.cdUp();
    }

    return "";
}

void MainWindow::on_inst_cancel_button_clicked()
{
    if (ui->inst_cancel_button->text() == "Edit Instrument")
    {
        ui->inst_cancel_button->setText("Cancel");
        enableInstForm();
    }

    else if (ui->inst_cancel_button->text() == "Cancel")
    {
        ui->inst_cancel_button->setText("Edit Instrument");
        disableInstForm();
    }
}

void MainWindow::on_chord_cancel_button_clicked()
{
    if (ui->chord_cancel_button->text() == "Edit Chord")
    {
        ui->chord_cancel_button->setText("Cancel");
        enableChordForm();
    }

    else if (ui->chord_cancel_button->text() == "Cancel")
    {
        ui->chord_cancel_button->setText("Edit Chord");
        disableChordForm();
    }
}
