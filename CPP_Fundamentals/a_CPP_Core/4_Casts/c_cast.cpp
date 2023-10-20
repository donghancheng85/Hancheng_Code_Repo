#include <iostream>

int main(){

  double d = 2;
  auto p = (long*)&d;
  auto q = (long long*)&d;
  std::cout << d << ' ' << *p << ' ' << *q << '\n';

  std::cout << "size of long is: " << sizeof(long) << "\n";
  std::cout << "size of long long is: " << sizeof(long long) << "\n";
  
}