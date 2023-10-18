#include <chrono>
#include <iostream>
#include <memory>

class IBase
{
public:
    virtual void impl1()
    {
        //std::cout << "base impl1!\n";
    }

    virtual void impl2()
    {
        //std::cout << "base impl2!\n";
    }

    virtual void impl3()
    {
        //std::cout << "base impl3!\n";
    }

    virtual ~IBase() = default;
};

class Derived : public IBase
{
public:
    void impl1() override
    {
        //std::cout <<"derived impl1!\n";
    }

    void impl2() override
    {
        //std::cout <<"derived impl2!\n";
    }

    void impl3() override
    {
        //std::cout <<"derived impl3!\n";
    }
};

int main()
{
    std::unique_ptr<IBase> basePtr = std::make_unique<Derived>();

    auto start = std::chrono::system_clock::now(); // (1)
    basePtr->impl1();
    basePtr->impl2();
    basePtr->impl3();
    std::chrono::duration<double> dur = std::chrono::system_clock::now() - start; // (2)
    std::cout << "time dynamic polymorphism: " << dur.count() << " seconds" << std::endl;  // (3)
}
