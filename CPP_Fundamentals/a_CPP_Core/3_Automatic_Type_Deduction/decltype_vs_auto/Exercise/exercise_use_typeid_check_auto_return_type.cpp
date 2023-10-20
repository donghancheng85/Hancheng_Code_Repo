#include <iostream>
#include <typeinfo>

template<typename T1, typename T2>
auto add(T1 first, T2 second) -> decltype(first + second){
    return first + second;
}
using namespace std::string_literals;

int main(){
    // std::cout << typeid( add(1, false) ).name() << std::endl; 
    // std::cout << typeid( add('a', 1) ).name() << std::endl; 
    // std::cout << typeid( add(false, false) ).name() << std::endl; 
    // std::cout << typeid( add(true, 3.14) ).name() << std::endl; 
    // std::cout << typeid( add(1, 4.0) ).name() << std::endl;
    std::cout << typeid( add(1.0f, 4.0) ).name() << std::endl;
    std::cout << typeid( add(10LL, 4.0f) ).name() << std::endl;
    int a;
}