#include <iostream>
#include <string>
#include <vector>

int FindMissingNumber(std::vector<int> nums)
{
    int N = nums.size();

    // Traverse nums from begin to the end, and put the number at the index it suppost to be
    for (std::size_t i = 0; i < N; ++i)
    {
        // check if the element is equal to its index
        if (i != nums[i] && nums[i] < N)
        {
            // swap to the "correct position" if nums[i] < N, or keep its position
            while (nums[i] < N && i != nums[i])
            {
                std::swap(nums[i], nums[nums[i]]);
            }
        }
    }

    // Traverse nums again to find the missing number
    for (std::size_t i = 0; i < N; ++i)
    {
        if (i != nums[i])
            return i;
    }

    return N;
}

int main()
{
    std::vector<int> nums{1,4,5,6,8,2,0,7};

    std::cout << FindMissingNumber(nums) << "\n\n";
}
