#ifndef NOTE_H
#define NOTE_H

#include <string>

class Note
{
private:
    int absPitch;
    int relPitch;
    int octave;

    std::string name;
    std::string altName;

    bool valid;

    void generateName();

public:
    Note();
    Note(int t, int c, int f);
    Note(int newPitch);

    int getAbsPitch() { return absPitch; }
    int getRelPitch() { return relPitch; }
    int getOctave() { return octave; }
    std::string getName() const { return name; }

    int encodeAbsPitch(int t, int c, int f);
    void set(int t, int c, int f);
    void setName(std::string n);
    void setName(std::string n1, std::string n2);
    void invalidate();

    bool isValid();
};

#endif // NOTE_H
