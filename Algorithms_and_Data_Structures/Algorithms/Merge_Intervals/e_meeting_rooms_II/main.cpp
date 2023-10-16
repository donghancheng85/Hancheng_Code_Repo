#include "Interval.hpp"
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class minHeapCallable
{
public:
    bool operator()(const Interval &lhs, const Interval &rhs)
    {
        return lhs.end > rhs.end;
    }
};

std::size_t FindSets(std::vector<Interval> &intervals)
{
    // Sort the input interval by the start time (increase)
    std::sort(intervals.begin(), intervals.end(), [](Interval lhs, Interval rhs) { return lhs.start < rhs.start; });

    // init a priority queue with the first element in the sorted vector intervals
    std::priority_queue<Interval, std::vector<Interval>, minHeapCallable> intervalHeap(intervals.begin(),
                                                                                       intervals.begin() + 1);

    for (std::size_t i = 1; i < intervals.size(); i++)
    {
        if (intervalHeap.top().end <= intervals[i].start)
        {
            // no need to add a new meeting room
            intervalHeap.pop();
            intervalHeap.push(intervals[i]);
        }
        else
        {
            // add a new meeting room
            intervalHeap.push(intervals[i]);
        }
    }
    return intervalHeap.size();
}

int main()
{
    std::vector<Interval> intervals{{1, 2}, {1, 2}, {1, 2}};
    std::cout << "Num of meeting rooms: " << FindSets(intervals) << "\n\n";
}
