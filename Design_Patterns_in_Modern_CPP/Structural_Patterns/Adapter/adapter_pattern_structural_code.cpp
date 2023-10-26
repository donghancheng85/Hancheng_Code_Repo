#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>

/**
 * @brief A structural Adapter Pattern
 *
 * @class IAdapter: interface of all adapters
 * @class LegecyCode: simulation of legacy code that take int as data
 * @class IntToStringAdapter: convert legacy int to string
 *
 */

class IAdapter
{
public:
    virtual std::string adaptedInterface() = 0;
    virtual ~IAdapter() = default;
};


class LegacyCode
{
public:
    explicit LegacyCode(int data) : m_data{data}{}

    int getData()
    {
        return m_data;
    }

private:
    int m_data;
};


class IntToStringAdapter : public IAdapter
{
public:
    explicit IntToStringAdapter(LegacyCode& lc) : m_legacyAdaptee{lc}{}

    std::string adaptedInterface() override
    {
        return std::to_string(m_legacyAdaptee.getData());
    }

private:
    LegacyCode& m_legacyAdaptee;
};



int main()
{
    LegacyCode intWrapper{13};

    std::unique_ptr<IAdapter> stringAdapter = std::make_unique<IntToStringAdapter>(intWrapper);

    // get string output
    auto strOut = stringAdapter->adaptedInterface();

    std::cout << strOut << "\n";

    return 0;
}
