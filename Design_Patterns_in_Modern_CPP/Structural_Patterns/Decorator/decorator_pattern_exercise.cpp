#include <string>
#include <iostream>
#include <sstream>
using namespace std;

struct Flower
{
    virtual ~Flower() = default;
    virtual string str() = 0;
};

struct Rose : Flower
{
    std::string color{};
    string str() override {
        std::ostringstream oss;
        oss << "A rose";
        return oss.str();
    }
};

struct RedFlower : Flower
{
public:
    std::string color{"red"};
    Flower& flower;
    RedFlower(Flower& f)
        : flower{f}
    {}

    std::string str() override
    {
        std::ostringstream oss;
        oss << flower.str();
        if(oss.str().find(color) == std::string::npos)
        {
            if(oss.str().find("that is") == std::string::npos)
                oss << " that is red";
            else
                oss << " and red";
        }

        return oss.str();
    }
};

struct BlueFlower : Flower
{
public:
    std::string color{"blue"};
    Flower& flower;
    BlueFlower(Flower& f)
        : flower{f}
    {}

    std::string str() override
    {
        std::ostringstream oss;
        oss << flower.str();
        if(oss.str().find(color) == std::string::npos)
        {
            if(oss.str().find("that is") == std::string::npos)
                oss << " that is blue";
            else
                oss << " and blue";
        }
        return oss.str();
    }
};


int main()
{
    Rose rose;
    RedFlower red_rose{rose};
    RedFlower red_red_rose{red_rose};
    BlueFlower blue_red_rose{red_rose};

    RedFlower rbr_rose{blue_red_rose};
    std::cout << rose.str() << "\n";          // "A rose"
    std::cout << red_rose.str()<< "\n";      // "A rose that is red"
    std::cout << red_red_rose.str()<< "\n";  // "A rose that is red"
    std::cout << blue_red_rose.str()<< "\n"; // "A rose that is red and blue"
    std::cout << rbr_rose.str()<< "\n";
}