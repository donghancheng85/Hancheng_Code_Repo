#include <algorithm>
#include <iostream>
#include <string>

bool IsPalindrome(std::string inputString)
{
    if (inputString.length() == 1)
        return true;
    
    auto bfit = inputString.begin();
    auto mbfit = bfit + inputString.length() / 2;
    auto brit = inputString.rbegin();
    auto mbrit = brit + inputString.length() / 2;

    return std::equal(bfit, mbfit, brit, mbrit);
}

int main()
{
    std::cout << std::boolalpha;
    std::cout << "IsPalindrome(kyayk)" << IsPalindrome("kyayk") << "\n";
    std::cout << "IsPalindrome(hello)" << IsPalindrome("hello") << "\n";
}