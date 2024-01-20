#include "MinStack.hpp"

int main()
{
    MinStack testStack;
    testStack.push(9);
    testStack.push(3);
    testStack.pop();
    testStack.push(4);
    testStack.pop();
    testStack.push(5);
    std::cout << testStack.min() << "\n\n";
}
