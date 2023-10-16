#include <iostream>
#include <vector>

int FindDuplicate(const std::vector<int>& nums)
{
    // fist traverse, find the intersection point
    auto slow = nums[0];
    auto fast = nums[0];

    while (true)
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
        
        if(slow == fast)
            break;
    }

    // second traverse, find the duplicate element
    slow = nums[0];

    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return fast;
}

int main()
{
    std::vector<int> myvec {1,3,6,2,7,3,5,4};

    std::cout << FindDuplicate(myvec) << "\n\n";
}