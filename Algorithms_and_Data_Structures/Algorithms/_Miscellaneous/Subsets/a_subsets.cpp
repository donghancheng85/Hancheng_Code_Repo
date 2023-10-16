#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> FindAllSubsets(std::vector<int> nums)
{
    // edge case
    if (nums.empty())
        return {{}};

    // total number of sets is 2^(nums.size())
    std::size_t numSets = 1 << nums.size();
    std::vector<std::vector<int>> result;

    for (std::size_t i = 0; i < numSets; ++i)
    {
        std::vector<int> temp{};
        temp.reserve(nums.size());

        for (std::size_t j = 0; j < nums.size(); ++j)
        {
            if (i & (1 << j))
                temp.push_back(nums[j]);
        }

        temp.shrink_to_fit();
        result.emplace_back(temp);
    }

    return result;
}

int main()
{
    std::vector<int> myvec{1, 2, 3, 4};

    auto result = FindAllSubsets(myvec);

    for (const auto &set : result)
    {
        std::cout << "[ ";
        for (auto num : set)
            std::cout << num << " ";
        std::cout << "]";
    }
    std::cout << "\n\n";
}
