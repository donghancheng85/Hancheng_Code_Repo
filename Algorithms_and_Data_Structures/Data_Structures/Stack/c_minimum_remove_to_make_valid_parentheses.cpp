#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string MinRemoveParentheses(std::string &s)
{
    std::vector<std::pair<char, std::size_t>> strStack;
    std::size_t index{0};
    for (auto c : s)
    {
        if (c == '(')
            strStack.emplace_back(c, index);
        else if (c == ')')
        {
            if (strStack.empty() || strStack.back().first == ')')
                strStack.emplace_back(c, index);
            else
                strStack.pop_back();
        }
        ++index;
    }

    std::for_each(strStack.rbegin(), strStack.rend(), [&s](std::pair<char, std::size_t> toRemove) {
        s.erase(toRemove.second, 1);
    });

    return s;
}

int main()
{
    std::string str = "ab)ca(so)(sc(s)(";

    std::cout << MinRemoveParentheses(str) << "\n\n";
}
