#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

bool CanFinish(int numCourses, std::vector<std::vector<int>> preRequisites)
{
    if(numCourses <= 0)
    {
        return false;
    }

    std::unordered_map<int, uint16_t> inDegree;
    std::unordered_map<int, std::vector<int>> graph;

    inDegree.reserve(numCourses);
    graph.reserve(numCourses);

    for(uint16_t i = 0; i < numCourses; ++i)
    {
        inDegree[i] = 0;
    }

    for(uint16_t i = 0; i < preRequisites.size(); ++i)
    {
        int parent = preRequisites.at(i).at(1);
        int child  = preRequisites.at(i).at(0);

        graph[parent].emplace_back(child);
        ++inDegree.at(child);
    }

    std::queue<int> zeroDegreeNodes;

    for (const auto&[node, degree] : inDegree)
    {
        if (degree == 0)
        {
            zeroDegreeNodes.push(node);
        }
    }

    uint16_t iterCount{0U};
    while (!zeroDegreeNodes.empty())
    {
        int node = zeroDegreeNodes.front();
        zeroDegreeNodes.pop();
        ++iterCount;

        if(graph.find(node) == graph.end())
        {
            continue;
        }

        auto childrenVector = graph.at(node);

        for (auto child : childrenVector)
        {
            --inDegree.at(child);
            if (inDegree.at(child) == 0)
            {
                zeroDegreeNodes.push(child);
            }
        }
    }

    return iterCount == numCourses;
}

int main()
{
    std::vector<int> numCourses = {3, 2, 10, 5, 5};
    std::vector<std::vector<std::vector<int>>> preRequisites =  {
      {{1,0},{2,1}},
      {{1,0},{0,1}},
      {{1,0},{2,1},{3,2},{4,3}},
      {{1,0},{2,1},{3,2},{4,3},{0,4}},
      {{2,0},{2,1},{3,2},{4,2},{3,1}}
    };
    for(int i=0; i<numCourses.size(); i++){
        std::cout << i+1 << ".\tNumber of courses: " << numCourses[i] << std::endl;
        std::cout << "\tpreRequisites: ";
        // Print(preRequisites[i]);
        std::cout<< "\n\tOutput: " << std::boolalpha << CanFinish(numCourses[i], preRequisites[i]) <<std::endl;
        std::cout <<std::string(89,'-')<< std::endl;
    }
}
