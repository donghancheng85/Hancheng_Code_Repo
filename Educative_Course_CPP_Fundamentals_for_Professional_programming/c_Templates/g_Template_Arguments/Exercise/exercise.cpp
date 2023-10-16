#include <initializer_list>
#include <iostream>
#include <list>
#include <vector>

template <typename T, template <typename, typename> class Cont = std::vector >
class Matrix{
public:
  explicit Matrix(std::initializer_list<T> inList): data(inList){
    for (auto d: data) std::cout << d << " ";
  }
  int getSize() const{
    return data.size();
  }

private:
  Cont<T, std::allocator<T>> data;

};

int main(){

  std::cout << std::endl;

  // Define myIntVec and myDoubleVec without specifying containers explicitly
  // Call getSize() function on it to check the result
  Matrix<int> myIntVec{1, 2, 3, 4, 5};
  std::cout<< "\n";
  std::cout << "myIntVec.getSize(): " << myIntVec.getSize() << "\n";

  Matrix<double> myDoubleVec{1.1, 2.2, 3.3};
  std::cout<< "\n";
  std::cout << "myDoubleVec.getSize(): " << myDoubleVec.getSize() << "\n";

  Matrix<std::string,std::list> myStringList{"one", "two", "three", "four"};
  std::cout << std::endl;
  std::cout << "myStringList.getSize(): " << myStringList.getSize() << std::endl;

  std::cout << std::endl;

}