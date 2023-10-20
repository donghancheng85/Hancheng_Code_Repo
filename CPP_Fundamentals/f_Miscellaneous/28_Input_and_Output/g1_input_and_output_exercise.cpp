#include <iostream>
#include <string>

class Fraction
{
public:
    Fraction() = default;
    Fraction(int num, int den)
        : numerator(num),
          denominator(den)
          {}
    
    friend std::istream& operator >> (std::istream& is, Fraction& frac);
    friend std::ostream& operator << (std::ostream& os, const Fraction& frac);

private:
    int numerator, denominator;
};

std::istream& operator >> (std::istream& is, Fraction& frac)
{
    is >> frac.numerator >> frac.denominator;
    return is;
}

std::ostream& operator << (std::ostream& os, const Fraction& frac)
{
    os << frac.numerator << "/" << frac.denominator << std::endl;
    return os;
}

int main()
{
    std::cout << "Please input numerator and denominator : \n";

    Fraction myFra;
    std::cin >> myFra;

    std::cout << "The input fraction is: \n";
    std::cout << myFra;

}