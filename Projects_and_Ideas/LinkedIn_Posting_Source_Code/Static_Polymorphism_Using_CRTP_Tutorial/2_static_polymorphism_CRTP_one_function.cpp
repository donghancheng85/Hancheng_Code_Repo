#include <iostream>

template <typename Derived>
class IBase
{
public:
    void interface()
    {
        static_cast<Derived *>(this)->impl(); // (4)
    }

    void impl() // (1)
    {
        std::cout << "base impl!\n";
    }
};

class Derived : public IBase<Derived> // (3)
{
public:
    void impl() // (2)
    {
        std::cout << "derived impl!\n";
    }
};

template <typename Base>
void execute(Base &base)  // (5)
{
    base.interface();
}

int main()
{
    Derived d; // (7)
    execute(d);  // (6)

    return 0;
}