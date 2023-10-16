#include <algorithm>
#include <iostream>
#include <vector>

void printVector(const std::vector<int>& vec)
{
    for (auto element : vec)
        std::cout << element << " ";
    std::cout << "\n";
}

int LongestCommonSubsequence(const std::string& str1, const std::string& str2)
{
    // use 2 rows to represent a 2D table since we do not need to create a str1.length()*str2.length() 2D table
    std::vector<int> current(str2.length() + 1, 0); // LCS current row
    std::vector<int> temp(str2.length() + 1, 0); // LCS temp row

    for (std::size_t i = 0; i < str1.length(); ++i)
    {
        for (std::size_t j = 0; j < str2.length(); ++j)
        {
            if(str1[i] == str2[j])
                current[j+1] = 1 + temp[j];
            else
                current[j+1] = std::max(temp[j+1], current[j]);
        }

        temp = current;
    }

    return current.back();
}

int main()
{
    std::string str1{"freedom"};
    std::string str2{"redeem"};

    std::cout << LongestCommonSubsequence(str1, str2) << "\n\n";

    return 0;
}
