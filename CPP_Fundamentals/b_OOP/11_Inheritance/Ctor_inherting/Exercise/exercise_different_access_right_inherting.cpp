#include <iostream>

class Base{
public:
  Base(int){
    std::cout << "Base ctor called!\n";
  }
};

// Make a class which derived Base class publiclly
class Der_Pub: public Base{
public:
    using Base::Base;
};

// Make a class which derived Base class protectedly
class Der_Pro: protected Base{
public:
    using Base::Base;
};

// Make a class which derived Base class privately
class Der_Pri: private Base{
public:
    using Base::Base;
};

int main(){

  // Call the objects of the above classes here
  Der_Pub dpub(3);
  Der_Pro dpro(3);
  Der_Pri dpri(3);
}
