#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CombinationLock
{
    std::vector<int> combination;
    
    //state transition functions
    void on_locked(int digit);
    void on_inputing(int digit);
public:
    std::string status;
    enum State
    {
        LOCKED,
        INPUTING,
        OPEN,
        ERROR
    } state{LOCKED};

    CombinationLock(const std::vector<int> &combination) : combination(combination) {
      status = "LOCKED";
      state = LOCKED;
    }

    void enter_digit(int digit)
    {
      switch (state)
      {
      case LOCKED:
        on_locked(digit);
        break;
      
      case INPUTING:
        on_inputing(digit);
        break;
      
      case OPEN:
      case ERROR:
      default:
        break;
      }
    }
};

void CombinationLock::on_locked(int digit)
{
  if (digit == combination[0])
  {
    status = std::to_string(digit);
    state = INPUTING;
  }
  else
  {
    status = "ERROR";
    state = ERROR;
  }
}

void CombinationLock::on_inputing(int digit)
{
  if (digit == combination.at(status.length())) // digit matches the input
  {
    std::cout << "The input digit \"" << digit << "\" matched the combination!\n";
    if (digit == *combination.rbegin()) // digit is the last match
    {
      status = "OPEN";
      state = OPEN;
      return;
    }
    status += std::to_string(digit);
  }
  else // digit is wrong
  {
    status = "ERROR";
    state = ERROR;
  }
}


int main()
{
    CombinationLock cl({1,2,3});
    std::cout << cl.status << "\n";
    cl.enter_digit(2);
    std::cout << cl.status << "\n";
    cl.enter_digit(2);
    std::cout << cl.status << "\n";
    cl.enter_digit(2);
    std::cout << cl.status << "\n";
}
