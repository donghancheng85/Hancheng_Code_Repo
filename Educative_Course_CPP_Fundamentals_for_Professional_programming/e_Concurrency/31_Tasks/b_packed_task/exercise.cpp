// packagedTask.cpp

#include <utility>
#include <future>
#include <iostream>
#include <thread>
#include <deque>

class SumUp{
  public:
    int operator()(int beg, int end){
      long long int sum{0};
      for (int i = beg; i < end; ++i ) sum += i;
      return sum;
    }
};

int main(){

  std::cout << std::endl;

  int NUM = std::thread::hardware_concurrency();
  std::cout << NUM << "\n";
  std::deque<std::future<int>> q_fut;
  std::deque<std::packaged_task<int(int, int)>> q_pt;

  // create packed_tasks and push them into deque
  for (int i=0; i < NUM;  i++)
  {
    std::packaged_task<int(int, int)> pt(SumUp{});
    q_fut.push_back(pt.get_future());
    q_pt.push_back(std::move(pt));
  }
  
  int begin{1};
  int increment{2500};
  int end = begin + increment;
  
  begin = 1;
  increment = 10000/NUM;
  end = begin + increment;
  while (!q_pt.empty())
  {
    std::packaged_task<int(int, int)> myTask = std::move(q_pt.front());
    q_pt.pop_front();
    std::thread s_t(std::move(myTask), begin, end);
    begin = end;
    end += increment;
    s_t.detach();
  }

  // get the result
  int result{0};
  while (!q_fut.empty())
  {
    auto fut = std::move(q_fut.front());
    q_fut.pop_front();
    result += fut.get();
  }


  std::cout << "sum of 0 .. 10000 = " << result << std::endl;

  std::cout << std::endl;

}