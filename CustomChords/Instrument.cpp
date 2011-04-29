#include "Instrument.h"

Instrument::Instrument()
{
    name = "";
    numStrings = 0;
}

Instrument::Instrument(Instrument const &i)
{
    name = i.getName();
    numStrings = i.getNumStrings();
    tuning = i.getTuning();

    id = i.getID();
}

Instrument::Instrument(std::string s, int n, std::vector <int> t)
{
    name = s;
    numStrings = n;
    tuning = t;
}

// NON-CLASS METHODS

std::ostream& operator<<(std::ostream& output, const Instrument& inst)
{
    output<<inst.getName()<<std::endl;

    output<<" - "<<inst.getNumStrings()<<" strings"<<std::endl;
    output<<" - Tuning: ";

    for (int i=0; i<inst.getTuning().size(); i++)
    {
        output<<tuningIntToStr(inst.getTuning()[i], '#')<<" ";
    }
    output<<std::endl;

    return output;
}

int tuningStrToInt(std::string t, int octave)
{
    int num;

    if (static_cast<int>(t[0]) >= 65 && static_cast<int>(t[0]) <= 71)
    {
        num = (int)t[0] - 67;

        switch (num) {
        case -2:
            num = -3;
            break;
        case 1:
            num = 2;
            break;
        case 2:
            num = 4;
            break;
        case 3:
            num = 5;
            break;
        case 4:
            num = 7;
            break;
        default:
            break;
        }

        if (num < 0)
            num += 12;

        if (t[1] == 'b')
            num--;

        else if (t[1] == '#')
            num++;
    }

    return num + 12*octave;
}

std::string tuningIntToStr(int t, char sharp_flat)
{
    while (t<0)
        t += 12;

    t %= 12;

    switch (t) {
    case 9:
        return "A";
        break;
    case 10:
        if (sharp_flat == '#')
            return "A#";
        else if (sharp_flat == 'b')
            return "Bb";
        break;
    case 11:
        return "B";
        break;
    case 0:
        return "C";
        break;
    case 1:
        if (sharp_flat == '#')
            return "C#";
        else if (sharp_flat == 'b')
            return "Db";
        break;
    case 2:
        return "D";
        break;
    case 3:
        if (sharp_flat == '#')
            return "D#";
        else if (sharp_flat == 'b')
            return "Eb";
        break;
    case 4:
        return "E";
        break;
    case 5:
        return "F";
        break;
    case 6:
        if (sharp_flat == '#')
            return "F#";
        else if (sharp_flat == 'b')
            return "Gb";
        break;
    case 7:
        return "G";
        break;
    case 8:
        if (sharp_flat == '#')
            return "G#";
        else if (sharp_flat == 'b')
            return "Ab";
        break;
    default:
        break;
    }

    return "";
}

Instrument& Instrument::operator=(Instrument const &i)
{
    name = i.getName();
    numStrings = i.getNumStrings();
    tuning = i.getTuning();

    id = i.getID();

    return *this;
}
