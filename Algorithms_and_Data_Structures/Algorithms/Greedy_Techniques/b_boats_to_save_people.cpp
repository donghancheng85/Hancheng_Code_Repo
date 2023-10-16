#include <iostream>
#include <vector>
#include <algorithm>

int RescueBoats(std::vector<int>& people, int limit)
{
    // sort the weight of people first, ascending order
    std::sort(people.begin(), people.end());

    //litr - left iterator
    auto litr = people.begin();
    auto ritr = people.end()-1;

    int result{0};

    while (litr < ritr)
    {
        if (*litr+*ritr <= limit)
        {
            ++result;
            ++litr;
            --ritr;
        }
        else
        {
            ++result;
            --ritr;
        }
    }

    if (litr == ritr)
        ++result;

    return result;
}

int main()
{
    std::vector<int> people {5, 5, 5, 5};
    int limit{5};

    std::cout << RescueBoats(people, limit) << "\n\n";
}
