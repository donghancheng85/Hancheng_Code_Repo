#include <iostream>
#include <thread>
#include <future>
#include <utility>

void test()
{
	std::cout << "hello from test\n";
}

void functionA(std::promise<void> syncPointMaster)
{
	std::cout << "hello from function A\n";

	std::thread threadC{test};
	threadC.join();

	syncPointMaster.set_value();
}

void functionB(std::future<void> syncPointSlave)
{
	syncPointSlave.get();
	std::cout << "hello from function B\n";
}

int main()
{
	std::promise<void> syncPointMaster;
	std::future<void> syncPointSlave = syncPointMaster.get_future();

	std::thread threadA{ functionA, std::move(syncPointMaster) };
	std::thread threadB{ functionB, std::move(syncPointSlave) };

	threadA.join();
	threadB.join();

	std::cout << "hello from main\n";
	
	return 0;
}