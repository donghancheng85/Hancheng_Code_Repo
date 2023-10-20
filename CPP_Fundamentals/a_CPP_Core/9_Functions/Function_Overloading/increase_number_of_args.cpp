#include <iostream>
#include <string.h>

float min(float x, float y){
    x = 1.23456f;
    return (x < y) ? x : y;
}

float min(float x, float y, float z){
    return x < y ? (x < z ? x : z) : (y < z ? y : z);
}

int main() {
  float a = 4.45f;
  float b = 1.23f;
  float f = min(a, b);
  std::cout << "a value is: " << a << std::endl;
  float f2 = min(4.45f, 1.23f, 0.19f);

  std::cout << f << std::endl;
  std::cout << f2 << std::endl;
  std::cout << a << std::endl;
}