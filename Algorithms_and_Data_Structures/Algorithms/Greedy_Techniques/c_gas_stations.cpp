#include <iostream>
#include <vector>
#include <numeric>

int GasStationJourney(std::vector<int> const & gas, std::vector<int> const & cost)
{
    // Calculate total gas and cost from the arrays
    auto sumGas = std::accumulate(gas.begin(), gas.end(), 0);
    auto sumCost = std::accumulate(cost.begin(), cost.end(), 0);

    if (sumGas < sumCost)
        return -1;

    int currCost{0};
    int currStart{0};
    for(int i = 0; i < gas.size(); ++i)
    {
        currCost += (gas[i] - cost[i]);

        if (currCost < 0)
        {
            currStart = i + 1;
            currCost = 0;
        }
    }

    return currStart;
}

int main()
{
    std::vector<int> gas {1,2,3,4,5};
    std::vector<int> cost {3,4,5,1,2};

    std::cout << GasStationJourney(gas, cost) << "\n\n";

    return 0;
}
