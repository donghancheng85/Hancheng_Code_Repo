#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>

int NetworkDelayTime(std::vector<std::vector<int>> &times, int n, int k)
{
    // use unordered map to store the node info and edge weight
    // key - node; value - vector of pairs that store the node and edge weight
    std::unordered_map<int, std::vector<std::pair<int, int>>> graph;

    for (const auto &vec : times)
        graph[vec[0]].emplace_back(vec[1], vec[2]);

    // edge case, k is not in the vertex list
    if (graph.count(k) == 0)
        return -1;

    // created visited set to store the visited node
    // and priority queue to store the neighbor node and its time delay (use vector and std::make_heap)
    std::unordered_set<int> visited;
    // tuple.get<0>: delay time; tuple.get<1>: layer; tuple.get<2>: node;
    std::vector<std::tuple<int, int, int>> nodePq;
    int delay{0};
    int layer{0};

    // init priority queue
    nodePq.emplace_back(delay, layer, k);
    std::make_heap(nodePq.begin(), nodePq.end(), std::greater<>{});
    ++layer;

    // BFS visit all node in graph, starting with k
    while (!nodePq.empty())
    {
        std::pop_heap(nodePq.begin(), nodePq.end(), std::greater<>{});
        auto tempNode = nodePq.back();
        nodePq.pop_back();

        // if visited, continue. No need for after operation. To deal with loop in the graph.
        if (visited.count(std::get<2>(tempNode)))
            continue;

        visited.insert(std::get<2>(tempNode));
        // updated delay if necessary
        delay = std::max(delay, std::get<0>(tempNode));

        for (const auto &p : graph[std::get<2>(tempNode)])
        {
            nodePq.emplace_back(delay + p.second, layer, p.first);
            std::push_heap(nodePq.begin(), nodePq.end(), std::greater<>{});
        }

        ++layer;
    }

    return (visited.size() == n) ? delay : -1;
}

int main()
{
    std::vector<std::vector<int>> times{{1, 2, 5}, {1, 3, 5}, {1, 4, 5}, {2, 4, 5}, {3, 4, 5}};
    int n = 4;
    int k = 1;

    std::cout << NetworkDelayTime(times, n, k) << "\n\n";
}
