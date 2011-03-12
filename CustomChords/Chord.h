#ifndef CHORD_H
#define CHORD_H

#include "Note.h"
#include "Instrument.h"
#include <vector>
#include <string>
#include <fstream>

class Chord
{
    friend std::ostream& operator<<(std::ostream& output, const Chord& c);

private:
    std::string name;
    Instrument *inst;
    int capo;
    std::vector <std::string> tab;
    std::vector <Note> notes;
    bool relative;

    Note bassNote;
    Note namedNote;
    std::vector <int> pattern;
    std::string modifier;

    int id;

    void regenerateNotes();
    void calculateInfo();

    bool valid;

public:
    Chord();
    Chord(Chord const &c);
    Chord(Instrument *i, std::string s, std::vector <std::string> t);
    Chord(Instrument *i, std::string s, std::vector <std::string> t, int c);
    Chord(Instrument *i, std::string s, std::vector <std::string> t, int c, bool rel);

    std::string getName() const { return name; }
    Instrument getInstrument() const { return *inst; }
    int getCapo() const { return capo; }
    std::vector <std::string> getTab() const { return tab; }
    std::vector <Note> getNotes() const { return notes; }
    int getNumStrings() const { return inst->getNumStrings(); }
    int isRelativeCapo() const { return relative; }

    Note getBassNote() const { return bassNote; }
    Note getNamedNote() const { return namedNote; }
    std::vector <int> getPattern() const { return pattern; }
    std::string getModifier() const { return modifier; }

    int getID() const { return id; }

    int isValid() const { return valid; }

    void setID(int i) { id = i; }
    void putName(std::string s) { name = s; };
    void putInstrument(Instrument *i) { inst = i; };
    void invalidate() { valid = false; }
    void updateTab(std::vector <std::string> t);

    Chord& operator=(Chord const &c);
};

#endif // CHORD_H
