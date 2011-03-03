#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <fstream>
#include <QFileSystemModel>

std::string trim(std::string str, char remove);
std::string trim(std::string str);

std::string tolower(std::string str);

void readPreferences();

#endif // FUNCTIONS_H
