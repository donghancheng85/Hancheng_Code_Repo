#include <iostream>
#include <string>
#include <unordered_map>

int FirstUniqueChar(const std::string &s)
{
    // create a hashmap to store the frequency of characters
    std::unordered_map<char, int> characterFrequencyInputString;

    // get the frequency in s
    for (auto character : s)
    {
        ++characterFrequencyInputString[character];
    }

    // traverse over input string to check the first character freq = 1
    int currentIndex{0};
    for (auto character : s)
    {
        if (characterFrequencyInputString[character] == 1)
        {
            return currentIndex;
        }
        ++currentIndex;
    }

    return -1;
}


int main()
{
    std::string inputString{"dajhfiuebdafsdhdgaj"};

    std::cout << FirstUniqueChar(inputString) << "\n\n";

    return 0;
}