#include "Note.h"

void Note::generateName()
{
    switch (relPitch) {
    case 0:
        setName("C");
        break;
    case 1:
        setName("Db", "C#");
        break;
    case 2:
        setName("D");
        break;
    case 3:
        setName("Eb", "D#");
        break;
    case 4:
        setName("E");
        break;
    case 5:
        setName("F");
        break;
    case 6:
        setName("Gb", "F#");
        break;
    case 7:
        setName("G");
        break;
    case 8:
        setName("Ab", "G#");
        break;
    case 9:
        setName("A");
        break;
    case 10:
        setName("Bb", "A#");
        break;
    case 11:
        setName("B");
        break;
    default:
        break;
    }
}

Note::Note()
{
    absPitch = 0;
    relPitch = 0;
    octave = 0;

    valid = false;
}

Note::Note(int t, int c, int f)
{
    set(t, c, f);
}

Note::Note(int newPitch)
{
    absPitch = newPitch;
    relPitch = absPitch % 12;
    octave = absPitch / 12;

    generateName();

    valid = true;
}


int Note::encodeAbsPitch(int t, int c, int f)
{
    return t + c + f;
}

void Note::set(int t, int c, int f)
{
    absPitch = encodeAbsPitch(t, c, f);
    relPitch = absPitch % 12;
    octave = absPitch / 12;

    generateName();

    valid = true;
}

void Note::setName(std::string n)
{
    name = n;
}

void Note::setName(std::string n1, std::string n2)
{
    name = n1;
    altName = n2;
}

void Note::invalidate()
{
    valid = false;
}

bool Note::isValid()
{
    return valid;
}

std::ostream& operator<<(std::ostream& output, const Note& n)
{
    output<<n.getName();

    return output;
}
