#include <iostream>
#include <string>

// Implement with full and partial specialization
// Write your code here

class Account{
public:
  explicit Account(double b): balance(b){}
  double getBalance() const {
    return balance;
  }
private:
  double balance;
};

template<typename T>
struct Type{
  std::string getName() const {
    return typeid(T).name();
  }
};

template<typename T>
struct Type<T*>{
  std::string getName() const {
    return "pointer!";
  }
};

template<typename T>
struct Type<const T>{
  std::string getName() const {
    return "const!";
  }
};

template<>
struct Type<Account>{
  std::string getName() const {
    return "Account type!";
  }
};

template<>
struct Type<std::string>
{
    std::string getName() const {
    return "String type!";
  }
};

template<>
struct Type<int>
{
    std::string getName() const {
    return "integer!";
  }
};

template<>
struct Type<double>
{
    std::string getName() const {
    return "double!";
  }
};

template<>
struct Type<float>
{
    std::string getName() const {
    return "float!";
  }
};

int main(){

  std::cout << std::boolalpha << std::endl;

  // call objects for each defined templetes here

  // An example of float is given below which returns "unknown"
  Type<int> tInt;
  std::cout << "tInt.getName(): " << tInt.getName() << std::endl;

  Type<double> tDouble;
  std::cout << "tDouble.getName(): " << tDouble.getName() << std::endl;

  Type<float> tFloat;
  std::cout << "tFloat.getName(): " << tFloat.getName() << std::endl;
  
  Type<float*> tpFloat;
  std::cout << "tcFloat.getName(): " << tpFloat.getName() << std::endl;

  Type<const float> tcFloat;
  std::cout << "tcFloat.getName(): " << tcFloat.getName() << std::endl;
  
  Type<std::string> tString;
  std::cout << "tString.getName(): " << tString.getName() << std::endl;

  Type<Account> tAccount;
  std::cout << "tAccount.getName(): " << tAccount.getName() << std::endl;

  std::cout << std::endl;

}