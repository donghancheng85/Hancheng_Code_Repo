#include <iostream>
#include <utility>
#include <type_traits>
using namespace std;

// Implement divmod function here
template <typename T>
constexpr std::pair<T, T> divmod(T x, T y)
{
    static_assert(std::is_integral<T>::value, "T needs to be integral type!!");

    if (y == 0)
    {
        return std::make_pair(0, 0);
    }

    return std::make_pair(x/y, x%y);
}

int main() {
  
    // call your function here
    constexpr auto result = divmod(30, 7);
    if (result.first == 0)
    {
        std::cout << "divisor cannot be zero!!\n";
        return -1;
    }

    std::cout << "divmod(30, 7): " << "Quotient: " << result.first << " Remainder: " << result.second <<"\n";

}