#include <iostream>
#include <string>
#include <exception>
#include <sstream>

class BlednyArgumentKonstruktora : public std::exception
{
    private:
    std::string blad;

    public:
    BlednyArgumentKonstruktora(int n)
    {
       blad = "Argument: " + std::to_string(n) + " nie jest poprawnym argumentem. Argument powinien byc liczba dodatnia.";
    }

    virtual const char* what() const noexcept
    {
        return blad.c_str();
    }
};

class BlednyArgumentMetody : public std::exception
{
    private:
    std::string blad;

    public:
    BlednyArgumentMetody(int n, int m)
    {
        blad = "Argument: " + std::to_string(m) + " nie jest poprawnym argumentem metody. Argument powinien byc w zakresie [0, " + std::to_string(n) + "]";
    }

    virtual const char* what() const noexcept
    {
        return blad.c_str();
    }
};


class WierszTrojkataPascala
{
    private:
    int *wiersz = nullptr;
    int n;

    public:
    WierszTrojkataPascala(int n) throw(BlednyArgumentKonstruktora)
    {
        if(n < 0)
            throw BlednyArgumentKonstruktora(n);
        
        wiersz = new int[n+1];
        this->n = n;

        for(int i = 0; i < n+1; i++) 
        {
            wiersz[i] = 1;
            for(int j = i - 1; j > 0; j--) 
            {
                wiersz[j] += wiersz[j-1];
            } 
        }
    }

    ~WierszTrojkataPascala()
    {
        if(wiersz != nullptr)
            delete[] wiersz;
    }

    int wspolczynnik(int m) throw(BlednyArgumentMetody)
    {
        if(m < 0 || m > n)
            throw BlednyArgumentMetody(n, m);
        return wiersz[m];
    }
};



int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        std::cerr << "Niepoprawna ilosc argumentow!\n";
        return 1;
    }
    
    std::istringstream ss;
	ss.str(argv[1]);
    int n;
    ss >> n;

    if(ss.fail() || !ss.eof())
    {
        std::cerr << "Argument nie jest liczba naturalna!\n";
        return 2;
    }

    try 
    {
        WierszTrojkataPascala wierszTrojkata(n);
        int m;

        for(int i = 2; i < argc; i++)
        {
            ss.clear();
            ss.str(argv[i]);
            ss >> m;
            if(ss.fail() || !ss.eof())
            {
                std::cerr << "Argument nie jest liczba naturalna!\n";
                continue;
            }

            try
            {
                std::cout << wierszTrojkata.wspolczynnik(m) << std::endl;
            }
            catch(BlednyArgumentMetody ex)
            {
                std::cerr << ex.what() << std::endl;
            }

        }        
    }
    catch(BlednyArgumentKonstruktora ex) 
    {
        std::cerr << ex.what() << std::endl;
    }
    catch(std::exception ex)
    {
        std::cerr << ex.what();
    }
    catch(...)
    {}

    return 0;
}
