#include <iostream>
#include <string>
#include <utility>
#include <vector>

template <typename T, typename ...T1>
T create(T1&& ...t1){
  return T(std::forward<T1>(t1)...);
}

struct MyStruct{
  MyStruct(int i,double d,std::string s){}
};

int main(){

  std::cout << std::endl;

  // Lvalues
  int five=5;
  int myFive= create<int>(five);
  std::cout << "myFive: "  << myFive << std::endl;

  std::string str{"Lvalue"};
  std::string str2= create<std::string>(str);
  std::cout << "str2: " << str2 << std::endl;

  // Rvalues
  int myFive2= create<int>(5);
  std::cout << "myFive2: " << myFive2 << std::endl;

  std::string str3= create<std::string>(std::string("Rvalue"));
  std::cout << "str3: " << str3 << std::endl;

  std::string str4= create<std::string>(std::move(str3));
  std::cout << "str4: " << str4 << std::endl;

  MyStruct mystruct = create<MyStruct>(3, 1.1, "sfee");
  std::vector<int> myvec = create<std::vector<int>, std::initializer_list<int>>({3,1,5,6});

  std::cout << "myvec[1] = " << myvec[1] << "\n";

  std::cout << std::endl;

};