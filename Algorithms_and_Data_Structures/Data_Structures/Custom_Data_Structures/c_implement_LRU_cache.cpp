#include <list>
#include <iostream>
#include <unordered_map>

// Using typedef to make things easier to understand

// We will use a linkedlist of a pair of integers
// where the first integer will be the key
// and the second integer will be the value

// typedef std::list<std::pair<int, int>> KeyValuePairLL;

class LRUCache
{
public:
    LRUCache() = default;
    LRUCache(int capacity) : m_capacity{capacity} {}

    int Get(int key)
    {
        if (m_lruCache.count(key))
        {
            auto listItr = m_lruCache[key];
            // since the catch is used, then move it to the front
            m_cachedKey.splice(m_cachedKey.begin(), m_cachedKey, listItr);
            return listItr->second;
        }

        return -1;
    }

    void Set(int key, int value)
    {
        if (m_lruCache.count(key) == 0)
        {
            // insert new key
            m_cachedKey.emplace_front(key, value);
            if (m_cachedKey.size() > m_capacity)
            {
                auto tempPair = m_cachedKey.back();
                m_cachedKey.pop_back();
                m_lruCache.erase(tempPair.first);
            }
        }
        else
        {
            // update existing key
            auto tempItr = m_lruCache[key];
            tempItr->second = value;
            m_cachedKey.splice(m_cachedKey.begin(), m_cachedKey, tempItr);
        }
        m_lruCache[key] = m_cachedKey.begin();
    }
private:
    int m_capacity{0};
    std::list<std::pair<int, int>> m_cachedKey{};
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_lruCache{};
};


int main()
{
    LRUCache testCache{2};
    std::cout << testCache.Get(10) << "\n\n";
    testCache.Set(10, 100);
    std::cout << testCache.Get(10) << "\n\n";
    testCache.Set(15, 50);
    std::cout << testCache.Get(10) << "\n\n";
    testCache.Set(30, 300);
    std::cout << testCache.Get(15) << "\n\n";
    std::cout << testCache.Get(30) << "\n\n";
    return 0;

}
