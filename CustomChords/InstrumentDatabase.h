#ifndef INSTRUMENTDATABASE_H
#define INSTRUMENTDATABASE_H

#include "CustomGuitarChords.h"
#include "functions.h"
#include "InstrumentDatabase.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class InstrumentDatabase
{
private:
    std::vector <Instrument> table;
    std::string dbFile;

    bool valid;

    void reload();
    int getIndex(int id);

public:
    InstrumentDatabase();
    InstrumentDatabase(std::string filename);

    std::vector <Instrument> getTable() const { return table; }
    std::string getFile() const { return dbFile; }
    bool isValid() const { return valid; }

    std::ostream& printAll(std::ostream &output) const;

    void setFile(std::string filename);
    void add(Instrument i);
    void remove(int id);

    void commitChanges();

    Instrument* find(std::string s);
    Instrument& operator[](std::string s);
    Instrument& operator[](int id);
};

#endif // INSTRUMENTDATABASE_H
