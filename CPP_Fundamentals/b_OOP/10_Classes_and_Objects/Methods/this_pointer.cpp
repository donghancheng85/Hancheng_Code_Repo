#include <iostream>

class Base{

public:

  Base& operator = (const Base& other){
    if (this == &other){
      std::cout << "self-assignment" << std::endl;
      return *this;
    }
    else{
      a = other.a;
      b = other.b;
      return *this;
    }
  }

  void newA(){
    int a{2011};
    std::cout << "this->a: " << this->a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "this->b: " << this->b << std::endl;
  }

private:
  int a{1998};
  int b{2014};

};

int main(){

  std::cout << std::endl;

  Base base;
  base.newA();

  std::cout << std::endl;

  Base& base2 = base; //note: base2 is a reference to base
  base = base2;

  std::cout << std::endl;

}