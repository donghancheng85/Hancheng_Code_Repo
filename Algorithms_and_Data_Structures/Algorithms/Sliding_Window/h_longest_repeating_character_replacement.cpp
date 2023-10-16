#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

int LongestRepeatingCharacterReplacement(const std::string& s, const int k)
{
    if (s.length() == 0)
        return -1;

    // init parameters
    std::size_t start{0};
    std::size_t end{1};
    std::size_t maxFreq{1}; // store the frequency of max frequency character
    std::size_t maxWindowSize{0};
    std::unordered_map<char, std::size_t> charFreq;
    ++charFreq[s[0]];

    // loop all the characters in s, until end reach to the end of s
    while( end < s.length() )
    {
        ++charFreq[s[end]];

        // update maxFreq
        maxFreq = std::max(maxFreq, charFreq[s[end]]);

        // more than k characters need to be changed
        if (end - start + 1 - maxFreq > k)
        {
            --charFreq[s[start]];
            ++start;
            maxFreq = std::max(maxFreq, charFreq[s[end]]);
        }

        maxWindowSize = std::max(maxWindowSize, end - start + 1);
        ++end;
    }

    return maxWindowSize;
}


int main()
{
    std::string str = "aaaaaaaaaa";
    int k = 2;

    std::cout << LongestRepeatingCharacterReplacement(str, k) << "\n\n";
}
