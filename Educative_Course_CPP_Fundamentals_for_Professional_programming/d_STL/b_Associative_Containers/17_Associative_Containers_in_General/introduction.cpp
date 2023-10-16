// orderedUnorderedComparison.cpp 
#include <iostream>
#include <map>
#include <unordered_map>

// std::map
int main(){
  std::map<std::string, int> m {{"Dijkstra", 1972}, {"Scott", 1976}};
  m["Ritchie"]= 1983;
  std::cout << m["Ritchie"];            // 1983
  std::cout<<"\n";
  
  for(auto p : m) std::cout << "{" << p.first << "," << p.second << "}";
                // {Dijkstra,1972},{Ritchie,1983},{Scott,1976}
  std::cout<<"\n";
  
  m.erase("Scott");
  for(auto p : m) std::cout << "{" << p.first << "," << p.second << "}";
                // {Dijkstra,1972},{Ritchie,1983}
  std::cout<<"\n";
  
  m.clear();
  std::cout << m.size() << std::endl;   // 0

  // std::unordered_map

  std::unordered_map<std::string, int> um {{"Dijkstra", 1972}, {"Scott", 1976}};
  um["Ritchie"]= 1983;
  std::cout << um["Ritchie"];          // 1983
  std::cout<<"\n";
  
  for(auto p : um) std::cout << "{" << p.first << "," << p.second << "}";
                 // {Ritchie,1983},{Scott,1976},{Dijkstra,1972}
  std::cout<<"\n";
  
  um.erase("Scott");
  for(auto p : um) std::cout << "{" << p.first << "," << p.second << "}";
                 // {Ritchie,1983},{Dijkstra,1972}
  std::cout<<"\n";
  
  um.clear();
  std::cout << um.size() << std::endl;  // 0
  
  return 0;
}