// templateTypes.cpp

#include <iostream>
#include <string>

template<typename T>
struct Type{
  std::string getName() const {
    return "unknown";
  }
};

int main(){

  std::cout << std::boolalpha << std::endl;

  Type<float> tFloat;
  std::cout << "tFloat.getName(): " << tFloat.getName() << std::endl;

  std::cout << std::endl;

}
