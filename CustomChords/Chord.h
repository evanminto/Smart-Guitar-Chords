#ifndef CHORD_H
#define CHORD_H

#include "Note.h"
#include "Instrument.h"
#include <vector>
#include <string>
#include <fstream>
#include <QString>
#include <iostream>

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

    Instrument * getInstrumentPtr() const { return inst; }

public:
    Chord();
    Chord(Chord const &c);
    Chord(Instrument *i, std::string const& s, std::vector <std::string> const& t);
    Chord(Instrument *i, std::string const& s, std::vector <std::string> const& t, int const& c);
    Chord(Instrument *i, std::string const& s, std::vector <std::string> const& t, int const& c, bool const& rel);

    std::string getName() const { return name; }
    Instrument getInstrument() const { return *inst; }
    bool isInstrumentSet() const { return (inst != NULL); }
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

    bool isValid() const { return valid; }

    void setID(int i) { id = i; }
    void putName(std::string s) { name = s; };
    void putInstrument(Instrument *i) { inst = i; };
    void invalidate() { valid = false; }
    void updateTab(std::vector <std::string> t);

    Chord& operator=(Chord const &c);
};

std::vector <QString> autoComplete(Instrument const& inst, int const& capo, QString const& qinput);
Note extractBassNote(std::vector <Note> const& notes);
std::vector <int> extractPattern(std::vector <Note> const& notes);
std::vector <Note> extractNotes(Instrument const& inst, std::string tab_str, int capo);
std::vector <Note> constructNotes(Instrument const& inst, Note const& bassNote, std::vector <int> const& pattern);
std::vector <int> constructTab(Instrument const& inst, std::vector <Note> const& notes);
std::string constructTabStr(Instrument const& inst, std::vector <Note> const& notes);
int constructFret(int const& tuning, Note const& note);

#endif // CHORD_H
