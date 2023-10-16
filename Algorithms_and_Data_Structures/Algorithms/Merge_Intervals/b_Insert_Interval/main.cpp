#include "Interval.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<Interval> MergeIntervals(const std::vector<Interval> &intervals)
{
    // edge case
    if (intervals.size() < 2)
        return intervals;

    std::vector<Interval> out;
    // insert the first interval to output
    out.push_back(intervals.front());

    for (std::size_t i = 1; i < intervals.size(); i++)
    {
        if (intervals[i].start <= out.back().end) // overlap merge
            out.back().end = (intervals[i].end < out.back().end) ? out.back().end : intervals[i].end;
        else // not overlap
            out.push_back(intervals[i]);
    }

    return out;
}

// Function that inserts the respective interval
std::vector<Interval> InsertInterval(std::vector<Interval>& existingIntervals, Interval newInterval)
{
    auto pos = std::lower_bound(existingIntervals.begin(), existingIntervals.end(), newInterval,
                                [](Interval new_inter, Interval val){
                                    return new_inter.start < val.start;
                                });
    existingIntervals.insert(pos, newInterval);

    return MergeIntervals(existingIntervals);
}

int main()
{
    std::vector<Interval> inter{{1, 2}, {3, 4}, {5, 8}, {9, 15}};
    Interval new_inter {16, 17};
    auto result = InsertInterval(inter, new_inter);

    for (auto &i : result)
        std::cout << i.ToString() << "\n";

    std::cout << "\n";
}
