#include "Interval.hpp"
#include <iostream>
#include <vector>

std::vector<Interval> IntervalsIntersection(const std::vector<Interval> &intervalListA,
                                            const std::vector<Interval> &intervalListB)
{
    std::vector<Interval> result;
    std::size_t indA{0};
    std::size_t indB{0};
    std::size_t count{2}; // init to 2 because start with the first element in both list

    while (count <= intervalListA.size() + intervalListB.size())
    {

        if (intervalListA[indA].start <= intervalListB[indB].end ||
            intervalListB[indB].start <= intervalListA[indA].end)
        {
            auto newStart = (intervalListA[indA].start <= intervalListB[indB].start) ? intervalListB[indB].start
                                                                                     : intervalListA[indA].start;
            auto newEnd = (intervalListA[indA].end <= intervalListB[indB].end) ? intervalListA[indA].end
                                                                               : intervalListB[indB].end;
            if (newStart <= newEnd)
                result.emplace_back(newStart, newEnd);
        }

        if (intervalListA[indA].end > intervalListB[indB].end)
        {
            if (indB < intervalListB.size())
            {
                ++indB;
                ++count;
            }
        }
        else
        {
            if (indA < intervalListA.size())
            {
                ++indA;
                ++count;
            }
        }
    }

    return result;
}

int main()
{
    std::vector<Interval> interA{{1, 4}, {5, 6}, {7, 8}, {9, 15}};
    std::vector<Interval> interB{{2, 4}, {5, 7}, {9, 15}};

    auto result = IntervalsIntersection(interA, interB);

    for (auto &r : result)
        std::cout << r.ToString() << " ";

    std::cout << "\n\n";
}
