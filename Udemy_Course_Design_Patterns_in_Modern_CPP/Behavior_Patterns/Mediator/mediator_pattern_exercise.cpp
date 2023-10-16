#include <vector>
#include <string>
#include <iostream>
using namespace std;

struct IParticipant
{
    virtual ~IParticipant() = default;
    virtual void receive (int value) = 0;
};
struct Mediator
{
    std::vector<IParticipant*> participants;
    void broadcast (int value, IParticipant* source)
    {
        for (auto p : participants)
        {
            if ( source != p )
                p->receive(value);
        }
    }
};

struct Participant : IParticipant
{
    int value{0};
    Mediator& mediator;

    Participant(Mediator &mediator) : mediator(mediator)
    {
        mediator.participants.push_back(this);
    }

    void say(int value)
    {
        mediator.broadcast(value, this);
    }

    virtual void receive (int val) override
    {
        value += val;
    }
};

int main()
{
    Mediator md;
    Participant p1{md};
    Participant p2{md};
    Participant p3{md};

    p1.say(8);
    p2.say(3);

    std::cout << p1.value << "\n" 
              << p2.value << "\n" 
              << p3.value << "\n";
}