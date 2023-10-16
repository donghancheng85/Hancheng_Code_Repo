#include <iostream>
#include <string>
#include <unordered_map>

bool IsIsomorphic(std::string string1, std::string string2)
{
    if (string1.length()!= string2.length())
        return false;

    std::unordered_map<char, char> str12Map;
    std::unordered_map<char, char> str21Map;

    for (std::size_t i=0; i<string1.length(); ++i)
    {
        if (str12Map.count(string1[i]) != 0 && str12Map[string1[i]] != string2[i])
            return false;

        if (str21Map.count(string2[i]) != 0 && str21Map[string2[i]] != string1[i])
            return false;

        str12Map[string1[i]] = string2[i];
        str21Map[string2[i]] = string1[i];
    }

    return true;
}

int main()
{
    std::string str1 = "paper";
    std::string str2 = "title";

    std::cout << std::boolalpha;
    std::cout << IsIsomorphic(str1, str2) << "\n\n";
}
