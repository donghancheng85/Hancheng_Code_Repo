#include<thread>
#include<iostream>

int main(){ 
  std::string s{"C++11"};

  std::thread t1([&s]{ s+="334"; std::cout << s << std::endl;});
  t1.join();
  std::cout << s << std::endl;
  std::thread t2([&]{ std::cout << s << std::endl;});
  t2.detach();
}