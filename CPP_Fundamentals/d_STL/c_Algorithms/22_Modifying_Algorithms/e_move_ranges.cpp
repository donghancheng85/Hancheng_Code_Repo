#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
 
int main(){
 
  std::cout << std::endl;
   
  std::vector<int> myVec1{0, 1, 2, 3, 4, 5, 6, 7, 9};
  std::vector<int> myVec2(10);
 
  std::move(myVec1.begin(), myVec1.end(), myVec2.begin());
  for ( auto v: myVec2 ) std::cout << v << " ";
 
  std::cout << "\n" << myVec1.size() << "\n\n";
   
  std::string str1{"abcdefghijklmnop"};
  std::string str2{"---------------------"};
   
  std::cout << str2 << std::endl;
  std::move_backward(str1.begin(), str1.end(), str2.end());
  std::cout << str2 << std::endl;
     
  std::cout << std::endl;
 
}