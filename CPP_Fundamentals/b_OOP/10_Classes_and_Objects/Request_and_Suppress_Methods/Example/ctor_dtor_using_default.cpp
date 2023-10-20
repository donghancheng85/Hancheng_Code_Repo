#include <iostream>

class SomeType{
  public:

  // state the compiler generated default constructor
  SomeType() = default;

  // constructor for int
  SomeType(int value){
    std::cout << "SomeType(int) " << std::endl;
  };

  // explicit Copy Constructor
  explicit SomeType(const SomeType&) = default;

  // virtual destructor
  virtual ~SomeType() = default;

};

int main(){

  std::cout << std::endl;

  SomeType someType;
  SomeType someType2(2);
  SomeType someType3(someType2);

  std::cout << std::endl;

}
