#include <chrono>
#include <iostream>

enum class Impl
{
    impl1,
    impl2,
    impl3
};

template <typename Derived>
class IBase
{
public:
    void interface(Impl function)
    {
        switch (function)
        {
        case Impl::impl1:
            static_cast<Derived *>(this)->impl1();
            break;
        case Impl::impl2:
            static_cast<Derived *>(this)->impl2();
            break;
        case Impl::impl3:
            static_cast<Derived *>(this)->impl3();
            break;
        default:
            break;
        }
    }

    void impl1()
    {
        //std::cout << "base impl1!\n";
    }

    void impl2()
    {
        //std::cout << "base impl2!\n";
    }

    void impl3()
    {
        //std::cout << "base impl3!\n";
    }
};

class Derived : public IBase<Derived>
{
public:
    void impl1()
    {
        //std::cout << "derived impl1!\n";
    }

    void impl2()
    {
        //std::cout << "derived impl2!\n";
    }

    void impl3()
    {
        //std::cout << "derived impl3!\n";
    }
};

template <typename Base>
void execute(Base &base, Impl function)
{
    base.interface(function);
}

int main()
{
    Derived d;

    auto start = std::chrono::system_clock::now();  // (1)
    execute(d, Impl::impl1);
    execute(d, Impl::impl2);
    execute(d, Impl::impl3);
    std::chrono::duration<double> dur = std::chrono::system_clock::now() - start; // (2)
    std::cout << "time static polymorphism: " << dur.count() << " seconds" << std::endl; // (3)

    return 0;
}
