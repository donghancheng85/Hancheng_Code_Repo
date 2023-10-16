// associativeContainerSearch.cpp 
#include <iostream>
#include <set>

int main(){
  std::multiset<int> mySet{3, 1, 5, 3, 4, 5, 1, 4, 4, 3, 2, 2, 7, 6, 4, 3, 6};

  for (auto s: mySet) std::cout << s << " "; // 1 1 2 2 3 3 3 3 4 4 4 4 5 5 6 6 7
  std::cout<<"\n";

  auto itr = mySet.begin();
  (std::advance(itr, 3));
  std::cout << *itr << "\n";
  
  mySet.erase(mySet.lower_bound(4), mySet.upper_bound(4));
  for (auto s: mySet) std::cout << s << " "; // 1 1 2 2 3 3 3 3 5 5 6 6 7
  std::cout<<"\n";
  
  std::cout << mySet.count(3) << std::endl; // 4
  std::cout << *mySet.find(3) << std::endl; // 3
  std::cout << *mySet.lower_bound(3) << std::endl; // 3
  std::cout << *mySet.upper_bound(3) << std::endl; // 5
  auto pair= mySet.equal_range(3);
  std::cout << "(" << *pair.first << "," << *pair.second << ")"; // (3,5)

  return 0;
}