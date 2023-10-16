#include <iostream>
#include <climits>
#include <limits>
#include <vector>

int MinSubArrayLen(int target, const std::vector<int>& nums)
{
    // pre-define necessary parameter
    std::size_t win_left{0};
    std::size_t win_right{0};

    int sum{0}; // sum of current window
    int min_len{std::numeric_limits<int>::max()};

    while (win_right <= nums.size()-1)
    {
        sum += nums[win_right];

        // found a window that is larger or equal to target
        if(sum >= target)
        {
            // move win_left until sum is smaller than target
            while(sum >= target)
            {
                sum -= nums[win_left];
                win_left++;
            }

            // update min_len if necessary. left side of window should
            // be one left to win_left
            if(win_right-win_left+2 < min_len)
                min_len = win_right-win_left+2;
        }
        win_right++;
    }

    return (min_len == std::numeric_limits<int>::max())? 0: min_len;
}

int main()
{
    int target{5};
    std::vector<int> nums {1, 2, 1, 3};

    std::cout << MinSubArrayLen(target, nums) << "\n\n";
}
