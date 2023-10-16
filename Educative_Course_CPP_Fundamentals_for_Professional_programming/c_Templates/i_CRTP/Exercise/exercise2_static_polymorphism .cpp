// templateCRTP.cpp

#include <iostream>
#include <type_traits>

template <typename Derived>
struct Base{
  void interface(){
    //static_assert(std::is_convertible<decltype(*this), Derived>::value, "CRTP base template is not the same as derived type!!");
    //std::cout << typeid(*this).name() << "\n";
    //std::cout << typeid(Derived).name() << "\n";
    static_cast<Derived*>(this)->implementation();
  }
  void implementation(){
    std::cout << "Implementation Base" << std::endl;
  }
};

struct Derived1: Base<Derived1>{
  void implementation(){
    std::cout << "Implementation Derived1" << std::endl;
  }
};

struct Derived2: Base<Derived2>{
  void implementation(){
    std::cout << "Implementation Derived2" << std::endl;
  }
};

struct Derived3: Base<Derived3>{};

template <typename T>
void execute(T& base){
    base.interface();
}

// Write the struct here
struct Derived4: Base<Derived3>
{
  void implementation(){
    std::cout << "Implementation Derived4" << std::endl;
  }
};


int main(){
  
  std::cout << std::endl;
  
  // call the function here
  Derived4 d4;
  execute(d4);
  
  std::cout << std::endl;
  
}
