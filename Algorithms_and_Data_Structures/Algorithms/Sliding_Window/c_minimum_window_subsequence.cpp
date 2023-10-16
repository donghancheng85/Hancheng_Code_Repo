#include <climits>
#include <string>
#include <iostream>
#include <vector>

std::string MinWindow(const std::string& str1, const std::string& str2)
{
    std::string smallest_window;
    int smallest_size        {INT_MAX};
    int current_window_start {0};

    // iterate index
    int str1_index            {0};
    int str2_index            {0};
    auto str1_length          {str1.length()};
    auto str2_length          {str2.length()};

    while (str1_index <= str1_length-1)
    {
        // iterate forward str1 until all str2 has been found
        if(str1.at(str1_index) == str2.at(str2_index))
        {
            // found one of the subsequence
            if(str2_index == str2_length-1)
            {
                // renew smallest_window and size if necessary
                if (str1_index - current_window_start +1 < smallest_size)
                {
                    smallest_size = str1_index - current_window_start +1;
                    smallest_window = str1.substr(current_window_start, smallest_size);
                }

                // iterate backward until all str2 character has been found
                int start1 {str1_index-1};
                int end1 {str1_index};
                str2_index--; // move one space since the current elements are already the same
                while (start1 >= 0)
                {
                    if(str1.at(start1) == str2.at(str2_index))
                    {
                        // find subsequence again
                        if(str2_index == 0)
                        {
                            // renew smallest_window and size if necessary
                            if (end1 - start1+1 < smallest_size)
                            {
                                smallest_size = end1 - start1+1;
                                current_window_start = start1;
                                str1_index = start1;
                                smallest_window = str1.substr(current_window_start, smallest_size);
                            }
                            break;
                        }
                        str2_index--;
                    }
                    start1--;
                }
            }

            // end of op
            str2_index++;
        }
        str1_index++;
    }
    return smallest_window;
}


int main()
{
    std::string str1 = "abababa";
    std::string str2 = "ba";
    auto result = MinWindow(str1, str2);
    std::cout << result << "\n\n";
}
