#include <iostream>

/**
 * @brief Note: derived class Derived2 has Derived1 as the template parameter. It is wrong.
 * The following code shows how to avoid this kind of mistake. Check comments in line 21-30
 */

template <typename Derived>
struct Base
{
    void interface()
    {
        static_cast<Derived *>(this)->implementation();
    }
    void implementation()
    {
        std::cout << "Implementation Base" << '\n';
    }

private:
    /**
     * @brief This will make sure the derived the class has itself as a template parameter.
     * If we do not have the following 2 lines of code, there is a problem. E.g., we declare Derived2:
     *     struct Derived2 : Base<Derived1>
     * We want to execute the implementation function in Derived2 but in this case, Derived1's implementation
     * will be executed.
     * Make ctor and template parameter Derived private will make sure the derived class has itself
     * as a template parameter. If not, compiler will generate error because derived class is not a friend
     * of the Base class. It cannot call the ctor.
     */
    Base() = default;
    friend Derived;
};

struct Derived1 : Base<Derived1>
{
    void implementation()
    {
        std::cout << "Implementation Derived1" << '\n';
    }
};

struct Derived2 : Base<Derived1> // Error! template argument is not the Derived2 itself!
{
    void implementation()
    {
        std::cout << "Implementation Derived2" << '\n';
    }
};


template <typename T>
void execute(T &base)
{
    base.interface();
}

int main()
{

    std::cout << '\n';

    Derived1 d1;
    execute(d1);

    // Derived2 d2; // Error! Derived2 cannot call ctor of Base<Derived1>
    // execute(d2);

    std::cout << '\n';
}
