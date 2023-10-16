#include <iostream>

/**
* Guidelines for NVI (Non-Virtual Interface)
* Guideline #1: Prefer to make interfaces nonvirtual, using Template Method design pattern.
* Guideline #2: Prefer to make virtual functions private.
* Guideline #3: Only if derived classes need to invoke the base implementation of a virtual function, 
* make the virtual function protected.
* Guideline #4: A base class destructor should be either public and virtual, or protected and nonvirtual.
* @link: https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-Virtual_Interface
*/

class Sort{
public:
  virtual void processData() final{ //Guideline #1
    readData_impl();
    sortData_impl();
    writeData_impl();
  }
  virtual ~Sort() = default; //Guideline #4
private:
  virtual void readData_impl(){} //Guideline #2
  virtual void sortData_impl() = 0;
  virtual void writeData_impl(){}
};


// Try using final and override

class QuickSort: public Sort{
private:
  void readData_impl() override { //Guideline #3
    std::cout << "readData" << std::endl;
  }
  void sortData_impl() override {
    std::cout <<  "sortData" << std::endl;
  }
  void writeData_impl() override {
    std::cout << "writeData" << std::endl;
  }
};


int main(){

  std::cout << std::endl;

  Sort* sort = new QuickSort; //or use shared/unique pointer
  sort->processData();

  std::cout << std::endl;
  delete sort;

}

