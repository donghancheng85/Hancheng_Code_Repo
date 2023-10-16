// Template function that calculates the sum of squared digits.
#include <cmath>
#include <iostream>

int SumOfSquaredDigits(int number)
{
    int totalSum = 0;
    while (number > 0)
    {
        int digit = number % 10;
        number = std::floor(number / 10);
        totalSum += digit * digit;
    }
    return totalSum;
}
bool IsHappyNumber(int n)
{
    // init
    int slow = n;
    int fast = SumOfSquaredDigits(n);

    while( fast != 1 && fast != slow )
    {
        slow = SumOfSquaredDigits(slow);
        fast = SumOfSquaredDigits(SumOfSquaredDigits(fast));
    }
     bool result;

    (fast == 1)? (result = true) : (result = false);
    return result;
}

int main()
{
    std::cout << std::boolalpha
              << IsHappyNumber(2147483646) << "\n"
              << IsHappyNumber(1) << "\n"
              << IsHappyNumber(8) << "\n";
}