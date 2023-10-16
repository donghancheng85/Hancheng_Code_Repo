#include <mutex>
#include <iostream>

class MySingleton{

  private:
    static std::once_flag of;
    static MySingleton* instance;
    MySingleton()= default;
    ~MySingleton()= default;

  public:
    MySingleton(const MySingleton&)= delete;
    MySingleton& operator=(const MySingleton&)= delete;

    // use call_once method to make sure thread executes once only

    static MySingleton* getInstance(){
      std::call_once(of, [](){
          instance= new MySingleton();
      });
      return instance;
    }
};

MySingleton* MySingleton::instance= nullptr;
std::once_flag MySingleton::of;


int main(){

  std::cout << std::endl;

  std::cout << "MySingleton::getInstance(): "<< MySingleton::getInstance() << std::endl;
  std::cout << "MySingleton::getInstance(): "<< MySingleton::getInstance() << std::endl;

  std::cout << std::endl;

}
