#include <regex>
#include <string>
#include <vector>

// helper class

void Split(std::string &s, std::string &delim, std::vector<std::string> &elems)
{
    std::regex rgx(delim);
    std::sregex_token_iterator iter(s.begin(), s.end(), rgx, -1);
    std::sregex_token_iterator end;
    while (iter != end)
    {
        elems.push_back(*iter);
        ++iter;
    }
}

class Log
{
public:
    int id;
    bool isStart;
    int time;
    Log(std::string content)
    {
        std::vector<std::string> strs;
        std::string delim = ":";
        Split(content, delim, strs);
        id = stoi(strs[0]);
        isStart = strs[1] == "start";
        time = stoi(strs[2]);
    }
};
