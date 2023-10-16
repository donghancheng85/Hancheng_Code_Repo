#include <iostream>

int main() {
  int i = 20; // A variable containing an integer
  int* iptr = &i; // A pointer that points to 'i'
  std::cout << iptr << std::endl; // Accessing the address stored in the pointer - addressXXXXXX
  std::cout << *iptr << std::endl; // Accessing the value that the pointer points to - deref 20
  i = 30;
  std::cout << *iptr << std::endl; // derefrencing the pointer reflects the change made in the variable - deref 30
  *iptr = 50;  // pointer variables can be used to change the value
  std::cout << *iptr << std::endl; // Accessing the changed value - deref 50
}