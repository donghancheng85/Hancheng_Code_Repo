#include <algorithm>
#include <iostream>
#include <vector>

class SumMe{
public:

  SumMe(): sum(0){};

  void operator()(int x){
    sum += x;
  }

  int getSum() const {
    return sum;
  }
private:
  int sum;
};

int main(){

  std::cout << std::endl;

  std::vector<int> intVec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  
  int sum{0};
  auto sum_lambda = [&sum](int ele){ sum += ele; };

  // Use a lambda function here and class sumMe is no longer needed
  std::for_each(intVec.begin(), intVec.end(), sum_lambda);
  std::cout << "use sum_lambda: " << sum << std::endl;

  std::cout << std::endl;

}
