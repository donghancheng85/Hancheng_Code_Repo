#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <deque>

std::string FindDictionary(std::vector<std::string>& words)
{
    // graph to store the depenency of the characters
    std::unordered_map<char, std::vector<char>> graph;
    // inDegree to store the degree of the characters, 0 means the character is a vertex
    std::unordered_map<char, int> inDegree;
    std::string result{};

    // init graph and inDegree, need to cover all possible characters
    for(const auto &word : words)
    {
        for(const auto c : word)
        {
            graph[c];
            inDegree[c] = 0;
        }
    }

    // build the dependency graph based on the provided words
    for (std::size_t i = 0; i < words.size() - 1; ++i)
    {
        // get the adjacent 2 words to build the graph
        const auto& w1 = words[i];
        const auto& w2 = words[i+1];

        // if w2 is a prefix of w1, there is no dictionary, return ""
        if (w1.size() > w2.size() && w1.find(w2) == 0)
            return "";

        for (std::size_t j = 0; j < std::min(w1.length(), w2.length()); ++j)
        {
            if(w1[j] != w2[j])
            {
                graph[w1[j]].push_back(w2[j]);
                ++inDegree[w2[j]];
                break;
            }
        }
    }

    // init queue to start BFS search, push all vertices that inDegree = 0 into the queue
    std::deque<char> vertices{};
    for (const auto& p : inDegree)
    {
        if(p.second == 0)
            vertices.push_back(p.first);
    }

    // pop the queue and generate the sorted dictionary
    while (!vertices.empty())
    {
        char top = vertices.front();
        result.push_back(top);
        vertices.pop_front();

        // reduce the indegree of the dependency of inDegree by 1
        for(auto c : graph[top])
        {
            // if the indegree becomes 0 (it is a vertex now), push it into the queue
            if(--inDegree[c] == 0)
                vertices.push_back(c);
        }
    }

    return (result.length() == inDegree.size()) ? result : "";
}

int main()
{
    std::vector<std::string> words {"m", "mx", "mxe", "mxer", "mxerl", "mxerlo", "mxerlos", "mxerlost", "mxerlostr", "mxerlostrpq", "mxerlostrp"};
    auto result = FindDictionary(words);

    std::cout << result << "\n\n";
}
