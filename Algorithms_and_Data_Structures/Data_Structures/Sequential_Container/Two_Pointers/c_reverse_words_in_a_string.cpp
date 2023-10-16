#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

std::string ReverseWords(std::string& sentence)
{
    std::stringstream wordStream{sentence};
    std::string word; //to temp store the words in the sentence 
    std::vector<std::string> wordsVec; // vector to store the words in the sentence

    while(wordStream >> word)
        wordsVec.push_back(word);

    sentence = "";
    std::reverse(wordsVec.begin(), wordsVec.end());
    for(auto& w : wordsVec)
    {
        sentence += w;
        sentence += " ";
    }
    sentence.pop_back();

    return sentence;
}


int main()
{
    std::string str = "Hey";

    auto result = ReverseWords(str);

    std::cout << result << "\n\n";
}