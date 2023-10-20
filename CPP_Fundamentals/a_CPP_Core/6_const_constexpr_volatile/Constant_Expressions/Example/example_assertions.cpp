#include <iostream>

constexpr int square(int x) { return x * x; }
constexpr int squareToSquare(int x){ return square(square(x));}

int main() {

  std::cout << std::endl;

  static_assert(square(10) == 100, "you calculated it wrong");
  static_assert(squareToSquare(10) == 10000 , "you calculated it wrong");

  std::cout<< "square(10) = " << square(10) << std::endl;
  std::cout<< "squareToSquare(10) = " << squareToSquare(10) << std::endl;
  constexpr int constExpr = square(10);
  
  int arrayClassic[100];
  int arrayNewWithConstExpression[constExpr];
  constexpr int arrayNewWithConstExpressioFunction[square(10)] = {0, };

  std::cout << std::endl;

}