#include <functional>
#include <iostream>
#include <memory>
using namespace std;

class Singleton
{
public:
  static Singleton* instance()
  {
    static Singleton s_instance;
    return &s_instance;
  }

  Singleton(const Singleton&) = delete;
  Singleton& operator = (const Singleton&) = delete;

private:
  Singleton() = default;
};

struct SingletonTester
{
  template <typename T>
  bool is_singleton(function<T*()> factory)
  {
    if (factory() == nullptr)
    {
        return false;
    }
    return (factory() == factory());
  }
};

int main()
{
  SingletonTester st;

  std::function<Singleton*()> f = Singleton::instance;
  std::function<int*()> int_f = []{return new int{};};

  bool b = st.is_singleton<Singleton>(Singleton::instance);

  std::cout << std::boolalpha
            << b << "\n\n";

}