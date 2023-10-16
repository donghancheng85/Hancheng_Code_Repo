// templateClassTemplateTypeFriendship.cpp

#include <iostream>

template <typename T>
class Bank{
  std::string secret{"Import secret from the bank."};
  friend T;
};

class Account{
public:
  Account(){
    Bank<Account> bank;
    std::cout << bank.secret << std::endl;
  }
};

int main(){

  std::cout << std::endl;

  Account acc;

  std::cout << std::endl;

}
