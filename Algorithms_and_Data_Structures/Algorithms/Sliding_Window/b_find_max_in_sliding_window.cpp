#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

void Clean_Window(std::deque<int>& currentWindow, const std::vector<int>& nums, int index)
{
    while(!currentWindow.empty() && nums[currentWindow.back()] <= nums[index])
        currentWindow.pop_back();
}

std::vector<int> FindMaxSlidingWindow(std::vector<int>& nums, int w)
{
    // when window size > vector size
    if (w >= nums.size())
        return {*std::max_element(nums.begin(), nums.end())};
    if (nums.empty())
        return {};

    std::vector<int> result;
    std::deque<int> currentWindow;
    auto it = nums.begin();

    // first window
    while (it < nums.begin()+w)
    {
        auto index = std::distance(nums.begin(), it);
        Clean_Window(currentWindow, nums, index);
        currentWindow.push_back(index);
        it++;
    }

    result.push_back(nums[currentWindow[0]]);

    while(it < nums.end())
    {
        auto index = std::distance(nums.begin(), it);
        Clean_Window(currentWindow, nums, index);

        if(!currentWindow.empty() && currentWindow[0] <= index - w)
            currentWindow.pop_front();

        currentWindow.push_back(std::distance(nums.begin(), it));
        result.push_back(nums[currentWindow[0]]);
        it++;
    }

    return result;
}


int main()
{
    std::vector<int> myvec {4, 5, 6, 1, 2, 3};

    auto result = FindMaxSlidingWindow(myvec, 4);

    for(auto i: result)
        std::cout << i << "  ";

    std::cout << "\n\n";
}
