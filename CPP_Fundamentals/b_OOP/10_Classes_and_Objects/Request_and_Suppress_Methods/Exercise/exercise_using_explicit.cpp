#include <iostream>

// your code goes here
class OnlyInt
{
public:
    OnlyInt() = default;
    explicit OnlyInt(int val): m_val(val){}

    template <typename T>
    OnlyInt(T val) = delete;

private:
    int m_val{0};
};

int main() {
  // test it here
  OnlyInt o1(5);

  //OnlyInt o2(5L); //error
}