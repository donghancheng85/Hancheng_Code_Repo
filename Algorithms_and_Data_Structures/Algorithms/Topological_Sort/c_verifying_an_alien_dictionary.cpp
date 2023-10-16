#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

bool VerifyAlienDictionary(std::vector<std::string>& words, std::string& order)
{
    if(words.size() <= 1)
        return true;

    std::unordered_map<char, std::size_t> orderMap;
    std::size_t i{0};
    for(auto c : order)
        orderMap[c] = i++;

    // iterate over words and check each adjacent words
    for(std::size_t j = 0; j < words.size() - 1; ++j)
    {
        const auto& word = words[j];
        const auto& wordNext = words[j+1];

        // word is the prefix of wordNext, order is wrong
        if (word.length() > wordNext.length() && (word.find(wordNext) != std::string::npos))
            return false;

        for(std::size_t k = 0; k < std::min(word.length(), wordNext.length()); ++k)
        {
            if (word[k] != wordNext[k])
            {
                if (orderMap[word[k]] > orderMap[wordNext[k]])
                    return false;
                else
                    break;
            }
        }
    }
    return true;
}


int main()
{
    std::vector<std::string> words {"jupyter", "ascending"};
    std::string order {"jabcdefghiklmnopqrstuvwxyz"};

    std::cout << std::boolalpha;
    std::cout << VerifyAlienDictionary(words, order) << "\n\n";

    return 0;
}
