#include <iostream>
#include <string>
#include <memory>

// C.120: Use class hierarchies to represent concepts with inherent hierarchical structure
// Device1 and Device2 represent concepts of the interface IDevice
class IDevice
{
public:
    // C.121: If a base class is used as an interface, make it a pure abstract class
    // C.122: Use abstract classes as interfaces when complete separation of interface and implementation is needed
    virtual ~IDevice() = default;
    virtual void read() const = 0;
    virtual void write(const std::string& str) = 0;
};

class Device1: public IDevice
{
public:
    void read() const override
    {
        std::cout << "Device1 read fuc called!!\n";
    }

    void write(const std::string& str) override
    {
        std::cout << "Device1 Write " << str << " to file.\n";
    }

};

class Device2: public IDevice
{
public:
    void read() const override
    {
        std::cout << "Device2 read fuc called!!\n";
    }

    void write(const std::string& str) override
    {
        std::cout << "Device2 Write " << str << " to file.\n";
    }

};

int main()
{
    std::shared_ptr<IDevice> dev1 = std::make_shared<Device1>();
    std::shared_ptr<IDevice> dev2 = std::make_shared<Device2>();

    dev1->read();
    dev2->read();

    dev1->write("something");
    dev2->write("something else");
}