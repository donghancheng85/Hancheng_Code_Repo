#include <chrono>
#include <iostream>
#include <numeric>
#include <random>
#include <vector>
#include <future>

static const int NUM = 100000000;
constexpr int NUM_T = 4; // number of threads

long long getDotProduct(std::vector<int>& v, std::vector<int>& w){
  return std::inner_product(v.begin(), v.end(),
                             w.begin(),
                             0LL);
}

int main(){

  std::cout << std::endl;

  // get NUM random numbers from 0 .. 100
  std::random_device seed;

  // generator
  std::mt19937 engine(seed());

  // distribution
  std::uniform_int_distribution<int> dist(0, 100);

  // fill the vectors
  std::vector<int> v,  w;
  v.reserve(NUM);
  w.reserve(NUM);
  for (int i = 0; i< NUM; ++i){
    v.push_back(dist(engine));
    w.push_back(dist(engine));
  }

  // measure the execution time
  std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
  std::cout << "getDotProduct(v, w): " << getDotProduct(v, w) << std::endl;
  std::chrono::duration<double> dur  = std::chrono::system_clock::now() - start;
  std::cout << "Sequential Execution: "<< dur.count() << std::endl;

  // calculate in multiple threads
  std::cout << "4 threads calcuation: " << std::endl;
  start = std::chrono::system_clock::now();
  int v_size = v.size();
  auto fut1 = std::async([&v, &w, v_size](){
    return std::inner_product(&v[0], &v[v_size/4], &w[0], 0LL);
  });
  auto fut2 = std::async([&v, &w, v_size](){
    return std::inner_product(&v[v_size/4], &v[v_size/2], &w[v_size/4], 0LL);
  });
  auto fut3 = std::async([&v, &w, v_size](){
    return std::inner_product(&v[v_size/2], &v[3*v_size/4], &w[v_size/2], 0LL);
  });
  auto fut4 = std::async([&v, &w, v_size](){
    return std::inner_product(&v[3*v_size/4], &v[v_size], &w[3*v_size/4], 0LL);
  });
  std::cout << "four thread calculation: " << fut1.get()+fut2.get()+fut3.get()+fut4.get() << std::endl;
  dur  = std::chrono::system_clock::now() - start;
  std::cout << "Sequential Execution: "<< dur.count() << std::endl;


  std::cout << std::endl;

}
