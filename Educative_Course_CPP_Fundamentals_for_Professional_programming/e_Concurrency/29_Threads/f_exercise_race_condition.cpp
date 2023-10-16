#include <chrono>
#include <iostream>
#include <thread>

class Sleeper{
  public:
    Sleeper(int& i_):i{i_}{};
    void operator() (int k, int sleeptime_mil){
      for (unsigned int j= 0; j <= 5; ++j){
        std::this_thread::sleep_for(std::chrono::milliseconds(sleeptime_mil));
        i += k;
      }
      std::cout << std::this_thread::get_id() << std::endl;
    }
  private:
    int& i;
};

int main(){

  std::cout << std::endl;

  int valSleeper= 1000;

  // Pass an argument here for sleep time variation
  std::thread t(Sleeper(valSleeper),10, 50);

  // detach thread after each execution to run independently
  t.detach();
  std::this_thread::sleep_for(std::chrono::milliseconds(200));
  std::cout << "valSleeper = " << valSleeper << std::endl;

  std::cout << std::endl;

}