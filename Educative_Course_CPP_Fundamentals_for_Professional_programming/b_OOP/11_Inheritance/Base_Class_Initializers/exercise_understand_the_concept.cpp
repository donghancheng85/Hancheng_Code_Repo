#include <iostream>
#include <string>

class Account{ 
public:
  Account(double amount, std::string cur)
  {std::cout << "Account ctor called!!\n";}
};

class BankAccount: public Account{ 
public:
  BankAccount(double r, std::string cur): Account(r, cur)
  {std::cout << "BankAccount ctor called!!\n";}
};

class BankAccoutInher: public BankAccount{
public:
  BankAccoutInher(double r, std::string cur): BankAccount(r, cur)
  {std::cout << "BankAccountInher ctor called!!\n";}
};

int main()
{
    BankAccoutInher bai(1.1, "sss");
}