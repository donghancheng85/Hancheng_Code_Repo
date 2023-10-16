#include <iostream>

class Account{
public:
  double getBalance() const {
    return balance;
  }
  void addAmount(double amount){
    balance += amount;
  }
private:
  double balance{0.0};
};

int main(){

  std::cout << std::endl;

  Account readWriteAccount;
  readWriteAccount.addAmount(50.0);
  std::cout << "readWriteAccount.getBalance(): " << readWriteAccount.getBalance() << std::endl; //50.0

  const Account readAccount;
  std::cout << "readAccount.getBalance(): " << readAccount.getBalance() << std::endl; //0.0

  std::cout << std::endl;

}