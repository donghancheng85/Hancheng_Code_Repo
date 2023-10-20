#include <cmath>
#include <iostream>

class MyHour{
public:
  MyHour(int hour){
    if (0 <= hour && hour <= 23) myHour = hour;
    else myHour = 0;
    std::cout << "myHour = " << myHour << std::endl;
  }

  MyHour(): MyHour(0){}

  MyHour(double hour):MyHour(static_cast<int>(ceil(hour))) {}

private:
  int myHour;
};

int main(){

  std::cout << std::endl;

  MyHour(10); //myHour = 10
  MyHour(100); //myHour = 0
  MyHour(); //myHour = 0
  MyHour(22.45); //myHour = 23

  std::cout << std::endl;

}