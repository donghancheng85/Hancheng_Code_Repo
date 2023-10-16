#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream infile;
    std::string fileName;

    std::cout << "please input file name: ";
    std::cin >> fileName;

    infile.open(fileName);
    
    if (!infile.is_open())
    {
        std::cout << "cannot open file " << fileName << "!\n";
        return -1;
    }

    std::cout << fileName << " has opened, reading file....\n";

    std::string line;
    while(std::getline(infile, line))
    {
        std::cout << line << "\n";
    }

    infile.close();
}