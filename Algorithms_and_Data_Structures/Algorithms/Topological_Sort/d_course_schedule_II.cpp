#include <deque>
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> FindOrder(int n, std::vector<std::vector<int>> preRequisites)
{
    // predefine graph: key-vertex, value-children vertices
    std::unordered_map<int, std::vector<int>> graph;

    // inDegree represents the vertices' degrees, which represent how many parent vertices they have
    std::unordered_map<int, std::size_t> inDegree;

    // Build the graph based on dependencies. [B, A] means B depend on A, their order should be A-->B
    // init graph first
    for (int i=0; i<n; ++i)
    {
        graph[i] = {};
        inDegree[i] = 0;
    }

    // build graph -- order is: v[1]-->v[0]
    // add v[0] to v[1]'s children list (a vector), increase v[0]'s inDegree by 1
    for (auto &v : preRequisites)
    {
        graph[v[1]].push_back(v[0]);
        ++inDegree[v[0]];
    }

    // init a deque to store the 0 degree vertices, i.e. the "sources" of the graph
    std::deque<int> sources;
    for (auto& p : inDegree)
    {
        if (p.second == 0)
            sources.push_back(p.first);
    }

    std::vector<int> result{};

    while (!sources.empty())
    {
        int currentV = sources.front();
        sources.pop_front();
        result.push_back(currentV);
        // decrease the children nodes indegree, if it is 0, push it back into the queue source, if any
        for (auto& child : graph[currentV])
        {
            if (--inDegree[child] == 0)
                sources.push_back(child);
        }
    }

    if (result.size() != n)
        return {};

   return result;
}

int main()
{
    int n = 7;
    std::vector<std::vector<int>> preRequisite  {{1, 0}, {0, 3}, {0, 2}, {3, 2}, {2, 5}, {4, 5}, {5, 6}, {2, 4}};
    auto result = FindOrder(n, preRequisite);

    for (auto r : result)
        std::cout << r << " ";

    std::cout << "\n\n";
    return 0;
}
