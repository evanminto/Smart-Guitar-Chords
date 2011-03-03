#include "InstrumentDatabase.h"

void InstrumentDatabase::reload()
{
    std::string inst_name, temp;
    std::vector <int> tuning;
    int strings_num = 0;
    int id = 0;

    std::ifstream infile;
    infile.open(dbFile.c_str());

    while (!infile.eof())
    {
        infile>>id>>temp;

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

        infile>>strings_num;

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

        Instrument i(inst_name, strings_num, tuning);
        i.setID(id);
        if (inst_name != "") table.push_back(i);

        tuning.clear();
        inst_name = "";
        strings_num = 0;
    }

    infile.close();

    valid = true;
}

int InstrumentDatabase::getIndex(int id)
{
    for (int i=0; i<table.size(); i++)
    {
        if (table[i].getID() == id)
            return i;
    }

    return -1;
}


InstrumentDatabase::InstrumentDatabase()
{
    valid = false;
}

InstrumentDatabase::InstrumentDatabase(std::string filename)
{
    setFile(filename);
    reload();
}


std::ostream& InstrumentDatabase::printAll(std::ostream &output) const
{
    for (int i=0; i<table.size(); i++)
    {
        output<<table[i];
        output<<std::endl;
    }

    return output;
}

void InstrumentDatabase::setFile(std::string filename)
{
    dbFile = filename;
    valid = false;
}

void InstrumentDatabase::add(Instrument i)
{
    i.setID(table[table.size()-1].getID()+1);
    table.push_back(i);
}

void InstrumentDatabase::remove(int id)
{
    table.erase(table.begin()+getIndex(id));
}


void InstrumentDatabase::commitChanges()
{
    std::string print_str;

    std::ofstream outfile;
    outfile.open(dbFile.c_str());

    for (int i=0; i<table.size(); i++)
    {
        outfile << table[i].getID() << " ";
        outfile << "\"" + table[i].getName() + "\" ";
        outfile << table[i].getNumStrings();
        outfile << " { ";

        for (int j=0; j<table[i].getTuning().size(); j++)
        {
            outfile << table[i].getTuning()[j];
            outfile << " ";
        }

        outfile << "}"<<std::endl;
    }

    outfile.close();
}

Instrument* InstrumentDatabase::find(std::string s)
{
    for (int i=0; i<table.size(); i++)
    {
        if (table[i].getName() == s)
            return &table[i];
    }

    Instrument *empty_inst = new Instrument;
    return empty_inst;
}

Instrument& InstrumentDatabase::operator[](std::string s)
{
    for (int i=0; i<table.size(); i++)
    {
        if (table[i].getName() == s)
            return table[i];
    }
}

Instrument& InstrumentDatabase::operator[](int id)
{
    for (int i=0; i<table.size(); i++)
    {
        if (table[i].getID() == id)
            return table[i];
    }
}
