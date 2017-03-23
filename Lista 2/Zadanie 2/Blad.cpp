#include "Blad.h"
#include <string>

Blad::Blad(std::string b)
{
    blad = b;
}

const char* Blad::what() const noexcept
{
    return blad.c_str();
}

BladKat::BladKat() : Blad("Bledny kat. Kat powinien byc w zakresie (0, 180).")
{}

BladCzworokat::BladCzworokat() : Blad("Brak obslugi czworokata o podanych parametrach.")
{}

BladBok::BladBok() : Blad("Niepoprawna wartosc dlugosci boku.")
{}

BladFigura::BladFigura() : Blad("Brak obsugi danej figury.")
{}

BladArgument::BladArgument() : Blad("Niepoprawny argument.")
{}