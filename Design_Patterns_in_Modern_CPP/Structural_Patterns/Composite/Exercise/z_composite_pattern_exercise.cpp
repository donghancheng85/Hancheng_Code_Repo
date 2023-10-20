#include "exercise.h"

int sum(const vector<ContainsIntegers*> items)
{
    int sum = 0;

    for (auto& v : items)
    {
        sum += v->sum();
    }

    return sum;
}


int main()
{
    SingleValue single_value{ 1 };
    ManyValues other_values;
    other_values.add(2);
    other_values.add(3);
    int res = sum({ &single_value, &other_values }); 

    std::cout << res << "\n";

}