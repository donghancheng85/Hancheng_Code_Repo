#include <iostream>
#include <vector>
#include <string>

std::string RemoveDuplicates(std::string& toCleanUp)
{
    if (toCleanUp.empty())
        return "";

    std::string charStack{};
    charStack.push_back(toCleanUp.front());
    toCleanUp.erase(toCleanUp.begin());

    for (auto c : toCleanUp)
        (c == charStack.back()) ? charStack.pop_back() : charStack.push_back(c);


    return charStack;
}

int main()
{
    std::string str = "ggaabcdeb";

    std::cout << RemoveDuplicates(str) << "\n\n";
}
