#include <thread>
#include <chrono>
#include <iostream>
#include <deque>

/**
* have 2 std::queue type variables. Engine queue and clean work queue
* Engine and cleaning crew should represent by one thread each not from one function
* These threads should run iteratively while checking for done flag with should be set upon the user request from the console which is input 100 to stop
* In each iteration, each thread check corresponding queue for a works. You can put command from the main thread to each corresponding queue
* If running thread find any command in the corresponding queue it should execute the command and sleep for 1 second. If not, sleep for 2 seconds.
* Captain does not have to wait for any command to finish and it should take 1 command for every 1 second (at least).
*/

namespace Cleaner
{
	std::deque<std::size_t> cleanerCommands;
	bool cleanerExit{ false };

	void cleanerFunc()
	{
		std::cout << "\nclean starts!\n";
		std::this_thread::sleep_for(std::chrono::milliseconds(5000));
		std::cout << "\nclearn finished!\n";
	}

	void cleanerThreadFactory()
	{
		while (!cleanerExit)
		{
			if (cleanerCommands.empty())
				std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			else
			{
				std::size_t command = cleanerCommands.front();
				cleanerCommands.pop_front();
				switch (command)
				{
				case 1:
				{
					// cleaning
					std::thread cleaner(cleanerFunc);
					cleaner.detach();
					break;
				}
				case 100:
					cleanerExit = true;
					break;
				default:
					break;
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
		}
	}
}

namespace EngineCrew
{
	std::deque<std::size_t> engineCrewCommands;
	bool engineCrewExit{ false };

	void enginCrew(std::size_t command)
	{
		switch (command)
		{
		case 2:
			std::cout << "\nspeed up!\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
			std::cout << "\nfull speed!\n";
			break;
		case 3:
			std::cout << "\nslowing down!\n";
			std::this_thread::sleep_for(std::chrono::milliseconds(5000));
			std::cout << "\nstopped!\n";
			break;
		default:
			break;
		}
	}

	void engineCrewThreadFactory()
	{
		while (!engineCrewExit)
		{
			if(engineCrewCommands.empty())
				std::this_thread::sleep_for(std::chrono::milliseconds(2000));
			else
			{
				std::size_t command = engineCrewCommands.front();
				engineCrewCommands.pop_front();
				switch (command)
				{
				case 2:
				case 3:
				{
					// stop
					std::thread stop(enginCrew, command);
					stop.join();
					break;
				}
				case 100:
					engineCrewExit = true;
					break;
				default:
					break;
				}
				std::this_thread::sleep_for(std::chrono::milliseconds(1000));
			}
		}
	}
}


int main()
{
	// Captain will issue 3 commands
	// Captain can order cleaning crew to clear. And captain does not have to wait on this command untile it's done (detach)
	// Full speed and stop the engine commandes. Captain has to wait until the engine crew to finish these commands to proceed to the next command
	// write a small program takes input from console and execute these commands. 1-- cleaning. 2--full speed. 3--stop. 100--exit program. Any other number: print "Invalid order" to console
	std::size_t command{ 0 };
	bool exit{ false };

	std::thread cleanerThread(Cleaner::cleanerThreadFactory);
	std::thread engineCrewThread(EngineCrew::engineCrewThreadFactory);

	while (!exit)
	{
		std::cout << "please input your command: ";
		std::cin >> command;

		switch (command)
		{
		case 1:
			// cleaning
			Cleaner::cleanerCommands.push_back(command);
			break;
		case 2:
			// full speed
			EngineCrew::engineCrewCommands.push_back(command);
			break;
		case 3:
			// stop
			EngineCrew::engineCrewCommands.push_back(command);
			break;
		case 100:
			Cleaner::cleanerCommands.push_back(command);
			EngineCrew::engineCrewCommands.push_back(command);
			exit = true;
			break;
		default:
			std::cout << "Invalid order!\n";
			break;
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	cleanerThread.join();
	engineCrewThread.join();

	return 0;
}