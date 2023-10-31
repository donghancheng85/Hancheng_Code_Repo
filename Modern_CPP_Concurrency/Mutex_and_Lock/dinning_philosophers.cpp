#include <chrono>
#include <functional>
#include <iostream>
#include <mutex>
#include <thread>

/**
 * @brief Dining Philosophers. Table is like following: FN - Fork N; PN - Philosophers N
 *  F1 - P0 - F2 - P1 - F3 - P2 - F4 - P3 - F5 - P4 - F1
 *  use mutexes to represent forks.
 *  Pick a fork means aquire a mutex.
 *  Eat means aquire both mutexes (forks) on the left and right.
 *  Put a fork means release a mutex.
 */

std::mutex cout_mtx;

class DiningPhilosophers
{
public:
    DiningPhilosophers(int philosopher, std::mutex& leftFork, std::mutex& rightFork)
        : m_philosopher{ philosopher }, m_leftFork{ leftFork }, m_rightFork{ rightFork }
    {
    }

    void wantsToEat(int philosopher)
    {
        /**
         * @brief keep looping to try to lock the mutex. Main idea is:
         * We cannot let all philosopher try to get the fork on the same side. i.e. both left or right
         * which will cause dead lock -- no philosopher can get another fork
         * Therefore, one philosopher needs to get fork on the other side. In this case, philosopher 0
         * first tries to get fork on the left side. All other philosophers tries to get forks on their right
         * side.
         */
        std::unique_lock<std::mutex> leftLock(m_leftFork, std::defer_lock);
        std::unique_lock<std::mutex> rightLock(m_rightFork, std::defer_lock);

        std::lock(leftLock, rightLock);
        pickLeftFork();
        pickRightFork();
        eat();
        putLeftFork();
        putRightFork();
    }

    void pickLeftFork()
    {
        //std::lock_guard<std::mutex> lk(cout_mtx);
        std::cout << "[" << m_philosopher << ",1,1] ";
    }

    void pickRightFork()
    {
        //std::lock_guard<std::mutex> lk(cout_mtx);
        std::cout << "[" << m_philosopher << ",2,1] ";
    }

    void eat()
    {
        //std::lock_guard<std::mutex> lk(cout_mtx);
        std::cout << "[" << m_philosopher << ",0,3] ";
    }

    void putLeftFork()
    {
        //std::lock_guard<std::mutex> lk(cout_mtx);
        std::cout << "[" << m_philosopher << ",1,2] ";
    }

    void putRightFork()
    {
        //std::lock_guard<std::mutex> lk(cout_mtx);
        std::cout << "[" << m_philosopher << ",2,2] ";
    }

private:
    int m_philosopher;
    std::mutex& m_leftFork;
    std::mutex& m_rightFork;
};

int main()
{
    std::mutex fork1, fork2, fork3, fork4, fork5;
    DiningPhilosophers p0{ 0, fork1, fork2 };
    DiningPhilosophers p1{ 1, fork2, fork3 };
    DiningPhilosophers p2{ 2, fork3, fork4 };
    DiningPhilosophers p3{ 3, fork4, fork5 };
    DiningPhilosophers p4{ 4, fork5, fork1 };

    // swpan threads
    std::thread thread_p4(&DiningPhilosophers::wantsToEat, &p4, 4);
    std::thread thread_p0(&DiningPhilosophers::wantsToEat, &p0, 0);
    std::thread thread_p1(&DiningPhilosophers::wantsToEat, &p1, 1);
    std::thread thread_p2(&DiningPhilosophers::wantsToEat, &p2, 2);
    std::thread thread_p3(&DiningPhilosophers::wantsToEat, &p3, 3);


    // join threads
    thread_p4.join();
    thread_p0.join();
    thread_p1.join();
    thread_p2.join();
    thread_p3.join();

    std::cout << "\n\n";

    return 0;
}

// output of program:
// [4, 2, 1] [1, 2, 1] [1, 1, 1] [1, 0, 3] [1, 1, 2] [1, 2, 2] [2, 2, 1] [2, 1, 1]
// [2, 0, 3] [2, 1, 2] [2, 2, 2] [3, 2, 1] [3, 1, 1] [3, 0, 3] [3, 1, 2] [3, 2, 2]
// [4, 1, 1] [4, 0, 3] [4, 1, 2] [4, 2, 2] [0, 1, 1] [0, 2, 1] [0, 0, 3] [0, 1, 2]
// [0, 2, 2]
