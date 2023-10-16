#include <iostream>
#include <numeric>
#include <vector>
#include <string>
using namespace std::string_literals;

int main() {

  /*add numbers*/
  std::vector<int> iVec{1,2,3,5,6,7,888,111};

  auto sum_iVec = std::accumulate(iVec.begin(), iVec.end(), 0);

  std::cout << "sum of iVec is: " << sum_iVec << "\n";

  /*multiply numbers*/
  auto multi_iVec = std::accumulate(
    iVec.begin(), iVec.end(), 1,
    [](int a, int b){return a * b;});

  std::cout << "multiply of iVec is: " << multi_iVec << "\n";

  /*concatenate strings*/
  std::vector<std::string> sVec{"Only ", "for ", "testing ", "Purpose."};
  auto con_sVec = std::accumulate(sVec.begin(), sVec.end(), ""s);

  std::cout << "concatenate strings vector sVec is: " << con_sVec << "\n";
  
  return 0;
}