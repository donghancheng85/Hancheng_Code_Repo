// templateFunctionsTemplatesOverloading.cpp

#include <iostream>

void xchg(int& x, int& y){   // 1
  int t = x;
  x = y;
  y = t;
}


template <typename T>        // 2
void xchg(T& x, T& y){
  T t = x;
  x = y;
  y = t;
}

template <typename T>         // 3
void xchg(T& x, T& y, T& z){
  xchg(x, y);
  xchg(x, z);
}

int main(){

  std::cout << std::endl;

  int intA = 5;
  int intB = 10;
  int intC = 20;

  double doubleA = 5.5;
  double doubleB = 10.0;
  
  std::cout << "Before: " << intA << ", " << intB << std::endl;
  xchg(intA, intB);              // 1
  std::cout << "After: " << intA << ", " << intB << std::endl;

  std::cout << std::endl;

  std::cout << "Before: " << doubleA << ", " << doubleB << std::endl;
  xchg(doubleA, doubleB);        // 2
  std::cout << "After: " << doubleA << ", " << doubleB << std::endl;
  
  std::cout << std::endl;

  xchg<>(intA, intB);            // explicit 2
  xchg<int>(intA, intB);         // explicit 2: xchg<int>
  // xchg<double>(intA, intB);      // ERROR explicit xchg<double>
  
  std::cout << "Before: " << intA << ", " << intB << ", " << intC << std::endl;
  xchg(intA, intB, intC);        // 3
  std::cout << "After: " << intA << ", " << intB << ", " << intC << std::endl;

  std::cout << std::endl;
}