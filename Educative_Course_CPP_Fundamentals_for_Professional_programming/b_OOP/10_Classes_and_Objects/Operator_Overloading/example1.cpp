#include <iostream>

class Account{

public:
  explicit Account(double b): balance(b){}

  Account& operator += (double b){
    balance += b;
    return * this;
  }

  friend Account& operator += (Account& a, Account& b);
  friend std::ostream& operator << (std::ostream& os, const Account& a);

private:
  double balance;

};

Account& operator += (Account& a, Account& b){
   a.balance += b.balance;
   return a;
 }

std::ostream& operator << (std::ostream& os, const Account& a){
   os << a.balance;
   return os;
}

int main(){

  std::cout << std::endl;

  Account acc1(100.0);
  Account acc2(100.0);
  Account acc3(100.0);

  acc1 += 50.0;
  acc1 += acc1;

  acc2 += 50.0;
  acc2 += acc2;

  acc3.operator += (50.0);
  //acc3.operator += (acc3);   ERROR, this is not the friend function

  std::cout << "acc1: " << acc1 << std::endl;
  std::cout << "acc2: " << acc2 << std::endl;

  std::cout << std::endl;

}