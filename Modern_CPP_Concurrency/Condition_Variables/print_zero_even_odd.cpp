#include <condition_variable>
#include <functional>
#include <future>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

// global variables
std::condition_variable g_cv;
std::mutex g_mtx;
bool g_zeroTurn{true};
bool g_oddTurn{true};
// bool g_evenTurn{false};

void printNumber(int n)
{
    std::cout << n << std::flush;
}

class ZeroEvenOdd
{
public:
    ZeroEvenOdd(int n, bool& zeroTurn, bool& oddTurn) : m_n{n}, m_zeroTurn{zeroTurn}, m_oddTurn{oddTurn}
    {
        m_totalNum = 2 * m_n;
        m_oddPrintNum = (m_n % 2 == 0)? m_n/2 : (m_n/2 + 1);
        m_evenPrintNum = m_n/2;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero()
    {
        for (std::size_t i = 0; i < m_n; ++i)
        {
            std::unique_lock<std::mutex> lk(g_mtx);
            g_cv.wait(lk, [this]() { return g_zeroTurn; });

            std::cout << 0 << std::flush;
            ++m_numPrinted;
            g_zeroTurn = false;

            lk.unlock();
            g_cv.notify_all();
        }
    }

    void even()
    {
        for (std::size_t i = 0; i < m_evenPrintNum; ++i)
        {
            std::unique_lock<std::mutex> lk(g_mtx);
            g_cv.wait(lk, [this]() { return !g_zeroTurn && !g_oddTurn; });

            std::cout << m_currentNum << std::flush;
            ++m_numPrinted;
            ++m_currentNum;

            g_zeroTurn = true;
            g_oddTurn = true;

            if (m_numPrinted == m_totalNum)
            {
                m_allDone = true;
            }

            lk.unlock();
            g_cv.notify_all();
        }
    }

    void odd()
    {
        for (std::size_t i = 0; i < m_oddPrintNum; ++i)
        {
            std::unique_lock<std::mutex> lk(g_mtx);
            g_cv.wait(lk, [this]() { return !g_zeroTurn && g_oddTurn; });

            std::cout << m_currentNum << std::flush;
            ++m_numPrinted;
            ++m_currentNum;

            g_zeroTurn = true;
            g_oddTurn = false;

            if (m_numPrinted == m_totalNum)
            {
                m_allDone = true;
            }

            lk.unlock();
            g_cv.notify_all();
        }
    }

private:
    int m_n;
    std::size_t m_oddPrintNum, m_evenPrintNum;
    std::size_t m_totalNum;
    std::size_t m_numPrinted{0};
    std::size_t m_currentNum{1};
    bool m_allDone{false};
    bool& m_zeroTurn, m_oddTurn;
};


int main()
{
    ZeroEvenOdd zeo(6, g_zeroTurn, g_oddTurn);

    std::thread threadA(&ZeroEvenOdd::zero, &zeo);
    std::thread threadB(&ZeroEvenOdd::even, &zeo);
    std::thread threadC(&ZeroEvenOdd::odd, &zeo);

    // init processing from main
    {
        std::lock_guard<std::mutex> lk(g_mtx);
        g_cv.notify_one();
    }

    // {
    //     std::unique_lock<std::mutex> lk(g_mtx);
    //     g_cv.wait(lk);
    // }


    threadA.join();
    threadB.join();
    threadC.join();

    std::cout << "\n";

    return 0;
}
