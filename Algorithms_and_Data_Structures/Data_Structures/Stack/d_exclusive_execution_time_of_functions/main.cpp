#include <iostream>
#include <string>
#include <vector>

#include "Logs.hpp"

std::vector<int> ExclusiveTime(int numberofFunction, const std::vector<std::string> &logs)
{
    const int OFFSET_TIME{1};
    const int INITIAL_VALUE{0};

    std::vector<Log> logStack{};
    logStack.reserve(logs.size());

    std::vector<int> calculatedExecutionTime(numberofFunction, INITIAL_VALUE);

    for (const auto& logEntry : logs)
    {
        Log currentLog(logEntry);
        if (currentLog.isStart)
        {
            logStack.push_back(currentLog);
        }
        else // function execution end
        {
            Log popedLog = logStack.back();
            logStack.pop_back();
            int executionPeriod = currentLog.time - popedLog.time + OFFSET_TIME;

            // add the calculated time period to the result vector calculatedExecutionTime
            calculatedExecutionTime[popedLog.id] += executionPeriod;

            // substract calculated time period of the remaining functions in the stack, if any
            if (!logStack.empty())
            {
                calculatedExecutionTime[logStack.back().id] -= executionPeriod;
            }
        }
    }

    return calculatedExecutionTime;
}

int main()
{
    int numberofFunction = 6;
    std::vector<std::string> logs{"0:start:0",
                                  "1:start:5",
                                  "2:start:8",
                                  "3:start:12",
                                  "4:start:15",
                                  "5:start:19",
                                  "5:end:22",
                                  "4:end:24",
                                  "3:end:27",
                                  "2:end:32",
                                  "1:end:35",
                                  "0:end:36"};

    auto result = ExclusiveTime(numberofFunction, logs);

    for (int i = 0; i < numberofFunction; ++i)
    {
        std::cout << "function " << i << " execution time = " << result[i] << "\n";
    }
    std::cout << "\n";
}
