#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>

class MedianOfStream
{
public:
    // This function should take a number and store it
    void InsertNum(int num)
    {
        // empty heaps
        if(m_smallHalfMaxHeap.empty())
        {
            m_smallHalfMaxHeap.push(num);
            return;
        }

        if (num > m_smallHalfMaxHeap.top())
             m_largerHalfMinHeap.push(num);
        else
            m_smallHalfMaxHeap.push(num);

        // resize the heaps
        while (m_smallHalfMaxHeap.size() > m_largerHalfMinHeap.size()+1)
        {
            auto temp = m_smallHalfMaxHeap.top();
            m_smallHalfMaxHeap.pop();
            m_largerHalfMinHeap.push(temp);
        }

        while (m_smallHalfMaxHeap.size() < m_largerHalfMinHeap.size())
        {
            auto temp = m_largerHalfMinHeap.top();
            m_largerHalfMinHeap.pop();
            m_smallHalfMaxHeap.push(temp);
        }
    }
    // This function should return the median of the stored numbers
    double FindMedian()
    {
        auto total = m_smallHalfMaxHeap.size() + m_largerHalfMinHeap.size();
        if(total % 2)
            return m_smallHalfMaxHeap.top();
        return (m_smallHalfMaxHeap.top() + m_largerHalfMinHeap.top()) / 2.0;
    }

    // 2 heaps to monitor smaller half and lager half, smaller half will always
    // equal or 1 more than lager half (odd or even)
    std::priority_queue<int> m_smallHalfMaxHeap{};
    std::priority_queue<int, std::vector<int>, std::greater<int>> m_largerHalfMinHeap{};
};

int main()
{
    MedianOfStream ms;

    ms.InsertNum(1);
    ms.InsertNum(2);
    std::cout << ms.FindMedian() << " ";
    ms.InsertNum(3);
    std::cout << ms.FindMedian() << " ";

    std::cout << "\n\n";
}
