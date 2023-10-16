#include <iostream>

int main(){
  float* fltPtr = new float(50.505); // A float has been created in dynamic memory
  std::cout << *fltPtr << std::endl;
  
  int* intArray = new int[10]; // A dynamic array of size 10 has been created
  intArray[0] = 20;
  std::cout << intArray[10000] << std::endl;

  //need to garbage collection
  delete fltPtr;
  delete[] intArray;
}