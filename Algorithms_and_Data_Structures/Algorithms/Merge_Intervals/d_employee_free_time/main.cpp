#include "Interval.hpp"
#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

bool minHeapFunc(std::tuple<int, std::size_t, std::size_t> lhs, std::tuple<int, std::size_t, std::size_t> rhs)
{
    return std::get<0>(lhs) > std::get<0>(rhs);
}

std::vector<Interval> EmployeeFreeTime(std::vector<std::vector<Interval>> schedule)
{
    std::vector<Interval> result;
    // tuple will store: interval start time, employee index, current interval index
    std::vector<std::tuple<int, std::size_t, std::size_t>> intervalHeap{};

    /**
     * @param previous store the end time of the previously precessed interval
     * @param i store the employee's index
     * @param j store the interval's index of employee i
     */
    int previous{0};
    std::size_t i{0}, j{0};
    intervalHeap.reserve(schedule.size());

    // push the start time of the first interval of each employee into the heap
    for (std::size_t e = 0; e < schedule.size(); e++)
        intervalHeap.emplace_back(std::make_tuple(schedule[e][0].start, e, 0));

    // Then make the vector a heap
    std::make_heap(intervalHeap.begin(), intervalHeap.end(), minHeapFunc);

    // init previous to the start time of the first (min) start time of in the heap
    previous = std::get<0>(intervalHeap[0]);

    while (!intervalHeap.empty())
    {
        auto &minStartTuple = intervalHeap[0]; // interval with mininum start time
        i = std::get<1>(minStartTuple);        // employee index
        j = std::get<2>(minStartTuple);        // employee's interval index

        // find free time interval
        if (schedule[i][j].start > previous)
            result.emplace_back(previous, schedule[i][j].start);

        // update previous
        previous = std::max(previous, schedule[i][j].end);

        // remove the first element of heap
        std::pop_heap(intervalHeap.begin(), intervalHeap.end(), minHeapFunc);
        intervalHeap.pop_back();

        // push next interval of employee i to the heap, if exist
        if (++j < schedule[i].size())
        {
            intervalHeap.emplace_back(std::make_tuple(schedule[i][j].start, i, j));
            std::push_heap(intervalHeap.begin(), intervalHeap.end(), minHeapFunc);
        }
    }
    return result;
}

int main()
{
    std::vector<std::vector<Interval>> twodVec{std::vector<Interval>{{1, 3}, {6, 7}},
                                               std::vector<Interval>{{2, 4}},
                                               std::vector<Interval>{{2, 5}, {9, 12}}};

    auto result = EmployeeFreeTime(twodVec);
    for (auto &r : result)
        std::cout << r.ToString() << " ";
    std::cout << "\n\n";
}
