// templateSpecializationFull.cpp

#include <iostream>
#include <string>

template <typename T>
T min(T fir, T sec){
  return (fir < sec) ? fir : sec;
}

template <>
bool min<bool>(bool fir, bool sec){
  return fir & sec;
}

int main(){

  std::cout << std::boolalpha << std::endl;

  std::cout << "min(3.5, 4.5): "  << min(3.5, 4.5) << std::endl;
  std::cout << "min<double>(3.5, 4.5): "  << min<double>(3.5, 4.5) << std::endl;

  std::cout << "min(true, false): "  << min(true, false) << std::endl;
  std::cout << "min<bool>(true, false): "  << min<bool>(true, false) << std::endl;

  std::cout << std::endl;

}
