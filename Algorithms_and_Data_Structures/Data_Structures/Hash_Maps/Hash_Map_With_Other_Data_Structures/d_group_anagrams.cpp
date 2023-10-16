#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

std::vector<std::vector<std::string>> GroupAnagrams(std::vector<std::string> &strs)
{
    // map to store group of anagrams
    std::unordered_map<std::string, std::vector<std::string>> groups;

    // frequency of characters in each string, use a vector with 26 elements (a-z)
    std::vector<std::size_t> freq(26, 0);

    for (const auto &s : strs)
    {
        // get the frequency of characters in each string
        for (auto c : s)
        {
            auto index = static_cast<std::size_t>(c - 'a');
            ++freq[index];
        }

        // convert freq to string so it can be easily stored in the hash map
        std::string keyTemp{};
        for (auto f : freq)
            keyTemp += std::to_string(f);

        groups[keyTemp].push_back(s);

        // reset freq
        std::fill(freq.begin(), freq.end(), 0ul);
    }

    std::vector<std::vector<std::string>> result;
    result.reserve(groups.size());

    for (const auto &p : groups)
        result.push_back(p.second);

    return result;
}

int main()
{
    std::vector<std::string> strs{"eat", "drink", "sleep", "repeat"};

    auto result = GroupAnagrams(strs);

    for (auto &vec : result)
    {
        std::cout << "[";
        for (auto &str : vec)
        {
            std::cout << str << " ";
        }
        std::cout << "] ";
    }

    std::cout << "\n\n";
}
