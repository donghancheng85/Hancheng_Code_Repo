#include <iostream>
#include <vector>
using namespace std;

struct Command
{
  enum Action { deposit, withdraw } action;
  int amount{0};
  bool success{false};
};

struct Account
{
  int balance{0};

  void process(Command& cmd)
  {
    switch (cmd.action)
    {
    case Command::Action::deposit:
        balance += cmd.amount;
        cmd.success = true;
        break;
    
    case Command::Action::withdraw:
        if(balance - cmd.amount >= 0)
        {
            balance -= cmd.amount;
            cmd.success = true;
        }
        else
            cmd.success = false;
        break;
    
    default:
        break;
    }
  }
};


int main()
{
    Account acc{100};
    Command cmd1{Command::Action::deposit, 30 , false};
    Command cmd2{Command::Action::deposit, 70 , false};
    Command cmd3{Command::Action::withdraw, 150 , false};
    Command cmd4{Command::Action::withdraw, 150 , false};
    std::vector<Command*> cmdVec{&cmd1, &cmd2, &cmd3, &cmd4};

    for(auto cmd : cmdVec)
        acc.process(*cmd);

    std::cout << boolalpha;
    std::cout << acc.balance << "\n";
    std::cout << cmd4.success << "\n";

}