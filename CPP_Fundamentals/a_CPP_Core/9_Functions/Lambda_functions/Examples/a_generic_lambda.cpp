#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

auto add = [](int i, int i2){ return i + i2; };
auto add14 = [](auto i, auto i2){ return i + i2; };

int main(){

  std::cout << std::endl;

  std::cout << "add(2000, 11): " << add(2000, 11) << std::endl;

  std::cout << "add14(2000, 14): " << add14(2000, 14) << std::endl;
  std::cout << "add14(2000L, 14): " << add14(2000L, 14) << std::endl;
  std::cout << "add14(3, 0.1415): " << add14(3, 0.1415) << std::endl;
  std::cout << "add14(std::string(Hello), std::string(World)): "
            << add14(std::string("Hello "), std::string("World")) << std::endl;

  std::cout << std::endl;

  std::vector<int> myVec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto res = std::accumulate(myVec.begin(), myVec.end(), 1, [](int i, int i2){ return i * i2;});
  std::cout << "res: " << res << std::endl;

  auto res14 = std::accumulate(myVec.begin(), myVec.end(), 1, [](auto i, auto i2){ return i * i2;});
  std::cout << "res14: " << res14 << std::endl;

  std::cout << std::endl;

}