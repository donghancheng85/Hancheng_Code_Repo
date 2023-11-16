#pragma once
#pragma once

#include <vector>
#include <thread>

/* RAII style single thread joiner */
class thread_guard {

	std::thread& t;

public:
	explicit thread_guard(std::thread& _t) : t(_t)
	{}

	~thread_guard()
	{
		if (t.joinable())
		{
			t.join();
		}
	}

	thread_guard(thread_guard& const) = delete;
	thread_guard& operator= (thread_guard& const) = delete;
};

/* RAII style multiple threads joiner */
class join_threads {
	std::vector<std::thread>& threads;

public:
	explicit join_threads(std::vector<std::thread>& _threads) :
		threads(_threads)
	{}

	~join_threads()
	{
		for (long i = 0; i < threads.size(); i++)
		{
			if (threads[i].joinable())
				threads[i].join();
		}
	}

};