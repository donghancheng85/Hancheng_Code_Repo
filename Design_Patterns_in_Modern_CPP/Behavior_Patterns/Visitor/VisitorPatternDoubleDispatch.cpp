#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

/**
 * @brief A Visitor Pattern demo using double dispatch
 * ICarPart represents the interface of all car parts
 * ICarPartVisitor represent the visitor of the car parts
 *
 * This demo uses double dispatch
 */

// forward declaration
class ICarPart;
class Engine;
class Body;
class Door;

class ICarPartVisitor // First dispatch: dynamic dispatch through virtual functions
{
public:
    virtual ~ICarPartVisitor() = default;

    virtual void visit(Engine* engine) = 0; // second dispatch: static dispatch through function overloading
    virtual void visit(Body* body) = 0;
    virtual void visit(Door* door) = 0;
};

class ICarPart
{
public:
    ICarPart(const std::string& partName) : m_partName{partName} {}
    virtual ~ICarPart() = default;

    virtual void acceptCarVisitor(ICarPartVisitor* visitor) = 0;
    std::string m_partName;
};

class Engine : public ICarPart
{
public:
    Engine(const std::string& partName) : ICarPart(partName) {}

    void acceptCarVisitor(ICarPartVisitor* visitor) override
    {
        visitor->visit(this);
    }
};

class Body : public ICarPart
{
public:
    Body(const std::string& partName) : ICarPart(partName) {}

    void acceptCarVisitor(ICarPartVisitor* visitor) override
    {
        visitor->visit(this);
    }
};

class Door : public ICarPart
{
public:
    Door(const std::string& partName) : ICarPart(partName) {}

    void acceptCarVisitor(ICarPartVisitor* visitor) override
    {
        visitor->visit(this);
    }
};


class CarPrintVisitor : public ICarPartVisitor
{
public:
    void visit(Engine* engine) override
    {
        std::cout << "visited engine: " << engine->m_partName << "\n";
    }

    void visit(Body* body) override
    {
        std::cout << "visited body: " << body->m_partName << "\n";
    }

    void visit(Door* door) override
    {
        std::cout << "visited door: " << door->m_partName << "\n";
    }
};



int main()
{
    std::shared_ptr<ICarPart> fordEngine = std::make_shared<Engine>("ford engine");
    std::shared_ptr<ICarPart> fordBody = std::make_shared<Body>("ford body");
    std::shared_ptr<ICarPart> fordDoor = std::make_shared<Door>("ford door");

    std::shared_ptr<ICarPartVisitor> visitor = std::make_shared<CarPrintVisitor>();

    fordEngine->acceptCarVisitor(visitor.get());
    fordBody->acceptCarVisitor(visitor.get());
    fordDoor->acceptCarVisitor(visitor.get());

    return 0;
}
