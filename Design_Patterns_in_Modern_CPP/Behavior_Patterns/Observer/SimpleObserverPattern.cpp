#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

/**
 * @brief A simple Observer Pattern demo
 * Publisher will publish data (string) to the observers
 * Observer will receive the data and print it on the console
 *
 * Publisher will be able to let the observers to subscribe and unsubscribe its service
 *
 */

// forward declaration
class Publisher;

class IObserver
{
public:
    IObserver(Publisher& publisher) : m_publisher{publisher}{}
    virtual void onNotify(std::string) = 0;
    virtual ~IObserver() = default;

protected:
    Publisher& m_publisher;
};

// Publisher can also defined as an interface for unit testing
class Publisher
{
public:
    Publisher() = default;
    void subscribe(IObserver* observer)
    {
        m_observers.push_back(observer);
    }

    void unsubscribe(IObserver* observer)
    {
        m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), observer), m_observers.end());
    }

    void onNotify()
    {
        for (const auto& observer: m_observers)
        {
            if (observer)
            {
                observer->onNotify(m_data);
            }
        }
    }

    void setdata(const std::string& data)
    {
        m_data = data;
    }

private:
    std::string m_data;
    std::vector<IObserver*> m_observers;
};

class Observer1 : public IObserver
{
public:
    Observer1 (Publisher& publisher) : IObserver(publisher){};

    void onNotify(std::string data) override
    {
        std::cout << "Observer1 received data: " << data << "\n";
    }

    virtual ~Observer1()
    {
        m_publisher.subscribe(this);
    }
};

class Observer2 : public IObserver
{
public:
    Observer2 (Publisher& publisher) : IObserver(publisher){};

    void onNotify(std::string data) override
    {
        std::cout << "Observer2 received data: " << data << "\n";
    }

    virtual ~Observer2()
    {
        m_publisher.unsubscribe(this);
    }
};


int main()
{
    Publisher dataProvider;

    std::shared_ptr<IObserver> observer1 = std::make_shared<Observer1>(dataProvider);
    std::shared_ptr<IObserver> observer2 = std::make_shared<Observer2>(dataProvider);

    dataProvider.subscribe(observer1.get());
    dataProvider.subscribe(observer2.get());

    dataProvider.setdata("some important data!!");
    dataProvider.onNotify();

    std::cout << "\n\n";

    {
        std::shared_ptr<IObserver> observer3 = std::make_shared<Observer2>(dataProvider);
        dataProvider.subscribe(observer3.get());
        dataProvider.onNotify();
    }
    std::cout << "\n\n";
    dataProvider.unsubscribe(observer1.get());

    dataProvider.onNotify();

    return 0;
}
