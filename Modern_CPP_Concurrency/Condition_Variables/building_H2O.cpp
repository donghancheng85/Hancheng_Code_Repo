#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

std::string g_water {"OOHHHHHHOOHH"};
std::mutex g_mtx;
std::condition_variable g_cv;
bool g_allPrinted {false};

void releaseHydrogen()
{
    std::cout << "H" << std::flush;
}

void releaseOxygen()
{
    std::cout << "O" << std::flush;
}

class H2O
{
public:
    H2O()
    {}

    void hydrogen(std::function<void()> releaseHydrogen)
    {
        // thread sync point
        std::unique_lock<decltype(g_mtx)> lk(g_mtx);
        g_cv.wait(lk, [this](){ return !m_enoughHydrogen && !m_oxygenTurn;});

        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        ++m_numHydrogen;
        ++m_numPrinted;

        if (m_numHydrogen >= 2)
        {
            m_enoughHydrogen = true;
            m_oxygenTurn = true;
            m_numHydrogen = 0;
        }

        if (m_numPrinted >= g_water.length())
        {
            // send back to main thread
            g_allPrinted = true;
        }

        // singal next thread to start work
        lk.unlock();
        g_cv.notify_one();
    }

    void oxygen(std::function<void()> releaseOxygen)
    {
        // thread sync point
        std::unique_lock<decltype(g_mtx)> lk(g_mtx);
        g_cv.wait(lk, [this](){ return m_enoughHydrogen && m_oxygenTurn;});

        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        ++m_numPrinted;

        m_enoughHydrogen = false;
        m_oxygenTurn = false;

        if (m_numPrinted >= g_water.length())
        {
            // send back to main thread
            g_allPrinted = true;
        }

        // singal next thread to start work
        lk.unlock();
        g_cv.notify_one();
    }

private:
    std::size_t m_numHydrogen {0};
    std::size_t m_numPrinted {0};
    bool m_enoughHydrogen {false};
    bool m_oxygenTurn {false};
};


int main()
{
    // init thread pool vector
    std::vector<std::thread> waterThreads;
    waterThreads.reserve(g_water.length());

    H2O h2o;

    // launch thread pool
    for (char c : g_water)
    {
        if (c == 'H')
        {
            waterThreads.emplace_back(&H2O::hydrogen, &h2o, releaseHydrogen);
        }
        else
        {
            waterThreads.emplace_back(&H2O::oxygen, &h2o, releaseOxygen);
        }
    }

    // main thread to signal start
    {
        std::lock_guard<decltype(g_mtx)> lk(g_mtx);
        g_cv.notify_one();
    }

    // return to main thread
    {
        std::unique_lock<decltype(g_mtx)> lk(g_mtx);
        g_cv.wait(lk, [](){return g_allPrinted;});
    }

    // join threads
    for (auto& t : waterThreads)
    {
        t.join();
    }

    std::cout << "\n\n";

    return 0;
}
