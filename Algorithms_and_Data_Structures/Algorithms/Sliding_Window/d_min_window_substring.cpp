#include <iostream>
#include <limits>
#include <string>
#include <unordered_map>

std::string MinWindow(const std::string& s, const std::string& t)
{
    //store char frequencies of t in t_char_freq, init necessary char for win_char_freq
    std::unordered_map<char, int> t_char_freq;
    std::unordered_map<char, int> win_char_freq;
    for(auto c : t)
    {
        t_char_freq[c]++;
        win_char_freq[c] = 0;
    }

    // init necessary parameters
    std::size_t win_left  {0}; // left index of window
    std::size_t win_right {0}; // right index of window

    const std::size_t req_match_size  {t_char_freq.size()}; // target map size
    std::size_t       curr_match_size {0};                  // current matched size

    std::size_t min_win_size  {std::numeric_limits<std::size_t>::max()};
    std::size_t curr_win_size {0};
    std::string min_win{""}; //min window, will be result

    while (win_right <= s.length()-1)
    {
        if(win_char_freq.count(s[win_right]))
        {
            win_char_freq[s[win_right]]++;
            if (win_char_freq[s[win_right]] >= t_char_freq[s[win_right]])
            {
                if (win_char_freq[s[win_right]] == t_char_freq[s[win_right]])
                    curr_match_size++;

                // found a window that contains all the characters in t
                if (curr_match_size == req_match_size)
                {
                    // update min_win if necessary
                    if ((win_right-win_left+1) < min_win_size)
                    {
                        min_win_size = win_right-win_left+1;
                        min_win = s.substr(win_left, min_win_size);
                    }

                    // trim window if possible, move win_left
                    while (curr_match_size == req_match_size)
                    {
                        if(win_char_freq.count(s[win_left]))
                        {
                            win_char_freq[s[win_left]]--;
                            if(win_char_freq[s[win_left]] < t_char_freq[s[win_left]])
                                curr_match_size--;

                            // update min_win if necessary
                            if ((win_right-win_left+1) < min_win_size)
                            {
                                min_win_size = win_right-win_left+1;
                                min_win = s.substr(win_left, min_win_size);
                            }
                        }
                        win_left++;
                    }
                }
            }
        }
        win_right++;
    }

    return min_win;
}


int main()
{
    std::string s {"ABDFGDCKAB"};
    std::string t {"ABCD"};

    auto result = MinWindow(s, t);

    std::cout << result << "\n\n";
}
