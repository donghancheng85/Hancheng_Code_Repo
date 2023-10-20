#include <functional>
#include <iostream>
#include <string>

void invokeMe(std::string& s){
  std::cout << s << ": not const " << std::endl;
}

void invokeMe(const std::string& s){
  std::cout << s << ": const " << std::endl;
}

template <typename T>
void doubleMe(T t){
  t *= 2;
}

int main(){

  std::cout << std::endl;

  std::string s{"string"};

  invokeMe(std::ref(s)); // not const
  invokeMe(std::cref(s)); // const

  std::cout << std::endl;

  int i = 1; 
  std::cout << "i: " << i << std::endl; // i: 1

  doubleMe(i);
  std::cout << "doubleMe(i): " << i << std::endl; // doubleMe(i): 1

  doubleMe(std::ref(i));
  std::cout << "doubleMe(std::ref(i)): " << i << std::endl; // doubleMe(i): 2

  double a = 5;
  std::cout << "a= " << a << std::endl; // a= 5
  doubleMe(std::ref(a));
  std::cout << "doubleMe(std::ref(a)): " << a << std::endl; //10

  std::cout << std::endl;

}