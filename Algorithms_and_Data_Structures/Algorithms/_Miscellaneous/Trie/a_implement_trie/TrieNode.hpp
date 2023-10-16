#pragma once
#include <map>
#include <memory>

class TrieNode {
   public:
       std::map<char, std::shared_ptr<TrieNode>> children;
       bool isWord;

       TrieNode() : children(), isWord(false)
       {
       }
};
