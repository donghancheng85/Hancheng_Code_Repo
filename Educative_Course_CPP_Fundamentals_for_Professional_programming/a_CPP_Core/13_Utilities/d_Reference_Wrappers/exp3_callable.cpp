// referenceWrapperCallable.cpp 
#include <iostream>
#include <functional>

void foo(){ 
  std::cout << "Invoked" << std::endl; 
}

int main() {
  typedef void callableUnit();
  std::reference_wrapper<callableUnit> refWrap(foo);

  refWrap(); // Invoked
  return 0;
}