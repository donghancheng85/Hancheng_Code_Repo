#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct Token
{
  int value;

  Token(int value) : value(value) {}
};

struct Memento
{
  std::vector<std::shared_ptr<Token>> tokens;
};

struct TokenMachine
{
  std::vector<std::shared_ptr<Token>> tokens;

  Memento add_token(int value)
  {
    return add_token(std::make_shared<Token>(value));
  }

  // adds the token to the set of tokens and returns the
  // snapshot of the entire system

  // @note:The system shall not have any connection with the original token
  // which means that each tokem in the systen needs to have a deep copy
  // pf the token that it stored.
  Memento add_token(const std::shared_ptr<Token>& token)
  {
    if (token)
    {
      tokens.emplace_back(std::make_shared<Token>(token->value));
    }
    return {tokens};
  }

  // reverts the system to a state represented by the token
  void revert(const Memento& m)
  {
    tokens.clear();
    for (auto t : m.tokens)
      tokens.emplace_back(std::make_shared<Token>(t->value));
  }
};

int main()
{
    TokenMachine tm;
    Memento m1, m2;

    m1 = tm.add_token(12);
    m2 = tm.add_token(34);

    for (auto t : tm.tokens)
    {
        std::cout << t->value << "   ";
    }
    std::cout << "\n\n";
    
    //tm.revert(m1);
    for (auto t : tm.tokens)
    {
        std::cout << t->value << "   ";
    }
    std::cout << "\n\n";
}