#include <iostream>
#include <ostream>

namespace Distance{
  class MyDistance{
    public:
      MyDistance(double i):m(i){}

        friend MyDistance operator +(const MyDistance& a, const MyDistance& b){
            return MyDistance(a.m + b.m);
        }
        friend MyDistance operator -(const MyDistance& a, const MyDistance& b){
            return MyDistance(a.m - b.m);
        }
        friend MyDistance operator *(double a, const MyDistance& b){
            return MyDistance(a * b.m);
        }
        friend MyDistance operator *(const MyDistance& a, double b){
            return MyDistance(a.m * b);
        }

        friend std::ostream& operator<< (std::ostream &out, const MyDistance& myDist){
            out << myDist.m << " m";
            return out;
        }
        
    private:
      double m;

  };

  namespace Unit{
        MyDistance operator "" _km(long double d){
        return MyDistance(1000*d);
        }
        MyDistance operator "" _m(long double m){
        return MyDistance(m);
        }
        MyDistance operator "" _dm(long double d){
        return MyDistance(d/10);
        }
        MyDistance operator "" _cm(long double c){
        return MyDistance(c/100);
        }
  }
}

using namespace Distance::Unit;

int main(){

    std:: cout << std::endl;

    Distance::MyDistance work = 30.0_km;
    Distance::MyDistance abbreviationToWork = 500.0_m;
    Distance::MyDistance workout = 5000.0_m;
    Distance::MyDistance shopping = 3000.0_m;

    auto myDistPerWeek = 4 * work * 2 - 3 * abbreviationToWork + workout + shopping;

    std::cout << "Travel Distance Per Week is: " << myDistPerWeek << "\n";

    std::cout << std::endl;

}

