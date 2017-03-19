#include <cmath>
#include <exception>
#include <string>
#include <sstream>
#include <iostream>

class BlednyKat : public std::exception
{
    private:
    std::string blad;

    public:
    BlednyKat(double k) 
    {
        blad = "Bledny kat: " + std::to_string(k) + ". Kat powinien byc w zakresie (0, 180).";
    }

    virtual const char* what() const noexcept
    {
        return blad.c_str();
    }
};

class BlednyCzworokat : public std::exception 
{
    private:
    std::string blad;

    public:
    BlednyCzworokat() 
    {
        blad = "Brak obslugi czworokata o podanych parametrach.";
    }

    virtual const char* what() const noexcept
    {
        return blad.c_str();
    }
};

class BlednyBok : public std::exception 
{
    private:
    std::string blad;

    public:
    BlednyBok() 
    {
        blad = "Niepoprawna wartosc dlugosci boku.";
    }

    virtual const char* what() const noexcept
    {
        return blad.c_str();
    }
};

class BlednaFigura : public std::exception 
{
    private:
    std::string blad;

    public:
    BlednaFigura() 
    {
        blad = "Brak obsugi danej figury.";
    }

    virtual const char* what() const noexcept
    {
        return blad.c_str();
    }
};

class BlednaIloscArgumentow : public std::exception
{
    private:
    std::string blad;

    public:
    BlednaIloscArgumentow()
    {
        blad = "Niepoprawna ilosc argumentow.";
    }

    virtual const char* what() const noexcept
    {
        return blad.c_str();
    }
};

class BlednyArgument : public std::exception
{
    private:
    std::string blad;

    public:
    BlednyArgument()
    {
        blad = "Niepoprawny argument.";
    }

    virtual const char* what() const noexcept
    {
        return blad.c_str();
    }
};

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
    Okrag(double r) throw(BlednyBok)
    {
        if(r <= 0)
            throw BlednyBok();
        
        promien = r;
    }

    double virtual obwod() 
    {
        return 2 * M_PI * promien;
    }

    virtual double pole()
    {
        return M_PI * promien * promien;
    }
};

class Pieciokat : public Figura 
{
    private:
    double bok;

    public:
    Pieciokat(double b) throw(BlednyBok)
    {
        if(b <= 0)
            throw BlednyBok();
        
        bok = b;
    }

    virtual double obwod() 
    {
        return 5 * bok;
    }

    virtual double pole() 
    {
        return (bok * bok * sqrt(5 * (5 + 2 * sqrt(5)))) / 4;
    }
};

class Szesciokat : public Figura 
{
    private:
    double bok;

    public:
    Szesciokat(double b) throw(BlednyBok)
    {
        if(b <= 0)
            throw BlednyBok();
        
        bok = b;
    }

    virtual double obwod() 
    {
        return 6 * bok;
    }

    virtual double pole() 
    {
        return (3 * bok * bok * sqrt(3)) / 2;
    }
};

class Czworokat : public Figura 
{
    public:
    static Czworokat* rozpoznaj(double bokA, double bokB, double bokC, double bokD, double kat) throw(BlednyCzworokat, BlednyBok, BlednyKat);
};

class Kwadrat : public Czworokat 
{
    private:
    double bok;

    public:
    Kwadrat(double b) throw(BlednyBok)
    {
        if(b <= 0)
            throw BlednyBok();
        
        bok = b;
    }

    virtual double obwod() 
    {
        return 4 * bok;
    }

    virtual double pole() 
    {
        return bok * bok;
    }
};

class Prostokat : public Czworokat 
{
    private:
    double bokA;
    double bokB;

    public:
    Prostokat(double a, double b) throw(BlednyBok)
    {
        if(a <= 0 || b <= 0)
            throw BlednyBok();
        
        bokA = a;
        bokB = b;
    }

    virtual double obwod() 
    {
        return 2 * bokA + 2 * bokB;
    }

    virtual double pole() 
    {
        return bokA * bokB;
    }
};

class Romb : public Czworokat 
{
    private:
    double bok;
    double kat;

    public:
    Romb(double b, double k) throw(BlednyBok, BlednyKat) 
    {
        if(b <= 0)
            throw BlednyBok();
        if(k <= 0 || k >= 180)
            throw BlednyKat(k);
        
        bok = b;
        kat = k;
    }

    virtual double obwod() 
    {
        return 4 * bok;
    }

    virtual double pole() 
    {
        return bok * bok * sin((kat * M_PI)/180.0);
    }
};


Czworokat* Czworokat::rozpoznaj(double bokA, double bokB, double bokC, double bokD, double kat) throw(BlednyCzworokat, BlednyBok, BlednyKat) 
{
    if((bokA == bokB) && (bokA == bokC) && (bokA == bokD)) 
    {
        if(kat == 90)
            return dynamic_cast<Czworokat*>(new Kwadrat(bokA));
        return dynamic_cast<Czworokat*>(new Romb(bokA, kat));
    }
    if((((bokA == bokB) && (bokC == bokD)) || ((bokA == bokC) && (bokB == bokD)) || ((bokA == bokD) && (bokB == bokC))) && kat == 90) 
    {
        double a = bokA;
        double b;
        if(bokB == bokA)
            b = bokC;
        else
            b = bokB;
        return dynamic_cast<Czworokat*>(new Prostokat(a, b));
    }

    throw BlednyCzworokat();
}


Figura** parsuj(int argc, char* argv[]) throw(BlednyArgument, BlednaIloscArgumentow, BlednaFigura, BlednyBok, BlednyKat, BlednyCzworokat) 
{
    if(argc < 2)
        throw BlednaIloscArgumentow();
    Figura** figury = new Figura*[std::string(argv[1]).length()];

    int pozycja = 2;
    std::istringstream ss;

    for(int i = 0; i < std::string(argv[1]).length(); i++) 
    {
        ss.clear();
        if(argv[1][i] == 'o') 
        {
            double a;
            if(pozycja >= argc)
                throw BlednaIloscArgumentow();
            ss.str(argv[pozycja]);
            ss >> a;
            if(ss.fail() || !ss.eof())
                throw BlednyArgument(); 
            figury[i] = new Okrag(a);
            pozycja++;
        }
        else if(argv[0][i] == 'c') 
        {
            double a[5];
            if(pozycja + 4 >= argc)
                throw BlednaIloscArgumentow();
            for(int p = 0; p < 5; p++)
            {
                ss.str(argv[pozycja]);
                ss >> a[p];
                if(ss.fail() || !ss.eof())
                    throw BlednyArgument(); 
                ss.clear();
            }
            figury[i] = Czworokat::rozpoznaj(a[0], a[1], a[2], a[3], a[4]);
            pozycja += 5;
        }
        else if(argv[0][i] == 'p') 
        {
            double a;
            if(pozycja >= argc)
                throw BlednaIloscArgumentow();
            ss.str(argv[pozycja]);
            ss >> a;
            if(ss.fail() || !ss.eof())
                throw BlednyArgument(); 
            figury[i] = new Pieciokat(a);
            pozycja++;
        }
        else if(argv[0][i] == 's') 
        {
            double a;
            if(pozycja >= argc)
                throw BlednaIloscArgumentow();
            ss.str(argv[pozycja]);
            ss >> a;
            if(ss.fail() || !ss.eof())
                throw BlednyArgument(); 
            figury[i] = new Szesciokat(a);
            pozycja++;
        }
        else 
        {
            throw new BlednaFigura();
        }
    }
    return figury;
}

void wypisz(Figura *f) 
{
        std::cout << "Obwod: " << f->obwod() << std::endl;
        std::cout << "Pole: " << f->pole() << std::endl;
}

void usun(Figura** f, int n)
{
    for(int i = 0; i < n; i++)
    {
        delete f[i];
    }
    delete[] f;
}



int main(int argc, char* argv[]) 
{
        try 
        {
            Figura** figury = parsuj(argc, argv);
            for(int i = 0; i < std::string(argv[1]).length(); i++) 
            {
                wypisz(figury[i]);
            }

            usun(figury, std::string(argv[1]).length());
        }
        catch(BlednyArgument ex) 
        {
            std::cout << ex.what() << std::endl;
        }
        catch(BlednaIloscArgumentow ex) 
        {
            std::cout << ex.what() << std::endl;
        }
        catch(BlednaFigura ex) 
        {
            std::cout << ex.what() << std::endl;
        }
        catch(BlednyBok ex) 
        {
            std::cout << ex.what() << std::endl;
        }
        catch(BlednyKat ex) 
        {
            std::cout << ex.what() << std::endl;
        }
        catch(BlednyCzworokat ex) 
        {
            std::cout << ex.what() << std::endl;
        }
        
    }