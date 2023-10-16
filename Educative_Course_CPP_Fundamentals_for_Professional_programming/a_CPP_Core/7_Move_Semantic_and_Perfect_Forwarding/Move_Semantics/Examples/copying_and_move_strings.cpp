#include <iostream>
#include <string>
#include <utility>

int main(){

  std::string str1{"ABCDEF"};
  std::string str2;

  std::cout << "\n";

  // initial value
  std::cout << "str1 = " << str1 << std::endl; //str1 = ABCDEF
  std::cout << "str2 = " << str2 << std::endl; //str2 = 

  // copy semantic
  str2= str1;
  std::cout << "str2 = str1;\n";
  std::cout << "str1 = " << str1 << std::endl; // str1 = ABCDEF
  std::cout << "str2 = " << str2 << std::endl; // str2 = ABCDEF

  std::cout << "\n";

  std::string str3;

  // initial value
  std::cout << "str1 = " << str1 << std::endl; // str1 = ABCDEF
  std::cout << "str3 = " << str3 << std::endl; // str3 =

  // move semantic
  str3= std::move(str1);
  std::cout << "str3 = std::move(str1);\n";
  std::cout << "str1 = " << str1 << std::endl; // str1 = 
  std::cout << "str3 = " << str3 << std::endl; // str3 = ABCDEF

  std::cout << "\n";
}