#include <string>
#include <iostream>
using namespace std;

struct Person
{
  int id;
  string name;
};

class PersonFactory
{
public:
  Person create_person(const string& name)
  {
    /**
    * static variable that represent number of person added
    * @note: the variable will still be shared among all the
    * objects
    */
    static int s_id = 0;
    return Person{s_id++, name};
  }
};

int main()
{
    PersonFactory pf;
    Person p1 = pf.create_person("Jim");
    Person p2 = pf.create_person("Tom");
    Person p3 = pf.create_person("Peter");

    PersonFactory pf2;
    Person p4 = pf2.create_person("Sarah");

    std::cout << "\n";
}