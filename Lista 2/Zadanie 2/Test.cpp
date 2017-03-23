#include <vector>
#include <array>
#include <memory>
#include <iostream>
#include "Figura.h"
#include "Konwersja.h"

std::vector<std::shared_ptr<Figura>> parsuj(int argc, char* argv[]) throw(std::out_of_range, BladArgument, BladCzworokat, BladKat, BladBok, BladFigura);
void wypisz(std::shared_ptr<Figura> f);

int main(int argc, char* argv[])
{
    try
    {
        std::vector<std::shared_ptr<Figura>> figury = parsuj(argc, argv);
        for(int i = 0; i < figury.size(); i++)
            wypisz(figury.at(i));
    }
    catch(Blad& ex)
    {
        std::cout << ex.what() << std::endl;
    }
    catch(std::out_of_range ex)
    {
        std::cout << "Niepoprawna ilosc argumentow." << std::endl;
    }

    return 0;
}

std::vector<std::shared_ptr<Figura>> parsuj(int argc, char* argv[]) throw(std::out_of_range, BladArgument, BladCzworokat, BladKat, BladBok, BladFigura)
{
    if(argc < 2)
        throw std::out_of_range("Niepoprawna ilosc argumentow.");
    
    std::vector<std::string> args;
    
    for(int i = 1; i < argc; i++)
    {
        args.push_back(std::string(argv[i]));
    }

    std::vector<std::shared_ptr<Figura>> figury;

    int pozycja = 1;

    for(int i = 0; i < args.at(0).length(); i++)
    {
        switch(args[0][i])
        {
            case 'o':
            figury.push_back(std::make_shared<Okrag>(stringToDouble(args.at(pozycja))));
            pozycja++;
            break;

            case 'p':
            figury.push_back(std::make_shared<Pieciokat>(stringToDouble(args.at(pozycja))));
            pozycja++;
            break;

            case 's':
            figury.push_back(std::make_shared<Szesciokat>(stringToDouble(args.at(pozycja))));
            pozycja++;
            break;

            case 'c':
            figury.push_back(Czworokat::rozpoznaj(stringToDouble(args.at(pozycja)), stringToDouble(args.at(pozycja+1)), stringToDouble(args.at(pozycja+2)), stringToDouble(args.at(pozycja+3)), stringToDouble(args.at(pozycja+4))));
            pozycja += 5;
            break;

            default:
            throw BladFigura();
        }
    }
    return figury;
}

void wypisz(std::shared_ptr<Figura> f)
{
    std::cout << "Obwod: " << f->obwod() << std::endl;
    std::cout << "Pole: " << f->pole() << std::endl;
}