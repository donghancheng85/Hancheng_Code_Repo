// templatePerfectForwarding.cpp

#include <iostream>
#include <utility>

template<typename T, typename ... Args>
T createT(Args&& ... args){
  return T(std::forward<Args>(args) ...);
}

struct MyStruct{
  MyStruct(int&, double&, double&&){}
  friend std::ostream& operator<< (std::ostream& out, const MyStruct&){
      out << "MyStruct" << std::endl;
      return out;
  }
};

int main(){

  std::cout << std::endl;

  double myDouble= createT<double>();
  std::cout << "myDouble: " << myDouble << std::endl; // 0.0

  int myInt= createT<int>(1);
  std::cout << "myInt: " << myInt << std::endl; // 1

  std::string myString= createT<std::string>("My String");
  std::cout << "myString: "  << myString << std::endl; //My Strinjg

  MyStruct myStruct= createT<MyStruct>(myInt, myDouble, 3.14);
  std::cout << "myStruct: "  << myStruct << std::endl; // MyStruct

  std::cout << std::endl;
}