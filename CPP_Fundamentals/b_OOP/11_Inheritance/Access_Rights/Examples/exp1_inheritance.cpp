#include <iostream>

class Account{

public:
   Account(double b): balance(b){}

   void deposit(double amt){
     balance += amt;
   }

   void withdraw(double amt){
     balance -= amt;
   }

   double getBalance() const {
     return balance;
   }

private:
   double balance;

};

class BankAccount: public Account{

public:
  // using Account::Account;
  BankAccount(double b): Account(b){}

  void addInterest(){
    deposit( getBalance()*0.05 );
  }
};

int main(){

  std::cout << std::endl;

  BankAccount bankAcc(100.0);
  bankAcc.deposit(50.0);
  bankAcc.deposit(25.15);
  bankAcc.withdraw(30);
  bankAcc.addInterest();

  std::cout << "bankAcc.getBalance(): " << bankAcc.getBalance() << std::endl;

  std::cout << std::endl;

}
