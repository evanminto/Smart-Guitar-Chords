#include "Chord.h"

void Chord::regenerateNotes()
{
    notes.clear();
    Note temp;

    for (int i=0; i<inst->getNumStrings(); i++)
    {
        if (tab[i] == "x")
            temp.invalidate();
        else
            temp.set(inst->getTuning()[i], capo, atoi(tab[i].c_str()));
        notes.push_back(temp);
    }
}

void Chord::calculateInfo()
{
    /*
        Note bassNote;
        Note namedNote;
        string modifier;
         */

    int minimum_note = 1000;

    for (int i=0; i<notes.size(); i++)
    {
        if (notes[i].isValid() && notes[i].getAbsPitch() < minimum_note)
        {
            minimum_note = notes[i].getAbsPitch();
            break;
        }
    }

    Note temp(minimum_note);
    bassNote = temp;

    for (int i=0; i<notes.size(); i++)
    {
        int newNote;

        if (!notes[i].isValid())
            newNote = -1;

        else if (notes[i].getRelPitch() < bassNote.getRelPitch())
            newNote = bassNote.getRelPitch() - notes[i].getRelPitch();

        else
            newNote = (12 - (notes[i].getRelPitch() - bassNote.getRelPitch())) %  12;

        pattern.push_back(newNote);
    }
}


Chord::Chord()
{
    name = "New Chord";
    capo = 0;
}

Chord::Chord(Chord const &c)
{
    name = c.getName();
    inst = &c.getInstrument();
    capo = c.getCapo();
    tab = c.getTab();
    notes = c.getNotes();
    relative = c.isRelativeCapo();

    bassNote = c.getBassNote();
    namedNote = c.getNamedNote();
    pattern = c.getPattern();
    modifier = c.getModifier();

    id = c.getID();

    valid = true;
}

Chord::Chord(Instrument *i, std::string s, std::vector <std::string> t)
{
    inst = i;
    name = s;
    tab = t;
    capo = 0;
    relative = true;

    regenerateNotes();
    calculateInfo();

    valid = true;
}

Chord::Chord(Instrument *i, std::string s, std::vector <std::string> t, int c)
{
    inst = i;
    name = s;
    tab = t;
    capo = c;
    relative = true;

    regenerateNotes();
    calculateInfo();

    valid = true;
}

Chord::Chord(Instrument *i, std::string s, std::vector <std::string> t, int c, bool rel)
{
    inst = i;
    name = s;
    tab = t;
    capo = c;
    relative = rel;

    regenerateNotes();
    calculateInfo();

    valid = true;
}


void Chord::updateTab(std::vector <std::string> t)
{
    tab = t;

    regenerateNotes();
    calculateInfo();
}


std::ostream& operator<<(std::ostream& output, const Chord& c)
{
    output<<c.getName()<<std::endl;

    output<<" - Instrument: "<<c.getInstrument().getName()<<std::endl;
    output<<" - Capo "<<c.getCapo();

    if (c.isRelativeCapo())
        output<<" (relative)";

    output<<std::endl;
    output<<" - Tab: ";

    for (int i=0; i<c.getTab().size(); i++)
    {
        output<<c.getTab()[i]<<" ";
    }
    output<<std::endl;

    output<<" - Key of "<<c.getBassNote().getName()<<": ";

    for (int i=0; i<c.getPattern().size(); i++)
    {
        if (c.getPattern()[i] == -1)
            output<<"x ";

        else
            output<<c.getPattern()[i]<<" ";
    }
    output<<std::endl;

    return output;

    /*
        output<<c.getBassNote().getName()<<": ";

        for (int i=0; i<c.getPattern().size(); i++)
        {
                if (c.getPattern()[i] == -1)
                        output<<"x ";

                else
                        output<<c.getPattern()[i]<<" ";
        }
        output<<endl;
         */

    /*
        if (c.relative)
        {
                for (int i=0; i<c.tab.size(); i++)
                        output<<c.tab[i]<<" ";

                output<<"(Capo "<<c.capo<<")"<<endl;
        }
        else
        {
                for (int i=0; i<c.tab.size(); i++)
                        output<<(atoi(c.tab[i].c_str())+c.capo)<<" ";

                output<<endl;
        }

         return output;
         */
}

Chord& Chord::operator=(Chord const &c)
{
    name = c.getName();
    inst = &c.getInstrument();
    capo = c.getCapo();
    tab = c.getTab();
    notes = c.getNotes();
    relative = c.isRelativeCapo();

    bassNote = c.getBassNote();
    namedNote = c.getNamedNote();
    pattern = c.getPattern();
    modifier = c.getModifier();

    id = c.getID();

    valid = true;

    return *this;
}
