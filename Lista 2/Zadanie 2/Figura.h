#pragma once
#include <memory>
#include "Blad.h"

class Figura 
{
    public:
    virtual double obwod() = 0;
    virtual double pole() = 0;
};

class Okrag : public Figura 
{
    private:
    double promien;

    public:
    Okrag(double r) throw(BladBok);

    virtual double obwod();
    virtual double pole();
};

class Pieciokat : public Figura
{
    private:
    double bok;

    public:
    Pieciokat(double b) throw(BladBok);

    virtual double obwod();
    virtual double pole();
};

class Szesciokat : public Figura
{
    private:
    double bok;

    public:
    Szesciokat(double b) throw(BladBok);

    virtual double obwod();
    virtual double pole();
};

class Czworokat : public Figura
{
    public:
    static std::shared_ptr<Czworokat> rozpoznaj(double a, double b, double c, double d, double kat) throw(BladBok, BladKat, BladCzworokat);
};

class Kwadrat : public Czworokat
{
    private:
    double bok;

    public:
    Kwadrat(double b) throw(BladBok);

    virtual double obwod();
    virtual double pole();
};

class Prostokat : public Czworokat
{
    private:
    double bokA;
    double bokB;

    public:
    Prostokat(double a, double b) throw(BladBok);

    virtual double obwod();
    virtual double pole();
};

class Romb : public Czworokat
{
    private:
    double bok;
    double kat;

    public:
    Romb(double a, double b) throw(BladBok, BladKat);

    virtual double obwod();
    virtual double pole();
};