#include <iostream>
#include <string>

class Abstract{
public:
    virtual ~Abstract() = 0;
};

Abstract::~Abstract(){}

class Concret: public Abstract{};

class HumanBeing{
public:
  HumanBeing(const std::string n): name(n){
    std::cout << name << " created." <<  std::endl;
  }

  virtual std::string getSex() const= 0;

private:
  std::string name;

};

class Man: public HumanBeing{
public:

  // using HumanBeing::HumanBeing;
  Man(const std::string n): HumanBeing(n){}

  std::string getSex() const override{
    return "male";
  }
};


class Woman: public HumanBeing{
public:

  // using HumanBeing::HumanBeing;
  Woman(const std::string n): HumanBeing(n){}

  std::string getSex() const override{
    return "female";
  }
};

int main(){

  std::cout << std::endl;

  // Abstract abstract;    // ERROR
  Concret concret;

  // HumanBeing humanBeing("grimm");   // ERROR

  Man schmidt("Schmidt");
  Woman huber("Huber");

  std::cout << "schmidt.getSex(): " <<  schmidt.getSex() << std::endl;
  std::cout << "huber.getSex(): " << huber.getSex() << std::endl;

  std::cout << std::endl;

}
