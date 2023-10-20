#include <iostream>
#include <string>

int main(){
  std::cout << std::endl;

  std::string copy = "original";
  std::string ref = "original";
  auto lambda = [copy, &ref]{std::cout << copy << " " << ref << std::endl;};
  lambda();
  copy = "changed";
  ref = "changed";
  lambda();

  std::cout << std::endl;
}