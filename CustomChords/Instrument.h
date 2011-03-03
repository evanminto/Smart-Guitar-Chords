#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <string>
#include <vector>
#include <fstream>

class Instrument
{
    friend std::ostream& operator<<(std::ostream& output, const Instrument& inst);

private:
    std::string name;
    int numStrings;
    std::vector <int> tuning;

    int id;

public:
    Instrument();
    Instrument(std::string s, int n, std::vector <int> t);

    std::string getName() const { return name; }
    int getNumStrings() const { return numStrings; }
    std::vector <int> getTuning() const { return tuning; }
    int getID() const { return id; }

    void setID(int i) { id = i; }

};

int tuningStrToInt(std::string t);
std::string tuningIntToStr(int t, char sharp_flat);

#endif // INSTRUMENT_H
