#include <iostream>
#include <string>

int ExtraCharacterIndex(const std::string &str1, const std::string &str2)
{
    char result = 0;

    // xor every character in str1 and str2, the result will be the only different character
    // use the following properties:
    // XOR is commutative. This means, a ^ b = b ^ a
    // XOR is self-inverse. This means, any number XOR'ed with itself evaluates to 0. a ^ a = 0
    for (auto c : str1)
        result ^= c;

    for (auto c : str2)
        result ^= c;

    return (str1.length() > str2.length()) ? str1.find(result) : str2.find(result);
}


int main()
{
    std::string str1{"cbda"};
    std::string str2{"abc"};

    std::cout << ExtraCharacterIndex(str1, str2) << "\n\n";
}
