#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int KSmallestNumber(std::vector<std::vector<int>>& list, int k)
{
    if (list.empty())
        return 0;

    /**
     * @brief min heap to store elements in the list elements in
     * elements in pair are: int - number in the list; std::size_t - index of the list
     */
    std::vector<std::pair<int, std::size_t>> minHeap;
    minHeap.reserve(list.size());

    // init heap
    for (std::size_t i = 0; i < list.size(); ++i)
    {
        if (!list[i].empty())
        {
            minHeap.emplace_back(std::make_pair(list[i].front(), i));
            list[i].erase(list[i].begin());
        }
    }

    std::make_heap(minHeap.begin(), minHeap.end(), std::greater<>{});

    // loop k times and find the kth element in the list
    // this is the protection if k is larger than the total number of elements
    std::pair<int, std::size_t> tempMin{0, 0};
    for (int n = 0; n < k - 1; ++n)
    {
        // pop the top of the heap
        if (!minHeap.empty())
        {
            std::pop_heap(minHeap.begin(), minHeap.end(), std::greater<>{});
            tempMin = minHeap.back();
            minHeap.pop_back();
        }

        // push element in the heap, from the list that has been poped, if the list is not empty
        if (!list[tempMin.second].empty())
        {
            minHeap.emplace_back(std::make_pair(list[tempMin.second].front(), tempMin.second));
            list[tempMin.second].erase(list[tempMin.second].begin());
            std::push_heap(minHeap.begin(), minHeap.end(), std::greater<>{});
        }
    }

    // find the kth element
    std::pop_heap(minHeap.begin(), minHeap.end(), std::greater<>{});

    return minHeap.empty() ? tempMin.first : minHeap.back().first;
}

int main()
{
    std::vector<std::vector<int>> lists{{2, 6, 8}, {3, 7, 10}, {5, 8, 11}};
    int k = 100;

    std::cout << KSmallestNumber(lists, k) << "\n\n";
}
