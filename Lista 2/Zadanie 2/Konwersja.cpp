#include "Konwersja.h"
#include <sstream>

int stringToInt(std::string s) throw(BladArgument)
{
    static std::stringstream ss;
    ss.clear();
    ss.str(s);

    int n;
    ss >> n;

    if(ss.fail() || !ss.eof())
        throw BladArgument();
    
    return n;
}

double stringToDouble(std::string s) throw(BladArgument)
{
    static std::stringstream ss;
    ss.clear();
    ss.str(s);

    double n;
    ss >> n;

    if(ss.fail() || !ss.eof())
        throw BladArgument();

    return n;
}