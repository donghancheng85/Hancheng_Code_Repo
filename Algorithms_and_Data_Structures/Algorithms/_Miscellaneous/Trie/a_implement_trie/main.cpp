#include <TrieNode.hpp>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Trie
{
public:
    Trie() : root(std::make_shared<TrieNode>())
    {
        // constructor
    }

    // inserting string in trie
    void Insert(std::string word)
    {
        auto current = root;
        for (auto c : word)
        {
            // if exist, move to next node. Else, create new node
            if (current->children.find(c) == current->children.end())
                current->children[c] = std::make_shared<TrieNode>();

            current = current->children[c];
        }
        current->isWord = true;
    }

    // searching for a string
    bool Search(std::string word)
    {
        auto current = root;
        for (auto c : word)
        {
            // if exist, move to next, else, return false
            if (current->children.find(c) != current->children.end())
                current = current->children[c];
            else
                return false;
        }
        return current->isWord;
    }

    // searching for a prefix
    bool SearchPrefix(std::string prefix)
    {
        auto current = root;
        for (auto c : prefix)
        {
            // if exist, move to next, else, return false
            if (current->children.find(c) != current->children.end())
                current = current->children[c];
            else
                return false;
        }
        return true;
    }

    std::shared_ptr<TrieNode> root;
};

int main()
{
    std::vector<std::string> keys = {"the", "a", "there", "answer"};
    Trie d;
    //Inserting keys
    for (int i = 0; i < keys.size(); i++)
    {
        std::cout << i + 1 << ".\tInserting key: " << keys[i] << std::endl;
        d.Insert(keys[i]);
        std::cout << std::endl;
        std::cout << std::string(100, '-') << std::endl;
    }
    // Searching keys
    std::vector<std::string> Search = {"a", "answer", "xyz", "an"};
    int num = 1;
    for (int i = 0; i < Search.size(); i++)
    {
        std::cout << num << ".\tSearching key: '" << Search[i] << "'" << std::endl;
        bool res = d.Search(Search[i]);
        std::cout << "\t" << std::boolalpha << res << std::endl;
        num += 1;
        std::cout << std::string(100, '-') << std::endl;
    }
    // Searching prefix
    std::vector<std::string> SearchP = {"b", "an"};
    for (int i = 0; i < SearchP.size(); i++)
    {
        std::cout << num << ".\tSearching prefix: '" << SearchP[i] << "'" << std::endl;
        bool res = d.SearchPrefix(SearchP[i]);
        std::cout << "\t" << std::boolalpha << res << std::endl;
        num += 1;
        std::cout << std::string(100, '-') << std::endl;
    }
}
