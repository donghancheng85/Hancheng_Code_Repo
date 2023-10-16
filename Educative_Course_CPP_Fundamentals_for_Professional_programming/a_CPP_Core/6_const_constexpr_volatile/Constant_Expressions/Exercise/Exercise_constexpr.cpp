#include <iostream>

struct MyDouble{
  double myVal;
  constexpr MyDouble(double v): myVal(v){} 
  constexpr double getVal()const{ return myVal; }
};

int main() {
  MyDouble md1{1.1}; //Will not be created at compile-time
  constexpr MyDouble md2{2.2}; //Will be created at compile time

  double d2 = md2.myVal; //Will not be created at compile time
  constexpr auto d2_const = md2.myVal; //Will be created at compile time

  auto d2_1 = md2.getVal(); //Will not be created at compile time
  constexpr auto d2_2 = md2.getVal(); //Will be created at compile time
}