#include <iostream>
#include <vector>

bool JumpGame(std::vector<int> nums)
{
    int currLast = nums.size()-1;
    for( int i = currLast-1; i > -1; --i)
    {
        // find if currLast reachable
        if (currLast - i <= nums[i])
            currLast = i;
    }

    if (currLast == 0)
        return true;

    return false;
}

int main()
{
    std::vector<int> nums {3, 2, 2, 0, 1, 4};
    std::cout << std::boolalpha;
    std::cout << JumpGame(nums) << "\n\n";
}
