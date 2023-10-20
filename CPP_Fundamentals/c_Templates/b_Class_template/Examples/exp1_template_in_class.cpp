// templateClassTemplate.cpp

#include <iostream>

class Account{
public:
  explicit Account(double amount=0.0): balance(amount){}

  void deposit(double amount){
    balance+= amount;
  }

  void withdraw(double amount){
    balance-= amount;
  }
  
  double getBalance() const{
    return balance;
  }

private:
  double balance;
};

template <typename T, int N>
class Array{
public:
  Array()= default;
  int getSize() const;

private:
  T elem[N];
};

template <typename T, int N>
int Array<T,N>::getSize() const {
  return N;
}

int main(){

  std::cout << std::endl;

  Array<double,10> doubleArray;
  std::cout << "doubleArray.getSize(): " << doubleArray.getSize() << std::endl;

  Array<Account,1000> accountArray;
  std::cout << "accountArray.getSize(): " << accountArray.getSize() << std::endl;

  std::cout << std::endl;
}