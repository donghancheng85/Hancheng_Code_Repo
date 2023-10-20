#include <iostream>
#include <future>
#include <thread>
#include <utility>
#include <string>
#include <exception>

void myDiv(std::promise<double> divPro, double a, double b)
{   
    try
    {
        if(b == 0)
        {
            std::string err = "divid by zero! " + std::to_string(a)
                              + " / " +std::to_string(b);
            throw std::runtime_error(err);
        }
        divPro.set_value(a/b);
    }
    catch(...)
    {
        divPro.set_exception(std::current_exception());
    }
}

int main()
{
    std::promise<double> divPro;
    auto divFut = divPro.get_future();

    std::thread divThread(myDiv, std::move(divPro), 1.0, 0.0);

    try
    {
        auto result = divFut.get();
        std::cout << "result is: " << result << "\n";
    }
    catch(const std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    divThread.join();
}