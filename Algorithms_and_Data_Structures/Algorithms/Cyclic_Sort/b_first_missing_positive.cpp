#include <iostream>
#include <vector>
#include <algorithm>

int SmallestMissingPositiveInteger(std::vector<int> nums)
{
    std::size_t RANGE = nums.size();

    // loop all the elements in nums and put them into correct position
    // i.e. index - 1 = element value
    for (std::size_t i=0; i < RANGE; ++i)
    {
        // ignore number that negitive or more than RANGE (no way to put them in position)
        if (nums[i] > 0 && nums[i] <= RANGE)
        {
            while (nums[i] != i+1 && nums[i] > 0 && nums[i] < RANGE)
            {
                std::swap(nums[i], nums[nums[i]-1]);
            }
        }
    }

    // loop all the elements again and find the smalles missing positive integer
    for (std::size_t i=0; i < RANGE; ++i)
    {
        if (nums[i] != i+1)
            return i+1;
    }

    return RANGE+1;
}

int main()
{
    std::vector<int> nums{1,4,5,6,8,2,0,7};


}
