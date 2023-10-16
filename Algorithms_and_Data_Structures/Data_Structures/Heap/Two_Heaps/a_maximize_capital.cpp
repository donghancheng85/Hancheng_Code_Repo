#include <algorithm>
#include <iostream>
#include <vector>

struct capProfPair
{
    int captial;
    int profit;
    capProfPair(int c, int p) : captial{c}, profit{p}
    {
    }
};

class minCapHeapCallable
{
public:
    bool operator()(capProfPair lhs, capProfPair rhs)
    {
        return lhs.captial > rhs.captial;
    }
};

class maxProfHeapCallable
{
public:
    bool operator()(capProfPair lhs, capProfPair rhs)
    {
        return lhs.profit < rhs.profit;
    }
};

int MaximumCapital(int c, int k, std::vector<int> capitals, std::vector<int> profits)
{
    std::vector<capProfPair> capMinHeap;
    // create min heap for capitals
    for (std::size_t i = 0; i < capitals.size(); i++)
        capMinHeap.emplace_back(capitals[i], profits[i]);
    std::make_heap(capMinHeap.begin(), capMinHeap.end(), minCapHeapCallable());

    // create max heap for profits that the invester can invest, use make_heap function later for this
    std::vector<capProfPair> profMaxHeap;

    // use a for loop to track all k capitals that will invest
    for (int j = 0; j < k; j++)
    {
        // in the capitals min heap, find all capitals that is less than invester's current capital
        while (capMinHeap.front().captial <= c && !capMinHeap.empty())
        {
            std::pop_heap(capMinHeap.begin(), capMinHeap.end(), minCapHeapCallable());
            profMaxHeap.push_back(capMinHeap.back());
            capMinHeap.pop_back();
        }
        // find the largets profit and invest
        if (!profMaxHeap.empty())
        {
            std::make_heap(profMaxHeap.begin(), profMaxHeap.end(), maxProfHeapCallable());
            std::pop_heap(profMaxHeap.begin(), profMaxHeap.end(), maxProfHeapCallable());
            // update new capital
            c += profMaxHeap.back().profit;
            profMaxHeap.pop_back();
        }
    }

    return c;
}

int main()
{
    std::vector<int> capitals{1, 2, 3, 4};
    std::vector<int> profits{1, 3, 5, 7};
    std::cout << MaximumCapital(2, 2, capitals, profits) << "\n\n";
}
