// vector.cpp 
#include <iostream>
#include <vector>

int main(){
  std::vector<int> intVec1(5, 2011);
  intVec1.reserve(10);
  std::cout << intVec1.size() << std::endl;     // 5
  std::cout << intVec1.capacity() << std::endl; // 10

  intVec1.shrink_to_fit();
  std::cout << intVec1.capacity() << std::endl; // 5

  std::vector<int> intVec2(10);
  std::cout << intVec2.size() << std::endl;     // 10

  std::vector<int> intVec3{10};
  std::cout << intVec3.size() << std::endl;     // 1

  std::vector<int> intVec4{5, 2011};
  std::cout << intVec4.size() << std::endl;     // 2
  return 0;
}