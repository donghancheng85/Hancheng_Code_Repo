#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> FindCorruptPair(std::vector<int>& nums)
{
    // Cyclic sort nums
    for(std::size_t i = 0; i < nums.size(); ++i)
    {
        while ((nums[i] != i+1) && (nums[i] != nums[nums[i]-1]))
        {
            std::swap(nums[i], nums[nums[i]-1]);
        }
    }

    for (std::size_t i=0; i < nums.size(); ++i)
    {
        if (i+1 != nums[i])
        {
            return {static_cast<int>(i+1), nums[i]};
        }
    }

    return {-1, -1};
}

int main()
{
    std::vector<int> nums {3,1,2,5,2};
    auto result = FindCorruptPair(nums);

    for (size_t i = 0; auto elem : result)
        std::cout << elem << (++i == result.size() ? "\n" : ", ");

    return 0;
}
