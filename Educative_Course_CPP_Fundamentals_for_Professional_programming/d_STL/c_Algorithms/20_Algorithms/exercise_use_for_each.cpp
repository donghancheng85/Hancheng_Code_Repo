// Calculate the mean of an std::vector and an std::array with std::for_each.

#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

class CalMean
{
private:
    double sum{0};
    int num{0};

public:
    template <typename T>
    void operator()(T val)
    {
        sum += static_cast<double>(val);
        num++;
    }

    double calMean()
    {
        return sum / static_cast<double>(num);
    }

};

int main()
{
    // calcuate std::vector mean
    std::vector<double> dVec{1.1, 2.2, 3.3, 4.4};
    auto dVecMean = std::for_each(dVec.begin(), dVec.end(), CalMean());

    std::cout << "dVec Mean is: " << dVecMean.calMean() << "\n";

    // calculate std::array mean
    std::array<int, 5> iArr{1,2,3,4,5};
    auto iArrMean = std::for_each(iArr.begin(), iArr.end(), CalMean());

    std::cout << "iArr Mean is: " << iArrMean.calMean() << "\n";
}