#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

struct IRat
{
    // modify attack value of each rat
    virtual void on_notify(std::size_t attack_value) = 0;
};

struct Game  // subject/observable
{
    std::vector<IRat*> rats;
    /**
     * add_rat will notify each rat in vector to increase their attack
    */
    void rat_change()
    {
        // remove "dead" rats
        rats.erase(std::remove(rats.begin(), rats.end(), nullptr), rats.end());
        auto desired_attack = rats.size();
        for (auto&& r : rats)
        {   
            if (r)
                r->on_notify(desired_attack);
            else
                rats.erase(std::remove(rats.begin(), rats.end(), r), rats.end());
        }
    }
};


struct Rat : IRat // observer
{
    Game& game;
    int attack{1};

    Rat(Game &game) : game(game)
    {
        game.rats.push_back(this);
        game.rat_change();
    }

    ~Rat() 
    { 
        auto it = std::find(game.rats.begin(), game.rats.end(), this);
        if (it != game.rats.end())
            *it = nullptr;
            game.rat_change();
    }

    void on_notify(std::size_t attack_value) override
    {
        attack = attack_value;
    }
};

int main()
{
    Game game;
    Rat rat{game};
    std::cout << "rat attack: " << rat.attack << "\n";

    Rat rat2{game};
    std::cout << "rat attack: " << rat.attack << "\n";
    std::cout << "rat2 attack: " << rat2.attack << "\n";

    {
        Rat rat3{game};

        std::cout << "rat attack: " << rat.attack << "\n";
        std::cout << "rat2 attack: " << rat2.attack << "\n";
        std::cout << "rat3 attack: " << rat3.attack << "\n";
    }

    std::cout << "rat3 dies." << "\n" ;
    std::cout << "rat attack: " << rat.attack << "\n";
    std::cout << "rat2 attack: " << rat2.attack << "\n";

}