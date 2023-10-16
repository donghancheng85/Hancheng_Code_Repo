#include <iostream>
#include <vector>
using namespace std;

/**
 * move it in vector vec. The move steps follows *it. If *it is position, move forward
 * or backward. If *it>0, then if std::distance(it, vec.end()-1) > *it, then it will move 
 * forward *it, else it=vec.begin() + (*it - std::distance(it, vec.end()))
*/
void moveIt(std::vector<int>::const_iterator& it, const std::vector<int>& vec)
{
    if (*it > 0)
    {
        if (vec.end()-1 - it >= *it)
            it += *it;
        else // loop around
        {
                //std::cout << vec.end() - it << "\n\n";
            it = vec.begin() + (*it - (vec.end() - it));
        }
    }
    else // *it < 0
    {
        if (it - vec.begin() > -(*it))
            it += *it;
        else
            it = vec.rbegin().base() + (*it - (vec.rend().base() - it));
    }
}

bool CircularArrayLoop(const std::vector<int>& nums)
{
    int maxNum = nums.size(); // max times of try
    int i = 0;

    while(i < maxNum)
    {
        auto slow = nums.begin() + i;
        auto fast = nums.begin() + i;
        bool direction = (*slow > 0);
        while(true)
        {
            auto temp = slow;
            moveIt(slow, nums);
            if (direction != (*slow > 0) || (temp == slow))
                break;
            temp = fast;
            moveIt(fast, nums);
            if (direction != (*fast > 0) || (temp == fast))
                break;
            temp = fast;
            moveIt(fast, nums);
            if (direction != (*fast > 0) || (temp == fast))
                break;
            if (slow == fast)
                return true;
        }
        i++;
    }
    return false;
}

int main()
{
    std::vector<int> vec {5, 4, -2, -1, 3};

    std::cout << std::boolalpha << CircularArrayLoop(vec) << "\n\n";

}