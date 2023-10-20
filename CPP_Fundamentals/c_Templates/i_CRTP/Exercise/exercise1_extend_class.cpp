#include <iostream>
#include <string>

template<class Derived>
class Relational{};

// Relational Operators

template <class Derived>
bool operator > (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);     
    Derived const& d2 = static_cast<Derived const&>(op2); 
    return d2 < d1;
}

template <class Derived>
bool operator == (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);     
    Derived const& d2 = static_cast<Derived const&>(op2); 
    return !(d1 < d2) && !(d2 < d1);
}

template <class Derived>
bool operator != (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);     
    Derived const& d2 = static_cast<Derived const&>(op2); 
    return (d1 < d2) || (d2 < d1);
}

template <class Derived>
bool operator <= (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);     
    Derived const& d2 = static_cast<Derived const&>(op2); 
    return (d1 < d2) || (d1 == d2);
}

template <class Derived>
bool operator >= (Relational<Derived> const& op1, Relational<Derived> const & op2){
    Derived const& d1 = static_cast<Derived const&>(op1);     
    Derived const& d2 = static_cast<Derived const&>(op2); 
    return (d1 > d2) || (d1 == d2);
}

// Implement a person class here

// Person
class Person : public Relational<Person>
{
public:
    explicit Person(std::string f, std::string l):
        firstN(f),
        lastN(l)
    {};

    friend bool operator < (const Person& p1, const Person& p2)
    {
        return (p1.firstN != p2.firstN)? (p1.firstN < p2.firstN): (p1.lastN < p2.lastN);
    }
private:
    std::string firstN;
    std::string lastN;
};

// Apple

class Apple:public Relational<Apple>{
public:
    explicit Apple(int s): size{s}{};
    friend bool operator < (Apple const& a1, Apple const& a2){
        return a1.size < a2.size;
    }
private:
    int size;
};

// Man

class Man:public Relational<Man>{
public:
    explicit Man(const std::string& n): name{n}{}
    friend bool operator < (Man const& m1, Man const& m2){
        return m1.name < m2.name;
    }
private:
    std::string name;
};

int main(){
  
  std::cout << std::boolalpha << std::endl;
  
  // Call Person class object here checks them for all relational operaotrs
  Person p1{"Jim", "mmkk"};
  Person p2{"Jim", "mmkk"};

  std::cout << "p1 < p2: " << (p1 < p2) << std::endl;
  std::cout << "p1 > p2: " << (p1 > p2) << std::endl;
  std::cout << "p1 == p2: " << (p1 == p2) << std::endl;
  std::cout << "p1 != p2: " << (p1 != p2) << std::endl;
  std::cout << "p1 <= p2: " << (p1 <= p2) << std::endl;
  std::cout << "p1 >= p2: " << (p1 >= p2) << std::endl;
  
  std::cout << std::endl;
    
}
