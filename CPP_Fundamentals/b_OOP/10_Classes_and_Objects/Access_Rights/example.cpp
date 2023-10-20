#include <iostream>

class Account{

public:
   Account(double b): balance(b){
     ++Account::transactions;
   }

   void deposit(double amt){
     balance = calcBalance(amt);
   }

   void withdraw(double amt){
     balance = calcBalance(-amt);
   }

   double getBalance() const {
     return balance;
   }


   static int transactions;

private:

   double calcBalance(double amt){
     ++Account::transactions;
     return balance += amt;
   }

   double balance;

};
int Account::transactions= 0;


int main(){

  std::cout << std::endl;

  Account acc(100.0);
  acc.deposit(50.0);
  acc.deposit(25.15);
  acc.withdraw(30);

  std::cout << "acc.getBalance(): " << acc.getBalance() << std::endl;
  std::cout << "Account::transactions: " << Account::transactions << std::endl;

  std::cout << std::endl;

}
