#include <cmath>
#include <iostream>
#include <string>
#include <unordered_set>

std::string FractionToDecimal(int numerator, int denominator)
{
    // if numerator is 0, then return 0
    if (numerator == 0)
        return "0";

    std::string result{};

    // if numerator or denominator is negitive, add "-" to result
    if (numerator < 0 || denominator < 0)
        if (!(numerator < 0 && denominator < 0))
            result += "-";

    // get abs of both values
    numerator = std::abs(numerator);
    denominator = std::abs(denominator);

    int quo = numerator / denominator;
    int remainder = numerator % denominator;

    // if remainder == 0, return
    result += std::to_string(quo);
    if (remainder == 0)
        return result;

    // if remainder != 0, then add decimal
    result += ".";
    std::string decimalStr{}; // store the decimal section
    std::unordered_set<int> remaindersList{};

    // loop unitl remainder is 0
    while (remainder)
    {
        // if the remainder is new, add it to the remainder list, or return the result which is recurring decimal
        if (remaindersList.count(remainder) == 0)
        {
            remaindersList.insert(remainder);
            quo = remainder * 10 / denominator;
            remainder = remainder * 10 % denominator;
            decimalStr += std::to_string(quo);
        }
        else
        {
            // find the index of next quo, the remainder part of decimal will be recurring
            quo = remainder * 10 / denominator;
            auto index = decimalStr.find(std::to_string(quo).c_str());
            decimalStr.insert(index, "(");
            result += decimalStr + ")";
            return result;
        }
    }

    return result + decimalStr;
}

int main()
{

    std::cout << FractionToDecimal(47, 18) << "\n\n";
}
