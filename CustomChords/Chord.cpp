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
    name = "";
    capo = 0;
    relative = false;
    valid = false;
    inst = NULL;
}

Chord::Chord(Chord const &c)
{
    name = c.getName();
    inst = c.getInstrumentPtr();
    capo = c.getCapo();
    tab = c.getTab();
    notes = c.getNotes();
    relative = c.isRelativeCapo();

    bassNote = c.getBassNote();
    namedNote = c.getNamedNote();
    pattern = c.getPattern();
    modifier = c.getModifier();

    id = c.getID();

    valid = c.isValid();
}

Chord::Chord(Instrument *i, std::string const& s, std::vector <std::string> const& t)
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

Chord::Chord(Instrument *i, std::string const& s, std::vector <std::string> const& t, int const& c)
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

Chord::Chord(Instrument *i, std::string const& s, std::vector <std::string> const& t, int const& c, bool const& rel)
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
    inst = c.getInstrumentPtr();
    capo = c.getCapo();
    tab = c.getTab();
    notes = c.getNotes();
    relative = c.isRelativeCapo();

    bassNote = c.getBassNote();
    namedNote = c.getNamedNote();
    pattern = c.getPattern();
    modifier = c.getModifier();

    id = c.getID();

    valid = c.isValid();

    return *this;
}



void removeDuplicates(std::vector<QString>& vec)
{

   std::sort(vec.begin(), vec.end());
   vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

std::vector <QString> autoComplete(Instrument const& inst, int const& capo, QString const& qinput)
{
    if ( qinput.size() == 0 )
    {
        std::vector <QString> result;
        return result;
    }

    std::vector <Note> notes = extractNotes( inst, qinput.toStdString(), capo );

    Note bass_note_orig = extractBassNote(notes);
    std::vector <int> pattern = extractPattern(notes);

    std::vector <QString> result;

    QString temp;
    Note bass_note;

    int center_fret = extractCenter(notes, inst);

    std::vector < std::vector <int> > suggestions = autofillPattern(pattern);

    for ( int i=0; i<suggestions.size(); i++ )
    {
        notes = constructNotes(inst, bass_note_orig, suggestions[i], center_fret);
        temp = QString::fromStdString( constructTabStr(inst, notes) );
        result.push_back(temp);
    }

    removeDuplicates(result);

    return result;
}

int extractCenter(std::vector <Note> notes, Instrument const& inst)
{
    int center_fret = 0;
    int num_fretted = 0;

    for ( int i=0; i<notes.size(); i++ )
    {
        if ( notes[i].getAbsPitch() < 500 &&
             notes[i].getAbsPitch() - inst.getTuning()[i] > 0 )
        {
            center_fret += (notes[i].getAbsPitch() - inst.getTuning()[i]);
            num_fretted++;
        }
    }

    std::cout<<"findCenter: "<<(center_fret/num_fretted)<<std::endl;

    return (center_fret / num_fretted);
}

std::vector <int> extractPatternList(std::vector <int> pattern)
{
    std::vector <int> result;

    std::cout<<"extractPatternList: ";

    for ( int i=0; i<pattern.size(); i++ )
    {
        bool found = false;
        for ( int j=0; j<result.size(); j++ )
        {
            if (pattern[i] == result[j])
                found = true;
        }

        if (!found && pattern[i] < 500)
        {
            std::cout<<pattern[i]<<" ";
            result.push_back(pattern[i]);
        }
    }

    std::cout<<std::endl;

    return result;
}

std::vector < std::vector <int> > autofillPattern(std::vector <int> pattern)
{
    std::vector <int> plist = extractPatternList(pattern);

    return autofillPatternRecursive(pattern, plist);
}

std::vector < std::vector <int> > autofillPatternRecursive(std::vector <int> pattern, std::vector <int> plist)
{
    for ( int k=0; k<pattern.size(); k++ )
        std::cout<<pattern[k]<<" ";
    std::cout<<"-- "<<plist.size()<<std::endl;

    std::vector < std::vector <int> > result;

    std::vector <int> temp;
    std::vector < std::vector <int> > temp_list;

    int num_xs = 0;

    for ( unsigned int i=0; i<pattern.size(); i++ )
    {
        if (pattern[i] > 500)
            num_xs++;
    }

    std::cout<<"num_xs: "<<num_xs<<std::endl;

    for ( int i=0; i<pattern.size(); i++ )
    {
        if ( pattern[i] > 500)
        {
            for ( int j=0; j<plist.size(); j++ )
            {
                temp = pattern;
                temp[i] = plist[j];

                result.push_back(temp);

                if (num_xs-1 > 0)
                {
                    //std::cout<<i<<" "<<j<<std::endl;
                    temp_list = autofillPatternRecursive(temp, plist);
                    result.insert( result.end(), temp_list.begin(), temp_list.end() );
                }
            }
        }
    }

    return result;
}

Note extractBassNote(std::vector <Note> const& notes)
{
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

    std::cout<<"extractBassNote: "<<temp.getAbsPitch()<<" (abs), "<<temp.getName()<<" (name)"<<std::endl;

    return temp;
}

std::vector <int> extractPattern(std::vector <Note> const& notes)
{
    std::vector <int> pattern;

    Note bassNote = extractBassNote(notes);

    std::cout<<"extractPattern: ";

    for (int i=0; i<notes.size(); i++)
    {
        int newNote;

        if (!notes[i].isValid())
            newNote = 1000;

        else
            newNote = abs( notes[i].getAbsPitch() - bassNote.getAbsPitch() ) %  12;


        pattern.push_back(newNote);

        std::cout<<newNote<<" ";
    }

    std::cout<<std::endl;

    return pattern;
}

std::vector <Note> extractNotes(Instrument const& inst, std::string tab_str, int capo)
{
    std::vector <std::string> tab;
    std::vector <Note> notes;

    char *temp;
    temp = (char *)calloc(5, 1);

    char *tokenized_str;
    tokenized_str = (char *)calloc(tab_str.length(), 1);
    strcpy(tokenized_str, tab_str.c_str());

    std::cout<<"extractNote: ";

    for (int i=0; i<inst.getTuning().size(); i++)
        std::cout<<inst.getTuning()[i]<<" ";

    std::cout<<"(tuning), ";

    temp = strtok( tokenized_str, " " );
    std::cout<<temp<<" ";
    tab.push_back( std::string(temp) );

    while ( ( temp = strtok( NULL, " " ) ) != NULL )
    {
        std::string str(temp);

        std::cout<<str<<" ";

        tab.push_back(str);
    }

    while ( tab.size() < inst.getNumStrings() )
        tab.push_back( "x" );

    std::cout<<"(tab), ";

    for (int i=0; i<inst.getNumStrings() && i<tab.size(); i++)
    {
        Note tn;

        if (tab[i] == "x")
            tn.invalidate();
        else
        {
            tn.set( inst.getTuning()[i], capo, atoi( tab[i].c_str() ) );
            /*
            std::cout<<"("<<inst.getTuning()[i]<<" + "<<capo<<" + "<<atoi( tab[i].c_str() )<<" = "
                     <<( inst.getTuning()[i] + capo + atoi( tab[i].c_str() ) )<<") ";
             */
        }

        std::cout<<tn.getAbsPitch()<<" ";

        notes.push_back(tn);
    }

    std::cout<<" (abs)"<<std::endl;

    return notes;
}

std::vector <Note> constructNotes(Instrument const& inst, Note const& bassNote, std::vector <int> const& pattern, int center_fret)
{
    // Find the string the bass note is played on
    int bass_note_str = 0;
    while (pattern[bass_note_str] >= 500) bass_note_str++;

    int bass_note_fret = bassNote.getAbsPitch() - inst.getTuning()[bass_note_str];

    std::vector <Note> result;

    for ( int i=0; i<pattern.size() && i<inst.getNumStrings(); i++ )
    {
        if (i < bass_note_str || pattern[i] >= 500) result.push_back(Note(1000));
        else if (i == bass_note_str) result.push_back(bassNote);

        else
        {
            for ( int j=center_fret-4; j<center_fret+4; j++ )
            {
                Note tn( inst.getTuning()[i] + j );

                if ( tn.getRelPitch() == bassNote.getRelPitch(pattern[i]) )
                {
                    result.push_back(tn);
                    break;
                }
            }
        }
    }

    /*
    for ( int i=0; i<result.size(); i++ )
        std::cout<<result[i].getAbsPitch()<<" ";

    std::cout<<" (abs)"<<std::endl;
    */

    return result;
}

std::vector <int> constructTab(Instrument const& inst, std::vector <Note> const& notes)
{
    std::vector <int> result;

    for (int i=0; i<inst.getNumStrings(); i++)
    {
        int fret = constructFret( inst.getTuning()[i], notes[i] );

        if (fret >= 0)
            result.push_back( fret );
    }

    return result;
}

std::string constructTabStr(Instrument const& inst, std::vector <Note> const& notes)
{
    std::vector <int> tab_int = constructTab(inst, notes);
    std::string result = "";

    for ( int i=0; i<tab_int.size(); i++ )
        result += ( tab_int[i] < 500 ? QString::number(tab_int[i]).toStdString() + " " : "x " );

    return result;
}

int constructFret(int const& tuning, Note const& note)
{
    return note.getAbsPitch() - tuning;
}

