#include <iostream>
#include <iterator>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>

int main(){
  std::vector<int> myIntVec;
  std::istream_iterator<int> myIntStreamReader(std::cin);
  std::istream_iterator<int> myEndIterator;

  // Possible input
  // 1
  // 2
  // 3
  // 4
  // z
  while(myIntStreamReader != myEndIterator){ 
    myIntVec.push_back(*myIntStreamReader);
    ++myIntStreamReader;
  }

  std::copy(myIntVec.begin(), myIntVec.end(), std::ostream_iterator<int>(std::cout, ":"));
          // 1:2:3:4:

  return 0;
}