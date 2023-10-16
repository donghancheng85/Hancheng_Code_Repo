#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> NextGreaterElement(const std::vector<int> &nums1, const std::vector<int> &nums2)
{
    // use stack to make sure the checked number is always on the right of current number
    // use unordered_map to store the next greater number of current number
    std::vector<int> rightNumStack;
    std::unordered_map<int, int> nextGreaterNumMap;

    for (auto num : nums2)
    {
        while (!rightNumStack.empty() && num > rightNumStack.back())
        {
            int key = rightNumStack.back();
            nextGreaterNumMap[key] = num;
            rightNumStack.pop_back();
        }
        rightNumStack.push_back(num);
    }

    std::vector<int> result;
    result.reserve(nums1.size());

    for (auto num1 : nums1)
        (nextGreaterNumMap.count(num1) != 0) ? result.push_back(nextGreaterNumMap[num1]) : result.push_back(-1);

    return result;
}

int main()
{
    std::vector<int> nums1{137, 59, 92, 122, 52, 131, 79, 236};
    std::vector<int> nums2{137, 59, 92, 122, 52, 131, 79, 236};

    auto result = NextGreaterElement(nums1, nums2);

    for (auto num : result)
        std::cout << num << " ";

    std::cout << "\n\n";

    return 0;
}
