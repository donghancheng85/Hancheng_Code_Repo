#include <iostream>
#include <vector>
#include <complex>
#include <tuple>
using namespace std;

struct Creature
{
    int attack, health;

    Creature(int attack, int health) : attack(attack), health(health) {}
};

struct CardGame
{
    std::vector<Creature> creatures;

    CardGame(const std::vector<Creature> &creatures) : creatures(creatures) {}

    // return the index of the creature that won (is a live)
    // example:
    // - creature1 alive, creature2 dead, return creature1
    // - creature1 dead, creature2 alive, return creature2
    // - no clear winner: return -1
    int combat(int creature1, int creature2)
    {
        hit(creatures.at(creature1), creatures.at(creature2));
        hit(creatures.at(creature2), creatures.at(creature1));

        if (
            (creatures.at(creature1).health <= 0 || creatures.at(creature2).health <= 0) &&
            (creatures.at(creature1).health != creatures.at(creature2).health)
        )
            return (creatures.at(creature1).health <= 0)? creature2: creature1;
        else
            return -1;
    }

    virtual void hit(Creature& attacker, Creature& other) = 0;
};

struct TemporaryCardDamageGame : CardGame
{
    TemporaryCardDamageGame(const std::vector<Creature> &creatures) : CardGame(creatures) {}

    void hit(Creature &attacker, Creature &other) override {
        auto buf = other.health;
        other.health -= attacker.attack;
        if(other.health > 0)
            other.health = buf;
    }
};

struct PermanentCardDamageGame : CardGame
{
    PermanentCardDamageGame(const std::vector<Creature> &creatures) : CardGame(creatures) {}

    void hit(Creature &attacker, Creature &other) override
    {
        other.health -= attacker.attack;
    }
};

int main()
{
    PermanentCardDamageGame tcdg {{{2, 2}, {2, 2}}};
    auto winner = tcdg.combat(0, 1);
    std::cout << "winner is? " << winner << "\n";
}