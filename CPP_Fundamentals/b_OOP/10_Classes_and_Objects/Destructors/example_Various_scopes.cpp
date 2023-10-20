#include <iostream>

class HelloGoodBye{
public:
  HelloGoodBye(int i):numb(i){
    std::cout << "Hello from " << numb << ": "<< std::endl;
  }
  ~HelloGoodBye();
private:
  int numb;
};

HelloGoodBye::~HelloGoodBye(){
  std::cout << "Good Bye from : " <<  numb << std::endl;
}

void func(){
  HelloGoodBye helloGoodBye(5);
}

HelloGoodBye helloGoodBye(1);

int main(){

  std::cout << std::endl;

  HelloGoodBye helloGoodBye(2); // Hello from 2:

  std::cout << std::endl;

  HelloGoodBye* helloGoodByePtr = new HelloGoodBye(3); // Hello from 3:

  std::cout << std::endl;

  {
    HelloGoodBye helloGoodBye(4); // Hello from 4:
  }// Good Bye from: 4

  std::cout << std::endl;

  delete helloGoodByePtr; //Good Bye from: 3

  func(); // Hello from 5:
  // Good Bye from: 5
  std::cout << "--------- End of main ----------"  << std::endl;

}
// Good Bye from: 2