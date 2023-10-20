#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

struct ContainsIntegers
{
  virtual ~ContainsIntegers() = default;
  virtual int sum() const = 0;
};

struct SingleValue : public ContainsIntegers
{
  int value{ 0 };

  SingleValue() = default;

  explicit SingleValue(const int value)
    : value{value}
  {
  }

  int sum() const override {return value;};
};

struct ManyValues : vector<int>, ContainsIntegers
{
  void add(const int value)
  {
    push_back(value);
  }

  int sum() const override { return std::accumulate(this->begin(), this->end(), 0); };
};

int sum(const vector<ContainsIntegers*> items);