// forwardList.cpp 
#include <iostream>
#include <algorithm>
#include <forward_list>

using std::cout;

int main(){
  std::forward_list<int> forw;
  std::cout << forw.empty() << std::endl; // 1 (1 denoted true)

  forw.push_front(7);
  forw.push_front(6);
  forw.push_front(5);
  forw.push_front(4);
  forw.push_front(3);
  forw.push_front(2);
  forw.push_front(1);
  for (auto i: forw) cout << i << " "; // 1 2 3 4 5 6 7
  cout<<"\n";

  // Accessing arbitrary element (5th)
  auto f_itr = forw.begin();
  std::advance(f_itr, 4);
  std::cout << "5th element is: " <<*f_itr << "\n";

  /*add or remove element*/
  // add at 6th position
  f_itr++;
  forw.insert_after(f_itr, 101010);
  for (auto i: forw) cout << i << " ";
  std::cout << "\n";
  
  // remove at 3th position
  auto f_itr1 = forw.begin();
  std::advance(f_itr1, 1);
  forw.erase_after(f_itr1);
  std::cout << "After remove the 3th position: \n";
  for (auto i: forw) cout << i << " ";
  std::cout << "\n";
  std::cout << "After remove the 3th position, the element at f_itr1 is: \n";
  std::cout << *f_itr1 << "\n"; // 2

  /*We can only move forward with the iterator.*/
  // f_itr1--; Error
  
  return 0;
}