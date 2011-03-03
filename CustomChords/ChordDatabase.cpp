/*
 *  ChordDatabase.cpp
 *  Smart-Guitar-Chords_test
 *
 *  Created by Evan Minto on 2/25/11.
 *  Copyright 2011 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CHORD_DATABASE_CPP
#define CHORD_DATABASE_CPP

#include "ChordDatabase.h"

void ChordDatabase::reload()
{
    std::string inst_name, chord_name, temp;
    std::vector <std::string> tab;
    int capo_num = 0;
    bool rel_capo;
    int id = 0;

    int strings_num;

    std::ifstream infile;
    infile.open(dbFile.c_str());

    while (!infile.eof())
    {
        infile>>id>>temp;

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

        strings_num = instruments->find(inst_name)->getNumStrings();

        // GET CAPO AND RELATIVITY

        infile>>capo_num>>temp;

        if (temp == "1")	rel_capo = true;
        else			rel_capo = false;

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

        Chord c(instruments->find(inst_name), chord_name, tab, capo_num, rel_capo);
        c.setID(id);
        if (chord_name != "") table.push_back(c);

        tab.clear();
        inst_name = chord_name = temp = "";
        capo_num = 0;
        rel_capo = false;
    }

    infile.close();

    valid = true;
}

int ChordDatabase::getIndex(int id)
{
    for (int i=0; i<table.size(); i++)
    {
        if (table[i].getID() == id)
            return i;
    }

    return -1;
}


ChordDatabase::ChordDatabase()
{
    valid = false;
}

ChordDatabase::ChordDatabase(std::string filename, InstrumentDatabase *idb)
{
    setFile(filename);
    setInstrumentDB(idb);
    reload();
}


std::ostream& ChordDatabase::printAll(std::ostream &output) const
{
    for (int i=0; i<table.size(); i++)
    {
        output<<table[i];
        output<<std::endl;
    }

    return output;
}


void ChordDatabase::setFile(std::string filename)
{
    dbFile = filename;
    valid = false;
}

void ChordDatabase::setInstrumentDB(InstrumentDatabase *idb)
{
    instruments = idb;
}

void ChordDatabase::add(Chord c)
{
    c.setID(table[table.size()-1].getID()+1);
    table.push_back(c);
}

void ChordDatabase::remove(int id)
{
    table.erase(table.begin()+getIndex(id));
}


void ChordDatabase::commitChanges()
{
    std::string print_str;

    std::ofstream outfile;
    outfile.open(dbFile.c_str());

    for (int i=0; i<table.size(); i++)
    {
        outfile << table[i].getID() << " ";
        outfile << "\"" << table[i].getName() << "\" ";
        outfile << "\"" << table[i].getInstrument().getName() << "\" ";

        outfile << table[i].getCapo();
        outfile << " " << table[i].isRelativeCapo();

        outfile << " { ";

        for (int j=0; j<table[i].getTab().size(); j++)
            outfile << table[i].getTab()[j] << " ";

        outfile << "} ";

        outfile << std::endl;
        print_str = "";
    }

    outfile.close();
}

Chord& ChordDatabase::operator[](std::string s)
{
    for (int i=0; i<table.size(); i++)
    {
        if (table[i].getName() == s)
            return table[i];
    }
}

Chord& ChordDatabase::operator[](int id)
{
    for (int i=0; i<table.size(); i++)
    {
        if (table[i].getID() == id)
            return table[i];
    }
}

#endif
