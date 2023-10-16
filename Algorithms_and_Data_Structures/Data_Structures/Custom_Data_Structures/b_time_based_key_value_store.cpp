#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

class TimeStamp
{
public:
    // Set TimeMap data variables
    void SetValue(const std::string &key, const std::string &value, int timeStamp)
    {
        m_dict[key][timeStamp] = value;
    }

    // Get TimeMap data variables
    std::string GetValue(const std::string &key, int timeStamp)
    {
        if (m_dict.count(key))
        {
            if(m_dict[key].size())
            {
                auto itr = m_dict[key].lower_bound(timeStamp);
                if(itr->first != timeStamp)
                {
                    return (--itr)->second;
                }
                return itr->second;
            }
        }
        return "";
    }

private:
    // members
    std::unordered_map<std::string, std::map<int, std::string>> m_dict;
};

int main()
{
    TimeStamp ts;

    ts.SetValue("foo", "bar", 1);
    ts.SetValue("foo", "tar", 4);

    std::cout << ts.GetValue("foo", 4) << "\n\n";

}
