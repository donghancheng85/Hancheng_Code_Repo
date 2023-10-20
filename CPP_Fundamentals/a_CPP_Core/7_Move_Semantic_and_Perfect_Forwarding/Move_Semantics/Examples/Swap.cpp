#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
void swap(T& a, T& b){
    T tmp(std::move(a)); // copy constructor
    a = std::move(b); // copy assignment operator
    b = std::move(tmp); // copy assignment operator
}

struct MyData{
  std::vector<int> myData;

  MyData():myData({1, 2, 3, 4, 5}){}

  // copy semantic
  MyData(const MyData& m):myData(m.myData){
    std::cout << "copy constructor"  << std::endl;
  }

  MyData& operator=(const MyData& m){
    myData = m.myData;
    std::cout << "copy assignment operator"  << std::endl;
    return *this;
  }

};

int main(){

  std::cout << std::endl;

  MyData a, b;
  swap(a, b);

  std::cout << std::endl;

};