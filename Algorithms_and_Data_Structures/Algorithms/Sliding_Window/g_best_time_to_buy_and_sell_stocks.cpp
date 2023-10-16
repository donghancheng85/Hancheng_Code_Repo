#include <algorithm>
#include <iostream>
#include <vector>

int MaxProfit(const std::vector<int> &stockPrices)
{
    //edge case
    if (!stockPrices.size())
        return 0;

    std::size_t buy{0};  // window left
    std::size_t sell{1}; // window right

    int max_profit{0};

    while (sell <= stockPrices.size() - 1)
    {
        // find better profit
        if (stockPrices[sell] > stockPrices[buy])
            max_profit = std::max(stockPrices[sell] - stockPrices[buy], max_profit);
        else
            buy = sell;
        sell++;
    }
    return max_profit;
}


int main()
{
    std::vector<int> stockPrices{2, 6, 8, 7, 8, 7, 9, 4, 1, 2, 4, 5, 8};

    std::cout << MaxProfit(stockPrices) << "\n\n";
}
