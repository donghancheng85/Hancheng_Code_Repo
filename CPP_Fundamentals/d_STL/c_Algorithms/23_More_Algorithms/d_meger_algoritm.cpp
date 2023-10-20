#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>
 
int main(){
 
  std::cout << std::boolalpha;
 
  std::vector<int> vec1{1, 1, 4, 3, 5, 8, 6, 7, 9, 2};
  std::vector<int> vec2{1, 2, 3};
  
  std::cout << "vec1:\t\t\t\t\t";
  for (auto v: vec1) std::cout << v << " ";
  std::cout << std::endl;
  //vec1:	1 1 4 3 5 8 6 7 9 2 
  std::cout << "vec2:\t\t\t\t\t";
  for (auto v: vec2) std::cout << v << " ";
  std::cout << std::endl;
  //vec2:	1 2 3 
  
  std::sort(vec1.begin(), vec1.end());
  std::vector<int> vec3(vec1);
  
  std::cout << std::endl;
  std::cout << "vec1 includes vec2: " << std::includes(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()) << std::endl;
  //vec1 includes vec2: true
  std::cout << std::endl;
  
  vec1.reserve(vec1.size() + vec2.size());
  vec1.insert(vec1.end(), vec2.begin(), vec2.end());
  
  std::cout << "vec1:\t\t\t\t\t";
  for (auto v: vec1) std::cout << v << " "; 
  std::cout << std::endl;
   
  std::inplace_merge(vec1.begin(), vec1.end() - vec2.size(), vec1.end());  
  std::cout << "vec1:\t\t\t\t\t";
  for ( auto v: vec1 ) std::cout << v << " ";
   
  std::cout << "\n\n";
   
  vec2.push_back(10);
   
  std::cout << "vec3:\t\t\t\t\t\t";
  for (auto v: vec3) std::cout <<  v << " ";
  std::cout << std::endl;
  std::cout << "vec2:\t\t\t\t\t";
  for (auto v: vec2) std::cout << v << " ";
   
  std::vector<int> res;
  std::set_union(vec3.begin(), vec3.end(), vec2.begin(), vec2.end(),
         std::back_inserter(res));
  std::cout << "\n" << "set_union:\t\t\t\t";
  for (auto v : res) std::cout << v << " ";
   
  res={};
  std::set_intersection(vec3.begin(), vec3.end(), vec2.begin(), vec2.end(),
         std::back_inserter(res));
  std::cout << "\n" << "set_intersection:\t\t\t";
  for (auto v : res) std::cout << v << " ";
   
   
  res={};
  std::set_difference(vec3.begin(), vec3.end(), vec2.begin(), vec2.end(),
         std::back_inserter(res));
  std::cout << "\n" << "set_difference:\t\t\t";
  for (auto v : res) std::cout << v << " ";
   
  res={};
  std::set_symmetric_difference(vec3.begin(), vec3.end(), vec2.begin(), vec2.end(),
         std::back_inserter(res));
  std::cout << "\n" << "set_symmetric_difference:\t";
  for (auto v : res) std::cout << v << " ";
   
 
  std::cout << "\n\n";
 
}