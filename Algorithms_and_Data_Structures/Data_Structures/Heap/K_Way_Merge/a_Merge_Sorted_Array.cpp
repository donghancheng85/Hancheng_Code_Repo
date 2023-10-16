#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> mergeSortedArray(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n)
{
    // init 3 positions
    int p1 {m-1}; // last valid item at array 1 (array 1 ends with n 0s)
    int p2 {n-1}; // last item at array 2
    std::size_t p {nums1.size()-1}; // end of array 1

    while (!nums2.empty())
    {
        if(p1 >= 0 && nums1[p1] > nums2[p2])
        {
            nums1[p] = nums1[p1--];
        }
        else
        {
            nums1[p] = nums2[p2--];
            nums2.pop_back();
        }
        p--;
    }

    return nums1;
}

int main()
{
    std::vector<int> nums1 {6,7,8,9,10,0,0,0,0,0};
    std::vector<int> nums2 {1,2,3,4,5};

    auto result = mergeSortedArray(nums1, 5, nums2, 5);

    for (auto r : result)
        std::cout << r << " ";

    std::cout << "\n\n";
}
