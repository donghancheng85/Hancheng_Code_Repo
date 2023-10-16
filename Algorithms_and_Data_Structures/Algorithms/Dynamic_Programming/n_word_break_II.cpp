#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

std::vector<std::string> WordBreak(std::string const & s, std::vector<std::string> const & wordDict)
{
    // convert vector wordDict to unordered_set to increase performance
    std::unordered_set<std::string> setDict;
    for(auto const & word : wordDict)
        setDict.insert(word);

    // create a list to store all possible combinations
    std::vector<std::vector<std::string>> dp(s.length() + 1);
    dp[0] = {""};

    for(std::size_t i = 1; i <= s.length(); ++i)
    {
        auto const& prefix = s.substr(0, i);
        std::vector<std::string> temp;

        for(std::size_t j = 0; j < i; ++j)
        {
            auto const& suffix = prefix.substr(j);
            // suffix is a valid word
            if(setDict.count(suffix))
            {
                // combine with all possible words that the prefix of the suffix
                for(auto const & words : dp[j])
                {
                    temp.push_back(words + (words.empty()? "" : " ") + suffix);
                }
            }
        }

        dp[i] = temp;
    }

    // Replace this placeholder return statement with your code
    return dp.back();
}

int main()
{
    std::string str{"magiclly"};
    std::vector<std::string> wordDict{"ag","al","icl","mag","magic","ly","lly"};

    auto result = WordBreak(str, wordDict);

    for(auto const & word : result)
        std::cout << word << "\n";
    std::cout << "\n";

    return 0;
}
