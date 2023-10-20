// sharedPtr.cpp

#include <iostream>
#include <memory>

using std::shared_ptr;

struct MyInt{
  MyInt(int v):val(v){
    std::cout << "  Hello: " << val << std::endl;
  }
  ~MyInt(){
    std::cout << "  Good Bye: " << val << std::endl;
  }
  int val;
};

int main(){

  std::cout << std::endl;

  shared_ptr<MyInt> sharPtr(new MyInt(1998)); // Hello: 1998
  std::cout << "    My value: " << sharPtr->val << std::endl; //1998
  std::cout << "sharedPtr.use_count(): " << sharPtr.use_count() << std::endl; //1


  {
    shared_ptr<MyInt> locSharPtr(sharPtr);
    std::cout << "locSharPtr.use_count(): " << locSharPtr.use_count() << std::endl; //2
  }
  std::cout << "sharPtr.use_count(): "<<  sharPtr.use_count() << std::endl; //1

  shared_ptr<MyInt> globSharPtr= sharPtr;
  std::cout << "sharPtr.use_count(): "<<  sharPtr.use_count() << std::endl; //2
  globSharPtr.reset();
  std::cout << "sharPtr.use_count(): "<<  sharPtr.use_count() << std::endl; // 1

  sharPtr= shared_ptr<MyInt>(new MyInt(2011)); // Hello: 2011, Good Bye: 1998

  std::cout << std::endl;
  
} // Good Bye: 2011