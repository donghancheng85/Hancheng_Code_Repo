#include <iostream>
#include <string>
#include <utility>
#include <vector>

int Calculator(std::string expression)
{
    // init parameters:
    // number - current digits that read from expression
    // sign - sign of current operation. 1 = +; -1 = -
    // result - store currently evlaulated result
    int number{0};
    int sign{1};
    int result{0};

    // use a stack to push result when meet "(", pop when ")" is met
    // pair.first = evaluated result; pair.second = sign
    std::vector<std::pair<int, int>> stack;

    // traverse every character in expression
    for (auto c : expression)
    {
        // c is digit, update number. static_cast<int>(c) - 48 return the digit that c represent
        if (std::isdigit(c))
            number = 10 * number + (static_cast<int>(c) - 48);
        // c is sign (+-), evaluate result on the left then update sign. reset number and sign afterwards
        else if (c == '+' || c == '-')
        {
            result += sign * number;
            sign = (c == '+')? 1 : -1;
            number = 0;
        }
        // c is "(", push result and sign into stack, then reset result and sign
        else if (c == '(')
        {
            stack.emplace_back(result, sign);
            sign = 1;
            result = 0;
        }
        // c is ")", pop the stack and calculate the result
        else if (c == ')')
        {
            // result in ()
            result += sign * number;
            sign = 1;
            number = 0;
            auto pair = stack.back();
            stack.pop_back();

            // combine the result in () and outside result (in "higher level ()" or outside)
            result = pair.first + pair.second * result;
        }
    }

    return result + number * sign;
}


int main()
{
    std::string expression {"(12 - 9 + 4) + ( 7 - 5)"};

    std::cout << Calculator(expression) << "\n\n";
}
