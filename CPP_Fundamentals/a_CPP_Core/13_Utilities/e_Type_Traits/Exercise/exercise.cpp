#include <iostream>
#include <type_traits>

int main() {
  // your code goes here
  std::cout << std::boolalpha;
  
  using myCInt = std::add_const_t<int>;
  using myInt = std::remove_const_t<myCInt>;
  std::cout << "Is type myInt and const int the same? " << 
    std::is_same<myInt, const int>::value;

  std::cout << "\n";

  return 0;
}