#include <algorithm>
#include <iostream>
#include <vector>

template <typename T, int N>
class Array{

public:
  Array()= default;
  
  // Define a friend of itself, means classes of the same template can access each other's private members
  template <typename U, int M> 
  friend class Array;

  template <typename T2>
  Array<T, N>& operator=(const Array<T2, N>& arr){
	  static_assert(std::is_convertible<T2, T>::value, "Cannot convert source type to destination type!");
      elem.clear();
	  elem.insert(elem.begin(), arr.elem.begin(), arr.elem.end());
	  return *this;
  }

  int getSize() const;
  // you need to make the `elem` private and then run it
private:
  std::vector<T> elem;
};

template <typename T, int N>
int Array<T, N>::getSize() const {
  return N;
}


int main(){

  // uncomment these line after the above implementation
  
  Array<double, 10> doubleArray{};
  Array<int, 10> intArray{};

  doubleArray = intArray;


}