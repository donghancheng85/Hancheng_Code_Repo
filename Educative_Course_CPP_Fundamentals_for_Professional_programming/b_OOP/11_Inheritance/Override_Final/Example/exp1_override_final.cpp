#include <iostream>

class Sort{
public:
  virtual void processData(){
    readData();
    sortData();
    writeData();
  }
  // virtual ~Sort() = default;
private:
  virtual void readData(){}
  virtual void sortData() = 0;
  virtual void writeData(){}
};


class QuickSort: public Sort{
private:
  void readData() {
    std::cout << "readData" << std::endl;
  }
  void sortData(){
    std::cout <<  "sortData" << std::endl;
  }
  void writeData(){
    std::cout << "writeData" << std::endl;
  }
};


int main(){

  std::cout << std::endl;

  Sort* sort = new QuickSort;
  sort->processData();
  
  std::cout << std::endl;
  delete sort;
}

