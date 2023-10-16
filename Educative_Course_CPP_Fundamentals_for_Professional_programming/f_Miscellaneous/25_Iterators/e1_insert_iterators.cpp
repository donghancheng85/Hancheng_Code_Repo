#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main(){
  
  std::deque<int> deq{5, 6, 7, 10, 11, 12};
  std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

  std::copy(std::find(vec.begin(), vec.end(), 13), vec.end(), std::back_inserter(deq));

  for (auto d: deq) std::cout << d << " "; // 5 6 7 10 11 12 13 14 15
  std::cout<<std::endl;

  std::copy(std::find(vec.begin(), vec.end(), 8),
  std::find(vec.begin(), vec.end(), 10),
  std::inserter(deq, std::find(deq.begin(), deq.end(), 10)));
  for (auto d: deq) std::cout << d << " "; // 5 6 7 8 9 10 11 12 13 14 15
  std::cout<<std::endl;

  std::copy(vec.rbegin()+11, vec.rend(),
  std::front_inserter(deq));
  for (auto d: deq) std::cout << d << " "; // 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
  std::cout<<std::endl;
  
  return 0;
}