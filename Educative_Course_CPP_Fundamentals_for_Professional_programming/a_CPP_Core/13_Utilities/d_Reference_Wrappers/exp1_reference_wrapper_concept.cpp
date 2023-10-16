#include <functional>
#include <iostream>
#include <vector>

int main(){

  std::cout << std::endl;

  // will not compile
  //std::vector<int&> myIntRefVector;

  int a = 0;
  int b = 0;
  int c = 0;

  std::vector< std::reference_wrapper<int>> myIntRefVector= {std::ref(a), std::ref(b), std::ref(c)};

  for (auto b: myIntRefVector) std::cout << b << " ";

  std::cout << std::endl;

  // modify b and also myIntRefVec[1] !!!!
  b = 2011;

  for (auto b: myIntRefVector) std::cout << b << " ";

  std::cout << "\n\n";
}