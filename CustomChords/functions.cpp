#include "functions.h"

std::string trim(std::string str, char remove = '\n')
{
    while (str[0] == remove)
        str = str.substr(1, str.length()-1);

    while (str[str.length()-1] == remove)
        str = str.substr(0, str.length()-1);

    return str;
}

std::string trim(std::string str)
{
    return trim(str, ' ');
}

std::string tolower(std::string str)
{
    std::string result;

    for (int i=0; i<str.length(); i++)
        result += tolower(str[i]);

    return result;
}

void startup()
{
    QDir dir(QDir::homePath());
    dir.cd("Library");
    if (!dir.cd("SmartGuitarChords"))
    {
        dir.mkdir("SmartGuitarChords");
        dir.cd("SmartGuitarChords");
        dir.mkdir("Chords");
        dir.mkdir("Instruments");
    }
}

