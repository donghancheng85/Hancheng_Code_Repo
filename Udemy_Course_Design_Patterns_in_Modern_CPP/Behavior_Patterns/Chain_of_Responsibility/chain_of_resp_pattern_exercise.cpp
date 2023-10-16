#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct Creature;
struct Game
{
  std::vector<Creature*> creatures;
};

struct StatQuery
{
  enum Statistic { attack, defense } statistic;
  int result;
};

struct Creature
{
protected:
  Game& game;
  int base_attack, base_defense;

public:
  Creature(Game &game, int base_attack, int base_defense) : game(game), base_attack(base_attack),
                                                            base_defense(base_defense) {}
  virtual ~Creature() = default;
  virtual int get_attack() { return base_attack; }
  virtual int get_defense() { return base_defense; }
  /**
   * query is a centralized chain of responsibility method and an interface to all derived classes.
   * When the derived classes want to check its status, they need to loop all the creatures in game.creatures
   * and call the overrided method of that class.
  */
  virtual void query(Creature* creature, StatQuery& sq) = 0;
};

class Goblin : public Creature
{
public:
  Goblin(Game &game, int base_attack, int base_defense) : Creature(game, base_attack, base_defense) {}

  Goblin(Game &game) : Creature(game, 1, 1) { }

  virtual ~Goblin() = default;
  
  /**
   * Goblin query method. will add other's defense by 1.
   * If the object is this, then add the base statistic.
  */
  void query(Creature* creature, StatQuery& sq) override
  {
    if (creature != this)
    {
        if (sq.statistic == StatQuery::Statistic::defense)
            sq.result++;
    }
    else
    {
        switch (sq.statistic)
        {
        case StatQuery::Statistic::attack :
            sq.result += base_attack;
            break;
        case StatQuery::Statistic::defense :
            sq.result += base_defense;
            break;
        default:
            break;
        }
    }
  }

  int get_data(StatQuery::Statistic stat)
  {
    StatQuery sq{stat, 0};
    for (auto c : game.creatures)
    {
        c->query(this, sq);
    }
    return sq.result;
  }

  int get_attack() override {
    return get_data(StatQuery::Statistic::attack);
  }

  int get_defense() override {
    return get_data(StatQuery::Statistic::defense);
  }
};

class GoblinKing : public Goblin
{
public:
  GoblinKing(Game &game) : Goblin(game, 3, 3) {}
  
  /**
   * GoblinKing query method. Will add both attack and defense of others by 1.
   * If this object, just add the base value.
  */
  void query(Creature* creature, StatQuery& sq) override
  {
    if (creature != this)
    {
        sq.result++;
    }
    else
    {
        Goblin::query(creature, sq);
    }
  }

  int get_data_k(StatQuery::Statistic stat)
  {
    StatQuery sq{stat, 0};
    for (auto c : game.creatures)
    {
        c->query(this, sq);
    }
    return sq.result;
  }

  int get_attack() override {
    return get_data_k(StatQuery::Statistic::attack);
  }

  int get_defense() override {
    return get_data_k(StatQuery::Statistic::defense);
  }

};


int main()
{
  Game game;
  Goblin goblin(game);
  game.creatures.push_back(&goblin);
  Goblin goblin2{game};
  game.creatures.push_back(&goblin2);
  GoblinKing goblin3{game};
  game.creatures.push_back(&goblin3);

  std::cout << goblin.get_attack() << "\n";
  std::cout << goblin.get_defense() << "\n";

}