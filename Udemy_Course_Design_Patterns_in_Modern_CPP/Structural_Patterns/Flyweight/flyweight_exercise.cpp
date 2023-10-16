#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cctype>
using namespace std;

struct Sentence
{
    struct WordToken
    {
        bool capitalize;
    };

    Sentence(const std::string& text) :
        content(text)
    {
        // Check the number of words in text
        std::stringstream stream(text);
        std::string word;
        
        while(stream >> word)
        {
            cap.emplace_back(WordToken{false});
        }
    }

    WordToken& operator[](std::size_t index)
    {
        return cap[index];
    }

    string str() const
    {
        std::stringstream stream(content);
        std::string word, out;
        int index{0};

        while(stream >> word)
        {
            if(cap[index].capitalize) 
            {
                std::transform(word.begin(), word.end(), std::back_inserter(out), ::toupper);
            }
            else
            {
                out += word;
            }
            out += " ";
            index++;
        }
        out.pop_back(); // remove the last space
        return out;
    }

private:
    std::string content;
    std::vector<WordToken> cap;
};

int main()
{
    Sentence sentence("hello world cccde   eeee");
    sentence[2].capitalize = true;
    cout << sentence.str(); // prints "hello WORLD"
}