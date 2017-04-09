#include <iostream>
#include <string>
#include <exception>
#include <sstream>


class RowOfPascalTriangle
{
    private:
    int *row = nullptr;
    int n;

    public:
    RowOfPascalTriangle(int n) throw(std::invalid_argument)
    {
        if(n < 0 || n > 33)
            throw std::invalid_argument("Argument is not correct!\n");
        
        row = new int[n+1];
        this->n = n;

        for(int i = 0; i < n+1; i++) 
        {
            row[i] = 1;
            for(int j = i - 1; j > 0; j--) 
            {
                row[j] += row[j-1];
            } 
        }
    }

    ~RowOfPascalTriangle()
    {
        if(row != nullptr)
            delete[] row;
    }

    int coefficient(int m) throw(std::invalid_argument)
    {
        if(m < 0 || m > n)
            throw std::invalid_argument("Argument is not correct!\n");
        return row[m];
    }
};



int main(int argc, char* argv[])
{
    try
    {
        if(argc < 2)
            throw std::out_of_range("Too few arguments!\n");
        
        std::istringstream ss;
        ss.str(argv[1]);
        int n;
        ss >> n;

        if(ss.fail() || !ss.eof())
            throw std::invalid_argument("Argument is not correct!\n");

        RowOfPascalTriangle rowOfTriangle(n);
        int m;

        for(int i = 2; i < argc; i++)
        {
            ss.clear();
            ss.str(argv[i]);
            ss >> m;
            if(ss.fail() || !ss.eof())
                throw std::invalid_argument("Argument is not correct!\n");

            try
            {
                std::cout << rowOfTriangle.coefficient(m) << std::endl;
            }
            catch(std::exception &ex)
            {
                std::cerr << ex.what() << std::endl;
            }

        }        
    }
    catch(std::exception &ex) 
    {
        std::cerr << ex.what() << std::endl;
    }

    return 0;
}