#include <iostream>
#include <cmath>

// Write your code here
// Method 1,function template, compile time calculation=================================================
template <int BASE, int POW>
constexpr long power1()
{
    int temp = POW;
    long result = 1;
    while (temp > 0)
    {
        result *= BASE;
        temp--;
    }
    return result;
}

// Method 2, function template using resusive call, compile time calculation===========================
template <int BASE>
constexpr long power2(int pow)
{
    return (pow > 0) ? BASE*power2<BASE>(pow-1) : 1;
}

// Method 3, template metaprogramming, calculate during compile time===================================
template <int BASE, int POW>
class power3
{
public:
    // need to be const or constexpr: complier does not allow non-const static member to be init
    // in the class. Also note: each static member in the template will have different init with
    // different template arguments.
    static constexpr long value = BASE * power3<BASE, POW-1>::value; 
};

template <int BASE>
class power3<BASE, 0>
{
public:
    static constexpr long value = 1;
};

// Method 4, class template, calculate at run time======================================================
template <int BASE, int POW>
class power4
{
public:
    static long value; 
};

template <int BASE, int POW>
long power4<BASE, POW>::value = BASE * power3<BASE, POW-1>::value;

template <int BASE>
class power4<BASE, 0>
{
public:
    static long value;
};
template <int BASE>
long power4<BASE, 0>::value = 1;

int main() {
    // Call function here
    constexpr long val = power1<2, 10>();

    std::cout << val << "\n";

    constexpr long val2 = power2<2>(10);

    std::cout << val2 << "\n";

    std::cout << "class template compile time: " << power3<2, 10>::value << "\n";

    std::cout << "class template run time: " << power4<2, 10>::value << "\n";

}