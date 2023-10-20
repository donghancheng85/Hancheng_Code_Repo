// dynamic polymorphism

#include <iostream>
#include <memory>

class IBase
{
public:
    virtual void implementation()
    {
        std::cout << "Implementation Base" << std::endl;
    } 
};

class Derived1: public IBase
{
public:
    void implementation() override
    {
        std::cout << "Implementation Derived1" << std::endl;
    }
};

class Derived2: public IBase
{
public:
    void implementation() override
    {
        std::cout << "Implementation Derived2" << std::endl;
    }
};

class Derived3: public IBase
{};


int main()
{
      
    std::cout << std::endl;
    
    std::unique_ptr<IBase> d1 = std::make_unique<Derived1>();
    d1->implementation();

    std::unique_ptr<IBase> d2 = std::make_unique<Derived2>();
    d2->implementation();
    
    std::unique_ptr<IBase> d3 = std::make_unique<Derived3>();
    d3->implementation();
  
    std::cout << std::endl;
}