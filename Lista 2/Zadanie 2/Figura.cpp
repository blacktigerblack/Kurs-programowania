#include "Figura.h"
#include <cmath>
#include <exception>
#include <string>
#include <sstream>
#include <iostream>


//Okrag
Okrag::Okrag(double r) throw(BladBok)
{
    if(r <= 0)
        throw BladBok();
        
    promien = r;
}

double Okrag::obwod()
{
    return 2 * M_PI * promien;
}

double Okrag::pole()
{
    return M_PI * promien * promien;
}


//Pieciokat
Pieciokat::Pieciokat(double b) throw(BladBok)
{
    if(b <= 0)
        throw BladBok();
        
    bok = b;
}

double Pieciokat::obwod() 
{
    return 5 * bok;
}

double Pieciokat::pole() 
{
    return (bok * bok * sqrt(5 * (5 + 2 * sqrt(5)))) / 4;
}


//Szesciokat
Szesciokat::Szesciokat(double b) throw(BladBok)
{
    if(b <= 0)
        throw BladBok();
        
    bok = b;
}

double Szesciokat::obwod() 
{
    return 6 * bok;
}

double Szesciokat::pole() 
{
    return (3 * bok * bok * sqrt(3)) / 2;
}


//Czworokat
std::shared_ptr<Czworokat> Czworokat::rozpoznaj(double a, double b, double c, double d, double kat) throw(BladCzworokat, BladBok, BladKat)
{
    if((a == b) && (a == c) && (a == d))
    {
        if(kat == 90)
            return std::make_shared<Kwadrat>(a);
        return std::make_shared<Romb>(a, kat);
    }
    if((((a == b) && (c == d)) || ((a == c) && (b == d)) || ((a == d) && (b == c))) && (kat == 90))
    {
        double bokA = a;
        double bokB;
        if(a == b)
            bokB = c;
        else
            bokB = b;
        
        return std::make_shared<Prostokat>(bokA, bokB);
    }
    throw BladCzworokat();
}


//Kwadrat
Kwadrat::Kwadrat(double b) throw(BladBok)
{
    if(b <= 0)
        throw BladBok();
        
    bok = b;
}

double Kwadrat::obwod() 
{
    return 4 * bok;
}

double Kwadrat::pole() 
{
    return bok * bok;
}


//Prostokat
Prostokat::Prostokat(double a, double b) throw(BladBok)
{
    if(a <= 0 || b <= 0)
        throw BladBok();
        
    bokA = a;
    bokB = b;
}

double Prostokat::obwod() 
{
    return 2 * bokA + 2 * bokB;
}

double Prostokat::pole() 
{
    return bokA * bokB;
}


//Romb
Romb::Romb(double b, double k) throw(BladBok, BladKat) 
{
    if(b <= 0)
        throw BladBok();
    if(k <= 0 || k >= 180)
        throw BladKat();
        
    bok = b;
    kat = k;
}

double Romb::obwod() 
{
    return 4 * bok;
}

double Romb::pole() 
{
    return bok * bok * sin((kat * M_PI)/180.0);
}