#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> SortColors(std::vector<int>& colors)
{
    // init 3 indexes
    std::size_t redI{0};
    std::size_t whiteI{0};
    std::size_t blueI{colors.size()-1};

    while(whiteI <= blueI && blueI > 0)
    {
        switch (colors[whiteI])
        {
        case 0:
            // color is red
            std::swap(colors[redI], colors[whiteI]);
            ++whiteI;
            ++redI;
            break;
        case 1:
            // color is white
            ++whiteI;
            break;
        case 2:
            // color is blue
            std::swap(colors[whiteI], colors[blueI]);
            --blueI;
            break;
        default:
            break;
        }
    }
    return colors;
}

int main()
{
    std::vector<int> colors{2,2};
    auto result = SortColors(colors);

    for (auto col : colors)
        std::cout << col << " ";
    std::cout << "\n\n";

    return 0;
}
