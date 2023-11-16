#include <stddef.h>
#include <stdio.h>
#include <algorithm>
#include <random>
#include <ratio>
#include <vector>
#include <chrono>
#include <execution>

using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::milli;
using std::random_device;
using std::sort;
using std::vector;

const size_t testSize = 1'000'000;
const int iterationCount = 5;

void print_results(const char* const tag, const vector<double>& sorted,
    high_resolution_clock::time_point startTime,
    high_resolution_clock::time_point endTime) {
    printf("%s: Lowest: %g Highest: %g Time: %fms\n", tag, sorted.front(),
        sorted.back(),
        duration_cast<duration<double, milli>>(endTime - startTime).count());
}

int main() {
    random_device rd;

    // generate some random doubles:
    printf("Testing with %zu doubles...\n", testSize);
    vector<double> doubles(testSize);
    for (auto& d : doubles) {
        d = static_cast<double>(rd());
    }

    // time how long it takes to sort them, five times each approach
    // compare the results of sequenced_policy and parallel_policy
    for (int i = 0; i < iterationCount; ++i)
    {
        vector<double> sorted(doubles);
        const auto startTime = high_resolution_clock::now();
        sort(sorted.begin(), sorted.end());
        const auto endTime = high_resolution_clock::now();
        print_results("Serial STL ", sorted, startTime, endTime);
    }

    for (int i = 0; i < iterationCount; ++i)
    {
        vector<double> sorted(doubles);
        const auto startTime = high_resolution_clock::now();
        // same sort call as above, but with par_unseq:
        std::sort(std::execution::par, sorted.begin(), sorted.end());
        const auto endTime = high_resolution_clock::now();
        // in our output, note that these are the parallel results:
        print_results("Parallel STL", sorted, startTime, endTime);
    }
}

/*
* Possible results:
Testing with 1000000 doubles...
Serial STL : Lowest: 5324 Highest: 4.29497e+09 Time: 313.454800ms
Serial STL : Lowest: 5324 Highest: 4.29497e+09 Time: 332.960500ms
Serial STL : Lowest: 5324 Highest: 4.29497e+09 Time: 317.707300ms
Serial STL : Lowest: 5324 Highest: 4.29497e+09 Time: 302.204500ms
Serial STL : Lowest: 5324 Highest: 4.29497e+09 Time: 296.656200ms
Parallel STL: Lowest: 5324 Highest: 4.29497e+09 Time: 85.895600ms
Parallel STL: Lowest: 5324 Highest: 4.29497e+09 Time: 64.242600ms
Parallel STL: Lowest: 5324 Highest: 4.29497e+09 Time: 65.696900ms
Parallel STL: Lowest: 5324 Highest: 4.29497e+09 Time: 68.132100ms
Parallel STL: Lowest: 5324 Highest: 4.29497e+09 Time: 72.631000ms

* parallel is much faster than sequenced sorting algorithm
*/
