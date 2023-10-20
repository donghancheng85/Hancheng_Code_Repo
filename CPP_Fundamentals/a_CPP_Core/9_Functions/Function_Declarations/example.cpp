#include <iostream>

bool isTempOK(const int temp, const int low = 20, const int high = 50){
  return (low < temp) && (temp < high);
}

int main(){
  
  std::cout << std::boolalpha << std::endl;

  std::cout << "isTempOK(20): "  << isTempOK(20) <<  std::endl; //false
  std::cout << "isTempOK(30): "  << isTempOK(30) <<  std::endl; //true
  std::cout << "isTempOK(50): "  << isTempOK(50) <<  std::endl; //false

  std::cout <<  std::endl;
  
  std::cout << "isTempOK(30, 30): "  << isTempOK(30, 30) <<  std::endl; // false
  std::cout << "isTempOK(50, 30, 100): "  << isTempOK(50, 30, 100) <<  std::endl; // true
  
  std::cout << std::endl;

} 