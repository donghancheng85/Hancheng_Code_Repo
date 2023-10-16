// templateFunctionsTemplates.cpp

#include <iostream>
#include <string>
#include <vector>

template <typename T>
void xchg(T& x, T& y){
  T t = x;
  x =y;
  y =t;
}

template <int N>
int nTimes(int n){
  return N * n;
}

int main(){

  std::cout << std::endl;

  bool t = true;
  bool f = false;
  std::cout << "(t, f):  (" << t << ", " << f << ") "<< std::endl;
  xchg(t, f);
  std::cout << "(t, f):  (" << t << ", " << f << ") "<< std::endl;

  std::cout << std::endl;

  int int2011 = 2011;
  int int2014 = 2014;
  std::cout << "(int2011, int2014):  (" << int2011 << ", " << int2014 << ") "<< std::endl;
  xchg(int2011, int2014);
  std::cout << "(int2011, int2014):  (" << int2011 << ", " << int2014 << ") "<< std::endl;

  std::cout << std::endl;

  std::string first{"first"};
  std::string second{"second"};
  std::cout << "(first, second):  (" << first << ", " << second << ") "<< std::endl;
  xchg(first, second);
  std::cout << "(first, second):  (" << first << ", " << second << ") "<< std::endl;

  std::cout << std::endl;
  std::vector<int> intVec1{1, 2, 3, 4, 5};
  std::vector<int> intVec2{5, 4, 3, 2, 1};

  std::cout << "vec1: ";
  for (auto v: intVec1)std::cout  << v << " ";
  std::cout << "\nvec2: ";
  for (auto v: intVec2)std::cout << v << " ";
  std::cout << std::endl;
  xchg(intVec1, intVec2);

  std::cout << "vec1: ";
  for (auto v: intVec1)std::cout  << v << " ";
  std::cout << "\nvec2: ";
  for (auto v: intVec2)std::cout << v << " ";
  std::cout << std::endl;


  std::cout << "\n\n";

  std::cout << "nTimes<5>(10): " << nTimes<5>(10) << std::endl;
  std::cout << "nTimes<10>(5): " << nTimes<10>(5) << std::endl;

  std::cout << std::endl;
}