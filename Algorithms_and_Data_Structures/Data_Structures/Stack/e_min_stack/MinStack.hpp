#include <iostream>
#include <stack>

class MinStack
{
public:
    // ctor
    MinStack() = default;

    // removes and returns value from stack
    int pop();

    // pushes value into the stack
    void push(int value);

    // returns maximum value in O(1)
    int min();

private:
    std::stack<int> mMainStack;
    std::stack<int> mMinStack;
};
