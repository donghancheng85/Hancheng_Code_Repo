#include <iostream>
#include <functional>

// Write class templates for given commented code
// accept char
template <char c>
class AcceptChar
{
public:
  AcceptChar()
  {
    std::cout << "AcceptChar type is: " << typeid(c).name() << "\n";
  }
};

// accept a function non-type template parameter
template <void(*fuc)()>
class AcceptFunction
{
public:
  AcceptFunction()
  {
    std::cout << "AcceptFunction type is: " << typeid(fuc).name() << "\n";
  }
};

// accept a reference non-type template parameter
template <int &arr>
class AcceptReference
{
public:
  AcceptReference()
  {
    std::cout << "AcceptReference type is: " << typeid(arr).name() << "\n";
  }
};

// accept null ptur
template <std::nullptr_t* ptr = nullptr>
class AcceptNullptr
{
public:
  AcceptNullptr()
  {
    std::cout << "AcceptNullptr type is: " << typeid(ptr).name() << "\n";
  }
};

//the following 2 template parameters need to be defined like this
void myFunc(){}

//int arr[5] = {1,1,1,1,1};

int arr = 3;

int main() {
  // uncomment these lines after implementing codes

  AcceptChar<'c'> acceptChar;
  AcceptFunction< myFunc > acceptFunction;
  AcceptReference< arr > acceptReference;
  AcceptNullptr< nullptr > acceptNullptr;
}