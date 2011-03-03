#ifndef CHORDDATABASE_H
#define CHORDDATABASE_H

#include "CustomGuitarChords.h"
#include "functions.h"
#include "InstrumentDatabase.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class ChordDatabase
{
private:
    std::vector <Chord> table;
    std::string dbFile;

    InstrumentDatabase *instruments;

    bool valid;

    void reload();
    int getIndex(int id);

public:
    ChordDatabase();
    ChordDatabase(std::string filename, InstrumentDatabase *idb);

    std::vector <Chord> getTable() const { return table; }
    std::string getFile() const { return dbFile; }
    bool isValid() const { return valid; }

    std::ostream& printAll(std::ostream &output) const;

    void setFile(std::string filename);
    void setInstrumentDB(InstrumentDatabase *idb);
    void add(Chord c);
    void remove(int id);

    void commitChanges();

    Chord& operator[](std::string s);
    Chord& operator[](int id);
};

#endif // CHORDDATABASE_H
