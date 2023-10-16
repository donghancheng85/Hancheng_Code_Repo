#include <iostream>

class Account{
public:
  constexpr Account(int amou): amount(amou){}
  constexpr double getAmount() const {
    return amount;
  }
  constexpr double getAccountFees() const {
    return 0.05 * getAmount();
  }
private:
  double amount;
};

int main(){

  std::cout << std::endl;

  constexpr Account accConst(15);
  constexpr double amouConst = accConst.getAmount();
  std::cout << "amouConst: " << amouConst << std::endl;
  std::cout << "accConst.getAccountFees(): " << accConst.getAccountFees() << std::endl;
  // constexpr double f = accConst.getAccountFees();
  std::cout << std::endl;

  Account accDyn(15);
  double amouDyn = accDyn.getAmount();
  std::cout << "amouDyn: " << amouDyn << std::endl;
  std::cout << "accDyn.getAccountFees(): " << accDyn.getAccountFees() << std::endl;

  std::cout << std::endl;

}
