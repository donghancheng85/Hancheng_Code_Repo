#include <iostream>
#include <memory>

class IBase
{
public:
    virtual void impl() = 0; // (1)

    virtual ~IBase() = default; // (3)
};

class Derived : public IBase
{
public:
    void impl() override // (2)
    {
        std::cout << "derived impl!\n";
    }
};

int main()
{
    std::unique_ptr<IBase> baseptr = std::make_unique<Derived>(); // (4)
    baseptr->impl();
}