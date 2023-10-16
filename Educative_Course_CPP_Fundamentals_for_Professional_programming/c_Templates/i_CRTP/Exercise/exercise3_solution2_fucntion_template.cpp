// Function template

#include <iostream>

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

template <typename T>
void execute(T& t){
    t.implementation();
}

int main()
{
      
    std::cout << std::endl;
    
    Derived1 d1;
    execute(d1);
    
    Derived2 d2;
    execute(d2);
    
    Derived3 d3;
    execute(d3);
  
    std::cout << std::endl;
}