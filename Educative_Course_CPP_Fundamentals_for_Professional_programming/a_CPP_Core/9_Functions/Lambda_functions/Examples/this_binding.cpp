#include <iostream>

class ClassMember{
  const static int a = 1;
  int get10(){
    return 10;
  }
  public:
    void showAll(){
      // define and invoke (trailing () ) the lambda functions
      [this]{std::cout << "by this = " << get10() + a  << std::endl;}();
      [&]{std::cout << "by reference = " << get10()+ a  << std::endl;}();
      [=]{std::cout << "by copy = " << get10() + a << std::endl;}();
    }
};

int main(){

  std::cout << std::endl;

  ClassMember cM;
  cM.showAll();

  std::cout << std::endl;

}
