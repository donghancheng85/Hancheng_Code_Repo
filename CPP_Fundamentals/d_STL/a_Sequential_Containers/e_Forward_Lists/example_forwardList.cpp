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

  forw.erase_after(forw.before_begin());  
  cout<< forw.front(); // 2
  cout<<"\n";

  std::forward_list<int> forw2;
  forw2.insert_after(forw2.before_begin(), 1);
  forw2.insert_after(++forw2.before_begin(), 2);
  forw2.insert_after(++(++(forw2.before_begin())), 3);
  forw2.push_front(1000);
  for (auto i= forw2.cbegin();i != forw2.cend(); ++i) cout << *i << " ";  // 1000 1 2 3
  cout<<"\n";
  
  auto IteratorTo5= std::find(forw.begin(), forw.end(), 5);
  forw.splice_after(IteratorTo5, std::move(forw2));
  for (auto i= forw.cbegin(); i != forw.cend(); ++i) cout << *i << " ";  // 2 3 4 5 1000 1 2 3 6 7
  cout<<"\n";
  
  forw.sort();
  for (auto i= forw.cbegin(); i != forw.cend(); ++i) cout << *i << " ";  
    // 1 2 2 3 3 4 5 6 7 1000
  cout<<"\n";
  
  forw.reverse();
  for (auto i= forw.cbegin(); i != forw.cend(); ++i) cout << *i << " ";  
    // 1000 7 6 5 4 3 3 2 2 1
  cout<<"\n";
  
  forw.unique();
  for (auto i= forw.cbegin(); i != forw.cend(); ++i) cout << *i << " ";  
    // 1000 7 6 5 4 3 2 1
  cout<<"\n";
  
  return 0;
}