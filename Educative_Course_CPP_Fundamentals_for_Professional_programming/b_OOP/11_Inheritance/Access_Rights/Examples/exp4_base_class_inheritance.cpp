#include <iostream>
#include <string>

class Account{
public:

  Account() {std::cout << "Account ctor!!\n";}

  Account(double amt, std::string c): amount(amt), cur(c){
    std::cout << "Account:amount: " << amount << std::endl;
    std::cout << "Account:cur: " << cur << std::endl;
  }

private:
  double amount;
  std::string cur;
};

class BankAccount: public Account{
public:
  BankAccount(double amt, std::string n): Account(amt, "EUR"), name(n){
    std::cout << "BankAccount:name: "  << name << std::endl;
  }
private:
  std::string name;

};

int main(){

  std::cout << std::endl;

  Account acc(100.0, "USD");

  std::cout << std::endl;

  BankAccount bankAcc(200.0, "grimm");

  std::cout << std::endl;

}
