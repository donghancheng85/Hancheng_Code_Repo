#include <vector>
#include <algorithm>
#include <iostream>

class KthLargest{
    public:
    int m_k;
    std::vector<int> kthMinHeap;

    // constructor to initialize heap and add values in it
    KthLargest(int K, const std::vector<int>& nums) : m_k{K}, kthMinHeap{nums}
    {
        std::make_heap(kthMinHeap.begin(), kthMinHeap.end(), std::greater<>{});
        pop_kthMinHeap();
    }

    // adds element in the heap
    int add(int val)
    {
        kthMinHeap.push_back(val);
        std::push_heap(kthMinHeap.begin(), kthMinHeap.end(), std::greater<>{});
        pop_kthMinHeap();
        return ReturnKthLargest();
    }

    // returns kth largest element from heap
    int ReturnKthLargest()
    {
        return kthMinHeap.front();
    }

    void pop_kthMinHeap()
    {
        while(kthMinHeap.size() > m_k)
        {
            std::pop_heap(kthMinHeap.begin(), kthMinHeap.end(), std::greater<>{});
            kthMinHeap.pop_back();
        }
    }
};

int main()
{
    std::vector<int> vec{-2, 8, 0, -5, 7, -1, 3, -3, -4, 1, 4, -8, -9, 2, -7, 6, -6, 9};
    std::sort(vec.begin(), vec.end(), std::greater<>{});

    std::cout << vec[9] << "\n\n";

}
