#include <iostream>
#include <string>
#include <unordered_map>

bool IsAnagram(const std::string &str1, const std::string &str2)
{
    if (str1.length() != str2.length())
        return false;

    std::unordered_map<char, int> charMap;
    for (auto c : str1)
        ++charMap[c];

    for (auto c : str2)
        --charMap[c];

    for (const auto &p : charMap)
    {
        if (p.second != 0)
            return false;
    }

    return true;
}

int main()
{
    std::string str1 = "super";
    std::string str2 = "upper";

    std::cout << std::boolalpha;
    std::cout << IsAnagram(str1, str2) << "\n\n";
}
