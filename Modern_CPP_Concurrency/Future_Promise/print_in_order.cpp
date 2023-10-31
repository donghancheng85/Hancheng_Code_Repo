#include <condition_variable>
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>
#include <future>

void printFirst()
{
    std::cout << "first" << std::flush;
}

void printSecond()
{
    std::cout << "second" << std::flush;
}

void printThird()
{
    std::cout << "third" << std::flush;
}

class Foo
{
public:
    Foo() :
    m_firstToSecondMaster {},
    m_secondToThirdMaster {},
    m_firstToSecondSlave {m_firstToSecondMaster.get_future()},
    m_secondToThirdSlave {m_secondToThirdMaster.get_future()}
    {}

    void first(std::function<void()> printFirst)
    {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        m_firstToSecondMaster.set_value();
    }

    void second(std::function<void()> printSecond)
    {
        m_firstToSecondSlave.get();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        m_secondToThirdMaster.set_value();
    }

    void third(std::function<void()> printThird)
    {
        m_secondToThirdSlave.get();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
    std::promise<void> m_firstToSecondMaster;
    std::promise<void> m_secondToThirdMaster;
    std::future<void> m_firstToSecondSlave;
    std::future<void> m_secondToThirdSlave;
};

int main()
{
    std::vector<int> nums {3,2,1};
    std::vector<std::thread> printThreads;
    printThreads.reserve(3);

    Foo foo;

    for (int n : nums)
    {
        switch (n)
        {
        case 1:
        {
            printThreads.emplace_back(&Foo::first, &foo, printFirst);
            break;
        }
        case 2:
        {
            printThreads.emplace_back(&Foo::second, &foo, printSecond);
            break;
        }
        case 3:
        {
            printThreads.emplace_back(&Foo::third, &foo, printThird);
            break;
        }
        default:
            break;
        }
    }

    for (std::thread& t : printThreads)
    {
        t.join();
    }

    std::cout << "\n";

    return 0;
}
