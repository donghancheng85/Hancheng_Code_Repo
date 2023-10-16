#include <iostream>
#include <string>
#include <unordered_map>

int FindLongestSubstring(const std::string& str)
{
    // edge case
    if(str == "")
        return 0;

    // pre-define necessary parameters
    std::size_t win_left{0};
    std::size_t win_right{0};
    std::size_t longest_len{0};
    std::unordered_map<char, std::size_t> freq; // store frequency of char in str

    while (win_right <= str.length()-1)
    {
        freq[str.at(win_right)]++;

        // found repeating char
        if(freq[str.at(win_right)] > 1)
        {
            // move win_left to the next element of the previous repeating char
            while (str.at(win_left) != str.at(win_right))
            {
                freq[str.at(win_left)]--;
                win_left++;
            }
            freq[str.at(win_left)]--;
            win_left++;
        }
        win_right++;
        // no repeating char between left and right, update longest_len if necessary
        if(win_right-win_left > longest_len)
            longest_len = win_right-win_left;
    }

    return longest_len;
}

int main()
{
    std::string str = "abcdbea";
    std::cout << FindLongestSubstring(str) << "\n\n";
}
