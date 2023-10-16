#include <iostream>
#include <string>
#include <set>
#include <unordered_map>

std::set<std::string> FindRepeatedSequences(const std::string& s, int k)
{   
    // count the repreat number of the dna sequence
    std::unordered_map<std::string, int> seq_count;

    //store the results
    std::set<std::string> dummy{}; 

    // query sequence is longer than the size of the dna sequence
    if (s.begin() + k >= s.end()) 
        return {};
    
    for (int i=0; i<=s.length()-k; i++)
        seq_count[s.substr(i, k)]++;
    
    for (auto& element: seq_count)
    {
        if (element.second > 1)
            dummy.insert(element.first);
    }

    return dummy;
}

int main()
{
    std::string str = "TTTTTCCCCCCCTTTTTTCCCCCCCTTTTTTT";
    int k = 10;

    auto result = FindRepeatedSequences(str, k);

    for (auto& s : result)
        std::cout << s << "\n";
}