#include <iostream>
#include <unordered_map>
#include <vector>

class FreqStack
{
public:
    FreqStack() :
        m_maxFreq{0}
    {}

    void push(int data)
    {
        // increase frequency of data by 1
        ++m_numFreqMap[data];
        if(m_numFreqMap[data] > m_maxFreq)
            m_maxFreq = m_numFreqMap[data];

        // push back data to specific frequency it corresponding to
        m_freqGroupMap[m_numFreqMap[data]].push_back(data);
    }

    int pop()
    {
        if (m_maxFreq == 0)
            return -1;

        int topNum = m_freqGroupMap[m_maxFreq].back();
        m_freqGroupMap[m_maxFreq].pop_back();
        --m_numFreqMap[topNum];
        if (m_freqGroupMap[m_maxFreq].empty())
            --m_maxFreq;

        return topNum;
    }
private:
    // first - frequency; second - vector of numbers
    std::unordered_map<std::size_t, std::vector<int>> m_freqGroupMap;
    // first - number in the stack; second - frequency
    std::unordered_map<int, std::size_t> m_numFreqMap;
    std::size_t m_maxFreq;
};


int main()
{
    std::vector<int> stack {5, 7, 7, 7, 4, 5, 3};
    FreqStack fs;

    for(int num: stack)
        fs.push(num);

    for(std::size_t i = 0; i < stack.size(); ++i)
        std::cout << fs.pop() << " ";
    std::cout << "\n\n";

    return 0;

}
