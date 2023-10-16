#include <iostream>
#include <cmath>
#include <vector>

std::size_t BitwiseComplement(std::size_t num)
{
    if (num == 0)
        return 1;

    // We need to calculate the number of binary digits that num has
    // the floor of log2(num) represents the value we need
    std::size_t numBinDigits = std::floor(std::log2(num)) + 1;
    // now we need to generate an "all 1" number to flip all the binary
    // digit in num. We use std::pow
    std::size_t numToFlip = std::pow(2, numBinDigits) - 1;

    return num ^ numToFlip;
}


int main()
{
    std::cout << BitwiseComplement(8) << "\n\n";
    return 0;
}
