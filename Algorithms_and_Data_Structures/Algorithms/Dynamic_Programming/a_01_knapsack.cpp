#include <algorithm>
#include <iostream>
#include <vector>

int FindMaxKnapsackProfit(std::size_t capacity, std::vector<int> weights, std::vector<int> values)
{
    // use one array to hold the dyanmic programming results
    // the array will mimic the rows of the supposed 2D dp array which will contain the best value in the pack
    // array row represent the item index + 1 (0 to value.size())
    // array column represent the remaining capacity (0 to capacity)
    // init array with all 0 (the first row, item 0)
    std::vector<int> dp(capacity + 1, 0);
    //std::vector<int> temp(capacity + 1, 0);

    // start to fill the dp array
    for (std::size_t i = 0; i < values.size(); i++)
    {
        // loop from the end since we do not want to change the value of the "previous" row before we use it
        // we only need to loop until the item can be put into the pack
        for (std::size_t j = capacity; j >= weights[i]; j--)
        {
            dp[j] = std::max(values[i] + dp[j - weights[i]], dp[j]);
        }
    }
    return dp.back();
}

int main()
{
    std::vector<int> weights = {1, 2, 3, 5};
    std::vector<int> values = {1, 5, 4, 8};

    std::cout << FindMaxKnapsackProfit(6, weights, values) << "\n";
}
