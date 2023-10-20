// array.cpp 
#include <iostream>
#include <array>
#include <numeric>

using namespace std;

int main(){
  std::array<int, 10> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  for (auto a: arr) std::cout << a << " " ;    // 1 2 3 4 5 6 7 8 9 10
  cout << "\n";

  std::cout << "Access the element that is greater than size (10) using index operator: " << arr[10] << "\n";
  std::cout << "Access the element that is greater than size (10) using at function: " << arr.at(10) << "\n";

  return 0;
}