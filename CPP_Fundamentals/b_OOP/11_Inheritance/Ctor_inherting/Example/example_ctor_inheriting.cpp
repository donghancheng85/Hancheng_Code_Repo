#include <iostream>
#include <string>

class Base{
 public:

    Base() = default;
    Base(int i){
      std::cout << "Base::Base("<< i << ")" << std::endl;
    }

    Base(std::string s){
      std::cout << "Base::Base("<< s << ")" << std::endl;
    }

    Base(double d){
      std::cout << "Base::Base("<< d << ")" << std::endl;
    }
};

class Derived: public Base{
  public:

    using Base::Base;

    Derived(double d){
      std::cout << "Derived::Derived("<< d << ")" << std::endl;
    }

};

int main(){

  // inheriting Base
  Derived(2011);         // Base::Base(2011)

  // inheriting Base     // Base::Base(C++0x)
  Derived("C++0x");

  // using Derived
  Derived(0.33);         // Derived::Derived(0.33)

}
