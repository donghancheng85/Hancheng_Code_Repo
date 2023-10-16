#include <iostream>
#include <string>
#include <unordered_map>

bool PermutePalindrome(const std::string& str)
{
    // use an unordered mapt to track character frequencies
    std::unordered_map<char, std::size_t> ump;

    for (auto c : str)
        ++ump[c];

    // check if there are more then 1 odd frequencies
    std::size_t oddCount {0};
    for (auto& p : ump)
    {
        if (p.second % 2)
            ++oddCount;
        if (oddCount > 1)
            return false;
    }

    return true;
}

int main()
{
    std::cout << std::boolalpha;

    std::cout << PermutePalindrome("code") << "\n\n";

}
