#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
using namespace std;

int main(){
  std::vector<int> vec{1, 23, 3, 3, 3, 4, 5};
  std::deque<int> deq;

  // Start iterator bigger than end iterator
  std::copy(vec.begin()+2, vec.begin(), deq.begin());

  // Target container too small
  std::copy(vec.begin(), vec.end(), std::back_insert_iterator<std::deque<int>>(deq));

  std::cout << deq.size() << "\n\n";
  return 0;
}