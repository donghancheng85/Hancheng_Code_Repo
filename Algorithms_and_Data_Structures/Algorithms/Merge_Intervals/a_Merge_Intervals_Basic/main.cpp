#include "Interval.hpp"
#include <iostream>
#include <vector>

std::vector<Interval> MergeIntervals(std::vector<Interval> &intervals)
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

int main()
{
    std::vector<Interval> inter{{1, 2}, {3, 4}, {8, 8}};
    auto result = MergeIntervals(inter);

    for (auto &i : result)
        std::cout << i.ToString() << "\n";

    std::cout << "\n";
}
