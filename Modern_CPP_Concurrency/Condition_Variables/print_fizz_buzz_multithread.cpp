/**
 * @file print_fizz_buzz_multithread.cpp
 * @author Hancheng Dong
 * @brief
 * Thread A: calls fizz() that should output the word "fizz".
 * Thread B: calls buzz() that should output the word "buzz".
 * Thread C: calls fizzbuzz() that should output the word "fizzbuzz".
 * Thread D: calls number() that should only output the integers.
 *
 * "fizzbuzz" if i is divisible by 3 and 5,
 * "fizz" if i is divisible by 3 and not 5,
 * "buzz" if i is divisible by 5 and not 3, or
 * i if i is not divisible by 3 or 5.
 *
 * @date 2023-10-26
 *
 */


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
bool g_numberTurn {true};
bool g_fizzTurn {false};
bool g_buzzTurn {false};
bool g_fizzbuzzTurn {false};
bool g_continuePrintNumber {true};
bool g_allPrinted {false};
int g_currentNumber {1};

class FizzBuzz
{
public:
    FizzBuzz(int n, bool allDone) : m_n{n}, m_allDone{allDone}
    {}

    // printFizz() outputs "fizz".
    void fizz()
    {
        while (!g_allPrinted)
        {
            //std::cout << "in fizz thread...\n" << std::flush;
            std::unique_lock<std::mutex> lk(g_mtx);
            g_cv.wait(lk, [](){ return g_fizzTurn; });

            if (g_allPrinted)
                break;

            std::cout << "\"fizz\"," << std::flush;
            processCurrentNumber();

            lk.unlock();
            g_cv.notify_all();
        }
    }

    // printBuzz() outputs "buzz".
    void buzz()
    {
        while (!g_allPrinted)
        {
            //std::cout << "in buzz thread...\n" << std::flush;
            std::unique_lock<std::mutex> lk(g_mtx);
            g_cv.wait(lk, [](){ return g_buzzTurn; });

            if (g_allPrinted)
                break;

            std::cout << "\"buzz\"," << std::flush;
            processCurrentNumber();

            lk.unlock();
            g_cv.notify_all();
        }

    }

    // printFizzBuzz() outputs "fizzbuzz".
    void fizzbuzz()
    {
        while (!g_allPrinted)
        {
            //std::cout << "in fizzbuzz thread...\n" << std::flush;
            std::unique_lock<std::mutex> lk(g_mtx);
            g_cv.wait(lk, [](){ return g_fizzbuzzTurn; });

            if (g_allPrinted)
                break;

            std::cout << "\"fizzbuzz\"," << std::flush;
            processCurrentNumber();

            lk.unlock();
            g_cv.notify_all();
        }

    }

    // printNumber(x) outputs "x", where x is an integer.
    void number()
    {
        while (!g_allPrinted)
        {
            //std::cout << "in number thread...\n" << std::flush;
            std::unique_lock<std::mutex> lk(g_mtx);
            g_cv.wait(lk, [](){ return g_numberTurn; });

            if (g_allPrinted)
                break;

            while (g_continuePrintNumber)
            {
                if (g_allPrinted)
                    break;
                std::cout << g_currentNumber << "," << std::flush;
                processCurrentNumber();
            }

            lk.unlock();
            g_cv.notify_all();
        }
    }

private:
    // helper function
    void processCurrentNumber()
    {
        ++g_currentNumber;
        if ( (g_currentNumber % 3 == 0) && (g_currentNumber % 5 != 0) )
        {
            g_numberTurn = false;
            g_fizzTurn = true;
            g_buzzTurn = false;
            g_fizzbuzzTurn = false;
            g_continuePrintNumber = false;
        }
        else if ( (g_currentNumber % 3 != 0) && (g_currentNumber % 5 == 0) )
        {
            g_numberTurn = false;
            g_fizzTurn = false;
            g_buzzTurn = true;
            g_fizzbuzzTurn = false;
            g_continuePrintNumber = false;
        }
        else if ( (g_currentNumber % 3 == 0) && (g_currentNumber % 5 == 0) )
        {
            g_numberTurn = false;
            g_fizzTurn = false;
            g_buzzTurn = false;
            g_fizzbuzzTurn = true;
            g_continuePrintNumber = false;
        }
        else
        {
            g_numberTurn = true;
            g_fizzTurn = false;
            g_buzzTurn = false;
            g_fizzbuzzTurn = false;
            g_continuePrintNumber = true;
        }

        if (g_currentNumber > m_n)
        {
            g_allPrinted = true;
            //std::cout << std::boolalpha << std::flush;
            //std::cout << "All printed!!\n";

            /* Need to sync all threads after finish , or the condition variable will keep waiting*/
            g_numberTurn = true;
            g_fizzTurn = true;
            g_buzzTurn = true;
            g_fizzbuzzTurn = true;
            g_continuePrintNumber = true;
        }
    }

private:
    int m_n;
    bool& m_allDone;
};


int main()
{
    FizzBuzz fizzbuzz(30, g_allPrinted);

    std::thread threadA(&FizzBuzz::fizz, &fizzbuzz);
    std::thread threadB(&FizzBuzz::buzz, &fizzbuzz);
    std::thread threadC(&FizzBuzz::fizzbuzz, &fizzbuzz);
    std::thread threadD(&FizzBuzz::number, &fizzbuzz);

    {
        std::lock_guard<std::mutex> lk(g_mtx);
        g_cv.notify_all();
    }


    threadA.join();
    threadB.join();
    threadC.join();
    threadD.join();

    std::cout << "\n";

    return 0;
}
