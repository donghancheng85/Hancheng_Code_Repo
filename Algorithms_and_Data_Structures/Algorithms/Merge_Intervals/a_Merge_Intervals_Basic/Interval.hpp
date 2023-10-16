#pragma once
#include <string>

class Interval
{
public:
    int start, end;
    bool closed{true};
    Interval(int s, int e) : start{s}, end{e}
    {
        closed = true; // by default, the interval is closed
    }
    // set the flag for closed/open
    void SetClosed(bool c)
    {
        closed = c;
    }
    std::string ToString()
    {
        return (this->closed) ? "[" + std::to_string(this->start) + ", " + std::to_string(this->end) + "]"
                              : "(" + std::to_string(this->start) + ", " + std::to_string(this->end) + ")";
    }
};
