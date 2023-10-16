#include <deque>
#include <iostream>
#include <map>
#include <vector>

std::vector<char> FindCompilationOrder(std::vector<std::vector<char>> dependencies)
{
    // graph is build based on dependencies, key is the vertex, value contains the child vertices
    std::map<char, std::vector<char>> graph;
    // inDegree represents the vertices' degrees, which represent how many parent vertices they have
    std::map<char, std::size_t> inDegree;

    // Build the graph based on dependencies. [B, A] means B depend on A, their order should be A-->B
    // init graph first
    for (auto &v : dependencies)
    {
        graph[v[0]] = {};
        inDegree[v[0]] = 0;
        graph[v[1]] = {};
        inDegree[v[1]] = 0;
    }

    // build graph -- order is: v[1]-->v[0]
    // add v[0] to v[1]'s children list (a vector), increase v[0]'s inDegree by 1
    for (auto &v : dependencies)
    {
        graph[v[1]].push_back(v[0]);
        ++inDegree[v[0]];
    }

    // init a deque to store the 0 degree vertices, i.e. the "sources" of the graph
    std::deque<char> sources;
    for (auto& p : inDegree)
    {
        if (p.second == 0)
            sources.push_back(p.first);
    }

    std::vector<char> order; // store the result

    // pop and push the deque sources, sort the vertices in a topological order
    // when pop the vertex from the deque, reduce all its children's degree by 1
    // if the children's degree reduce to 0, push it into the deque
    while (!sources.empty())
    {
        auto currentv = sources.front();
        sources.pop_front();
        for (auto child : graph[currentv])
        {
            if(--inDegree[child] == 0)
                sources.push_back(child);
        }
        order.push_back(currentv);
    }

    // graph has loop
    if (order.size() != graph.size())
        return {};

    return order;
}

int main()
{
    std::vector<std::vector<char>> dependencies {{'B', 'C'}, {'C', 'A'}, {'A', 'F'}};
    auto result = FindCompilationOrder(dependencies);

    for (auto c : result)
        std::cout << c << " ";

    std::cout << "\n\n";
}
