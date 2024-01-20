#include "MinStack.hpp"
#include <limits>

int MinStack::pop()
{
    int result = std::numeric_limits<int>::min();
    if (!mMainStack.empty())
    {
        result = mMainStack.top();
        mMainStack.pop();
        mMinStack.pop();
    }
    return result;
}

void MinStack::push(int value)
{
    mMainStack.push(value);

    if (mMinStack.empty() || value < mMinStack.top())
    {
        mMinStack.push(value);
    }
    else
    {
        int valueToBePushed = mMinStack.top();
        mMinStack.push(valueToBePushed);
    }
}

int MinStack::min()
{
    int result = std::numeric_limits<int>::min();
    if (!mMinStack.empty())
    {
        result = mMinStack.top();
    }
    return result;
}
