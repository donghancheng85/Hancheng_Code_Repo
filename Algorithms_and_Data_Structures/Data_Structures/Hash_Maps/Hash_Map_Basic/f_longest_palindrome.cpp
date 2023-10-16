#include <iostream>
#include <string>
#include <unordered_map>

int LongestPalindrome(std::string palString)
{
    std::unordered_map<char, std::size_t> charCount;

    // count chars in palString
    for (auto c : palString)
    {
        ++charCount[c];
    }

    int result{0};
    bool hasOdd{false};

    for (auto& p : charCount)
    {
        if (p.second % 2 == 0)
            result += p.second;
        // odd count
        else
        {
            result += (p.second-1);
            hasOdd = true;
        }
    }

    return hasOdd? (result + 1) : result;
}

int main()
{
    std::string str = "GOODMORNINGTOYOU";

    std::cout << LongestPalindrome(str) << "\n\n";
}
