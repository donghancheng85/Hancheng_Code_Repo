#include <iostream>

class Account{
public:

  Account(double amt):amount(amt){}

  double getBalance() const {
    return amount;
  }

private:
  double amount;
};

class BankAccount: virtual public Account{
public:
  BankAccount(double amt): Account(amt){}
};

class WireAccount: virtual public Account{
public:
  WireAccount(double amt): Account(amt){}
};

class CheckingAccount: public BankAccount, public WireAccount{
public:
  // CheckingAccount(double amt): BankAccount(amt), WireAccount(amt){}
  CheckingAccount(double amt): BankAccount(amt), WireAccount(amt),Account(amt){}
};

int main(){

  std::cout << std::endl;

  CheckingAccount checkAccount(100.0);
  std::cout << "checkAccount.getBalance(): " << checkAccount.getBalance() << std::endl;

  std::cout << "checkAccount.BankAccount::getBalance(): "  <<  checkAccount.BankAccount::getBalance()   <<  std::endl;
  std::cout << "checkAccount.WireAccount::getBalance(): "  <<  checkAccount.WireAccount::getBalance()   <<  std::endl;

  std::cout << std::endl;

}
