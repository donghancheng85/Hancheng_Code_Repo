#include <functional>
#include <iostream>

std::function<int(int)> makeLambda(int a){    
    return [a](int b){ return a + b; };
}

int main(){
    
    auto add5 = makeLambda(5);      
    
    auto add10 = makeLambda(10);      
    
    add5(10) == add10(5);

    auto res_add5 = add5(3);
    auto res_add10 = add10(3);
    
    std::cout << "add5(3) = " << res_add5 << "\n";
    std::cout << "add10(3) = " << res_add10 << "\n";
}