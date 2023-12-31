#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
 
int main(){
 
  std::cout << std::endl;
   
  std::unordered_map<std::string, int> myMap{ {"Rainer", 1966}, {"Beatrix", 1966}, {"Juliette", 1997}, {"Marius", 1999} };
 
  for ( auto m: myMap) std::cout << "{" << m.first <<  ", " << m.second << "} ";
   
  std::cout << std::endl;
   
  auto mapItBegin= std::begin(myMap);
  std::cout << "{" << mapItBegin->first <<  ", " << mapItBegin->second << "}" << std::endl;
  auto mapIt= std::next(mapItBegin);
  std::cout << "{" << mapIt->first <<  ", " << mapIt->second << "}" << std::endl;
   
  auto dist= std::distance(mapItBegin, mapIt);
  std::cout << "std::distance(mapItBegin, mapIt): " << dist << std::endl;
   
  std::cout << std::endl;
   
  std::array<int, 10> myArr{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
   
  for ( auto a: myArr ) std::cout << a << " "; 
   
  std::cout << std::endl;
   
  auto arrItEnd= std::end(myArr); // end iterator is one place pass the end of the container
  auto arrIt= std::prev(arrItEnd);
  std::cout << *arrIt << std::endl;
   
  std::advance(arrIt, -5);
  std::cout << *arrIt << std::endl; // 4
   
  std::cout << std::endl;
 
}