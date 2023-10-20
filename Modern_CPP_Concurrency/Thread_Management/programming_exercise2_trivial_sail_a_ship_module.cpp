#include <thread>
#include <chrono>
#include <iostream>

void cleanerFunc()
{
	std::cout << "\nclean starts!\n";
	std::this_thread::sleep_for(std::chrono::milliseconds(5000));
	std::cout << "\nclearn finished!\n";
}

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


int main()
{
	// Captain will issue 3 commands
	// Captain can order cleaning crew to clear. And captain does not have to wait on this command untile it's done (detach)
	// Full speed and stop the engine commandes. Captain has to wait until the engine crew to finish these commands to proceed to the next command
	// write a small program takes input from console and execute these commands. 1-- cleaning. 2--full speed. 3--stop. 100--exit program. Any other number: print "Invalid order" to console
	std::size_t command{ 0 };
	bool exit{ false };

	while (!exit)
	{
		std::cout << "please input your command: ";
		std::cin >> command;

		switch (command)
		{
			case 1:
			{
				// cleaning
				std::thread cleaner(cleanerFunc);
				cleaner.detach();
				break;
			}
			case 2:
			{
				// full speed
				std::thread fullSpeed(enginCrew, command);
				fullSpeed.join();
				break;
			}
			case 3:
			{
				// stop
				std::thread stop(enginCrew, command);
				stop.join();
				break;
			}
			case 100:
				exit = true;
				break;
			default:
				std::cout << "Invalid order!\n";
				break;
		}
	}

	return 0;
}