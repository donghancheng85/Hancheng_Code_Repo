#include <iostream>
#include <array>
#include <vector>
#include <set>
#include <unordered_set>

int main() {
    //init std::array
    std::array<int, 3> my_arr{9, 1, 2};
    std::cout << "std::array<int, 3> my_arr elements are: " ;
    for (auto i : my_arr)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    //init std::vector
    std::vector<int> my_vec{13, 5, 66, 123};
    std::cout << "std::vector<int> my_vec elements are: " ;
    for (auto i : my_vec)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    //init std::set
    std::set<std::string> my_set{"ccc", "abce", "zetre", "ccc"};
    std::cout << "std::set<std::string> my_set elements are: " ;
    for (auto i: my_set)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    //init std::unordered_multiset
    std::unordered_multiset<int> my_uset{1, 4, 1, 5, 166, 3};
    std::cout << "sstd::unordered_multiset<int> my_uset elements are: " ;
    for (auto i: my_uset)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}