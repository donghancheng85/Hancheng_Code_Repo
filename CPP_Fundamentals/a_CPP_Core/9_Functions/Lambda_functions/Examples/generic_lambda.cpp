#include <iostream>
#include <vector>
#include <numeric>
using namespace std::string_literals;

int main() {
  auto add11=[ ](int i, int i2){ return i + i2; }; 
  auto add14= [ ](auto i, auto i2){ return i + i2; };
  std::vector<int> myVec{1, 2, 3, 4, 5};
  auto res11= std::accumulate(myVec.begin(), myVec.end(), 0, add11); 
  auto res14= std::accumulate(myVec.begin(), myVec.end(), 0, add14);
  
  std::cout << res11 << std::endl;
  std::cout << res14 << std::endl;

  std::vector<std::string> myVecStr{"Hello"s, " World"s};
  auto st= std::accumulate(myVecStr.begin(), myVecStr.end(), ""s, add14);
  std::cout << st << std::endl; // Hello World
}