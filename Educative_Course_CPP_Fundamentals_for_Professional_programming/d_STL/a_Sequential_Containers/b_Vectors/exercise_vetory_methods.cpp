#include <iostream>
#include <vector>

int main() {
  
  // write your code here
  // create a vector
  std::vector<int> intVec{1,2,3,4,5,6};
  
  // vector size and capacity
  std::cout << "init intVec size: " << intVec.size() << "\n";
  std::cout << "init intVec capacity: " << intVec.capacity() << "\n";

  // insert element to vector
  intVec.insert(intVec.end(), {4,4,4,4,7,7});
  intVec.push_back(5);
  intVec.push_back(5);
  // vector size and capacity
  std::cout << "after insert intVec size: " << intVec.size() << "\n";
  std::cout << "after insert intVec capacity: " << intVec.capacity() << "\n";

  // call shrink_to_fit
  intVec.shrink_to_fit();
  // check vector size and capacity again
  std::cout << "after shrink_to_fit intVec size: " << intVec.size() << "\n";
  std::cout << "after shrink_to_fit intVec capacity: " << intVec.capacity() << "\n";

}