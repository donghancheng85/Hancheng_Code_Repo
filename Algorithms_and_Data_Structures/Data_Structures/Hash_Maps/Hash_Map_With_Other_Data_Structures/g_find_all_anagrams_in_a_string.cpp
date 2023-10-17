#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

std::vector<std::size_t> FindAnagrams(const std::string& a, const std::string& b)
{
    // edge case, string b is longer than string a. No anagram
    if (a.length() < b.length())
        return{};

    // hashA to store string a's characters' frequency in a moving window
    // the size of the moving window is the length of string B
    std::unordered_map<char, std::size_t> hashA;

    // hashB to store the frequency of the characters in string b. It does not change
    std::unordered_map<char, std::size_t> hashB;

    // get character frequency in string b, and first window of a
    for (std::size_t i = 0; i < b.length(); ++i)
    {
        ++hashA[a[i]];
        ++hashB[b[i]];
    }

    std::size_t windowSize = b.length();
    std::vector<std::size_t> result{};

    // compare the first window
    if (hashA == hashB)
        result.push_back(0);

    // use sliding window in string a
    for(std::size_t windowBegin = 1; windowBegin < a.length()-b.length() + 1; ++windowBegin)
    {
        // remove the character that move out of the window
        --hashA[a[windowBegin-1]];
        if (hashA[a[windowBegin-1]] == 0)
            hashA.erase(a[windowBegin-1]);

        // add the character that enters the window
        std::size_t windowEnd = windowBegin + windowSize - 1;
        ++hashA[a[windowEnd]];

        if (hashA == hashB)
            result.push_back(windowBegin);
    }

    return result;
}


int main()
{
    std::string a = "acttacttca";
    std::string b = "cat";

    auto result = FindAnagrams(a, b);

    for (const auto & num : result)
        std::cout << num << " ";
    std::cout << "\n\n";

    return 0;
}
