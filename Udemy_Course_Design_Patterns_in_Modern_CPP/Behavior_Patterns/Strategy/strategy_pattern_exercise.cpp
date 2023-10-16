#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
#include <cmath>
#include <memory>
using namespace std;
using namespace std::complex_literals;

struct DiscriminantStrategy
{
    virtual ~DiscriminantStrategy() = default;
    virtual double calculate_discriminant(double a, double b, double c) = 0;
};

struct OrdinaryDiscriminantStrategy : DiscriminantStrategy
{
    double calculate_discriminant(double a, double b, double c) override
    {
        return std::pow(b, 2)-4*a*c;
    }
};

struct RealDiscriminantStrategy : DiscriminantStrategy
{
    double calculate_discriminant(double a, double b, double c) override
    {
        double dis = std::pow(b, 2)-4*a*c;
        if (dis < 0)
            return std::nan("");
        else
            return dis;
    }
};

class QuadraticEquationSolver
{
    DiscriminantStrategy& strategy;
public:
    QuadraticEquationSolver(DiscriminantStrategy &strategy) : strategy(strategy) {}

    std::tuple<std::complex<double>, std::complex<double>> solve(double a, double b, double c)
    {
        double dis = strategy.calculate_discriminant(a, b, c);
        if (std::isnan(dis))
        {
            // RealDiscriminantStrategy
            std::cout << "nan!!" << "\n";
            return {
                {std::nan(""), std::nan("")}, 
                {std::nan(""), std::nan("")}
                };
        }
        else if (dis >= 0)
        {
            // real solution
            std::cout << "Real!!" << "\n";
            double rootd = std::sqrt(dis);
            return {
                {(-b + rootd)/(2*a), 0},
                {(-b - rootd)/(2*a), 0}
                };
        }
        else
        {
            // complex solution
            std::cout << "complex!!" << "\n";
            double rootd = std::sqrt(-dis);
            return{
                {(-b/(2*a)) , (rootd/(2*a))},
                {(-b/(2*a)) , -(rootd/(2*a))}
                };
        }
    }
};


int main()
{
    std::unique_ptr<DiscriminantStrategy> ds{new RealDiscriminantStrategy()};
    QuadraticEquationSolver eq(*ds);
    auto solution = eq.solve(1,1,2);

    std::cout << "solution 1 is: " << std::get<0>(solution) << "\n";
    std::cout << "solution 2 is: " << std::get<1>(solution) << "\n";



    // double result = ds->calculate_discriminant(1, 15, 1);
    // std::cout << std::boolalpha
    //           << std::isnan(result) << std::endl;
    // double v = 3.0;
    // std::complex<double> z1(1.0, v);
    // std::cout << z1 << std::endl;

}