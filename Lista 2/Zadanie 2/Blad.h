#pragma once
#include <exception>
#include <string>

class Blad : std::exception
{
    private:
    std::string blad;

    public:
    Blad(std::string b);

    virtual const char* what() const noexcept;
};

class BladKat : public Blad
{
    public:
    BladKat();
};

class BladCzworokat : public Blad
{
    public:
    BladCzworokat();
};

class BladBok : public Blad
{
    public:
    BladBok();
};

class BladFigura : public Blad
{
    public:
    BladFigura();
};

class BladArgument : public Blad
{
    public:
    BladArgument();
};