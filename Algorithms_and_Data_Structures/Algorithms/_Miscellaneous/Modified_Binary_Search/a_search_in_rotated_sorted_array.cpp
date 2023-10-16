#include <algorithm>
#include <iostream>
#include <vector>

std::size_t BinarySearchRotated(std::vector<int> &nums, int target)
{
    std::size_t low{0};
    std::size_t high{nums.size() - 1};
    std::size_t mid = (low + high) / 2;

    while (low <= high)
    {
        if (target == nums[mid])
            return mid;

        if (target > nums[mid])
        {
            // second half is sorted
            if (nums[mid] <= nums[high])
            {
                // target is in sorted section
                if (target <= nums[high])
                {
                    auto result = std::lower_bound(nums.begin() + mid, nums.begin() + high + 1, target);
                    if (target == *result)
                        return std::distance(nums.begin(), result);
                    else
                        return -1;
                }
                // target is not is the sorted section, ignore this section
                high = mid - 1;
                mid = (low + high) / 2;
            }
        }
        else
        {
            // first half is sorted
            if (nums[low] <= nums[mid])
            {
                // target is in sorted section
                if (nums[low] <= target)
                {
                    auto result = std::lower_bound(nums.begin() + low, nums.begin() + mid + 1, target);
                    if (target == *result)
                        return std::distance(nums.begin(), result);
                    else
                        return -1;
                }
                // target is not in the sorted section, ignore this section
                low = mid + 1;
                mid = (low + high) / 2;
            }
        }
    }

    return -1;
}

int main()
{
    std::vector<int> myvec{4, 5, 6, 1, 2, 3};
    int target = 3;

    std::cout << BinarySearchRotated(myvec, target) << "\n\n";
}
