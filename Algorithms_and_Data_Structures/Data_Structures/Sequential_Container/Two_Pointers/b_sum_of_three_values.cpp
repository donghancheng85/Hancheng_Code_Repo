#include<vector>
#include <iostream>
#include <algorithm>

bool FindSumOfThree(std::vector<int> nums, int target)
{
    std::sort(nums.begin(), nums.end());
    auto left = nums.begin();
    auto right = nums.end()-1;

    while (left < right)
    {
        auto third = target - *right - *left;
        auto it = std::lower_bound(left+1, right, third);
        if ( it != (right) )
        {
            if (*it == third)
                return true;
            right--;
        }
        else
            left++;
    }
    return false;
}

int main()
{
    std::vector<int> myvec{-1,2,1,-4,5,-3};

    std::cout << std::boolalpha;
    std::cout << FindSumOfThree(myvec, 8) << "\n\n";

    //auto it = std::lower_bound(myvec.begin(), myvec.rbegin().base(), 7);

    //std::cout << std::distance(myvec.begin(), it) << " it value is: " << *it << "\n\n";

}