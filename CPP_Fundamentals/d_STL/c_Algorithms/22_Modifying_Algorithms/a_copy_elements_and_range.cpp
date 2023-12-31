#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
int main(){
 
  std::cout << std::endl;
   
  std::vector<int> myVec{0, 1, 2, 3, 4, 5, 6, 7, 9};
  std::vector<int> myVec2(10);
 
  std::copy_if(myVec.begin(), myVec.end(), myVec2.begin()+3, [](int a){ return a%2; });
  for ( auto v: myVec2 ) std::cout << v << " "; // 0 0 0 1 3 5 7 9
 
  std::cout << "\n\n";
   
  std::string str{"Iamstring1"};
  std::string str2{"Hellostring---------------------2"};
   
  std::cout << str2 << std::endl;
  std::copy_backward(str.begin(), str.end(), str2.end());
  std::cout << str2 << std::endl;
   
  std::cout << std::endl;
   
  std::cout << str << std::endl;
  std::copy_backward(str.begin(), str.begin() + 5,  str.end());
  std::cout << str << std::endl;
   
  std::cout << std::endl;
 
}