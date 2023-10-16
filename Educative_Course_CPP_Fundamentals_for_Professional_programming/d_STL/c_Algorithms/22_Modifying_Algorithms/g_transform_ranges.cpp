#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
#include <vector>
 
int main(){
   
  std::cout << std::endl;
 
  std::string str{"abcdefghijklmnopqrstuvwxyz"};
 
  std::cout << str << std::endl;
 
  std::transform(str.begin(), str.end(), str.begin(), [](char c){ return std::toupper(c); });
 
  std::cout << str << std::endl;
   
  std::cout << std::endl;
   
  std::vector<std::string> vecStr1{"Only", "for", "testing", "purpose", "."};
  std::vector<std::string> vecStr2(5, "-");
   
  std::vector<std::string> vecRes;
   
  std::transform(vecStr1.begin(), vecStr1.end(),
         vecStr2.begin(),
         std::back_inserter(vecRes),
         [](std::string a, std::string b){ return b + a + b; });
   
  for ( auto str: vecRes ) std::cout << str << std::endl;
 
  std::cout << std::endl;
 
}