/**
 * @brief A coding problem of State Pattern --  Combination lock.
 *
 * A combination lock use only digits as its password
 * It has 4 states: Locked, Inputing, Open, Error
 *
 * Locked: It is the init state. Starts to receive user's input number by number.
 * If the user's input matches, transfer to Inputing state. Otherwise to Error.
 *
 * Inputing: continue receiving user's input. If the input is correct, continue.
 * Otherwise, transfer to Error. If user's input has matched all digits in the password.
 * transfer to Open.
 *
 * Open: one of the final states. It represent the lock is open and then transfer to Locked state.
 *
 * Error: one of the final states. It represent the input does not match the password and then
 * transfer to Locked state.
 *
 */


#include <iostream>
#include <vector>
#include <memory>
#include <string>

// forward declaration
class Context;
class Locked;
class Inputing;
class Open;
class Error;

/**
 * @brief interface of all derived states
 */
class IState
{
public:
    IState() :
        m_pcontext{}
    {}

    explicit IState(std::weak_ptr<Context> context) :
        m_pcontext{ context }
    {}

    void setContext(std::weak_ptr<Context> context)
    {
        m_pcontext = context;
    }

    virtual void handleInput() const = 0;

    virtual ~IState() = default;

protected:
    // use weak_ptr to avoid cyclic reference with Context class
    // Context class already has a shared_ptr points to IState
    std::weak_ptr<Context> m_pcontext;
};


/**
 * @brief Context to hold the state and the passoword. Also handle state transition
 * using handleInput() function, which calls the handleInput() function of the state
 * class
 * Note: the class must be instantiated on the heap by calling getContextInstance()
 */
class Context : public std::enable_shared_from_this<Context>
{
public:
    // static factory function to produce new Context object that
    // pointed by a shared_ptr
    static std::shared_ptr<Context> getContextInstance()
    {
        return std::shared_ptr<Context>(new Context());
    }

    void transitionTo(std::shared_ptr<IState> stateP)
    {
        m_state = stateP;
        m_state->setContext(shared_from_this());
    }

    void setPassword(const std::vector<int>& password)
    {
        m_password = password;
    }

    void handleInput()
    {
        m_state->handleInput();
    }

public:
    std::string m_currentIput;
    std::size_t m_inputCount;
    std::vector<int> m_password;

private:
    Context() :
        m_currentIput{},
        m_inputCount{ 0 },
        m_password{},
        m_state{ nullptr }
    {}
    std::shared_ptr<IState> m_state;
};

/**
 * @brief Derived states
 */

class Locked : public IState
{
public:
    void handleInput() const override;
};

class Inputing : public IState
{
public:
    void handleInput() const override;
};

class Open : public IState
{
public:
    void handleInput() const override;
};

class Error : public IState
{
public:
    void handleInput() const override;
};


/**
 * @brief Define functions
 */

void Locked::handleInput() const
{
    // handle edge case
    auto contextSp = m_pcontext.lock();
    if (contextSp->m_inputCount > 0)
    {
        contextSp->m_inputCount = 0;
        contextSp->m_currentIput = "";
    }

    std::cout << "current state: Locked.\n";

    if (contextSp->m_currentIput == std::to_string(contextSp->m_password.at(contextSp->m_inputCount)))
    {
        // Edge case: one digit password
        if (contextSp->m_inputCount == contextSp->m_password.size())
        {
            // all passoword correct, transit to open
            contextSp->transitionTo(std::make_shared<Open>());
            std::cout << "correct input! lock opened!\n";
            return;
        }

        // correct input, transit to Inputing
        ++contextSp->m_inputCount;
        contextSp->transitionTo(std::make_shared<Inputing>());
        std::cout << "correct input! transitting to Inputing state!\n";
    }
    else
    {
        // wrong input, transit to Error
        contextSp->m_inputCount = 0;
        contextSp->m_currentIput = "";
        contextSp->transitionTo(std::make_shared<Error>());
        std::cout << "wrong input! transitting to Error state!\n";
    }
}

void Inputing::handleInput() const
{
    std::cout << "current state: Inputing.\n";
    auto contextSp = m_pcontext.lock();

    if (contextSp->m_currentIput == std::to_string(contextSp->m_password.at(contextSp->m_inputCount)))
    {
        ++contextSp->m_inputCount;
        if (contextSp->m_inputCount == contextSp->m_password.size())
        {
            // all passoword correct, transit to open
            contextSp->transitionTo(std::make_shared<Open>());
            std::cout << "correct input! lock opened!\n";
            return;
        }
        std::cout << "correct input! continue input!\n";
    }
    else
    {
        // wrong input, transit to Error
        contextSp->m_inputCount = 0;
        contextSp->m_currentIput = "";
        contextSp->transitionTo(std::make_shared<Error>());
        std::cout << "wrong input! transitting to Error state!\n";
    }
}

void Open::handleInput() const
{
    std::cout << "current state: Open.\n";
    auto contextSp = m_pcontext.lock();

    contextSp->m_inputCount = 0;
    contextSp->m_currentIput = "";

    std::cout << "transitting back to Locked\n";
    contextSp->transitionTo(std::make_shared<Locked>());
}

void Error::handleInput() const
{
    std::cout << "current state: Error.\n";
    auto contextSp = m_pcontext.lock();

    contextSp->m_inputCount = 0;
    contextSp->m_currentIput = "";

    std::cout << "transitting back to Locked\n";
    contextSp->transitionTo(std::make_shared<Locked>());
}


int main()
{
    // init
    std::shared_ptr<Context> lockContext = Context::getContextInstance();
    std::shared_ptr<IState> state = std::make_shared<Locked>();
    lockContext->setPassword(std::vector<int>{1, 2});
    lockContext->transitionTo(state);

    // simulate input password
    std::vector<int> inputPassoword{ 1,2 };
    for (int digit : inputPassoword)
    {
        lockContext->m_currentIput = std::to_string(digit);
        lockContext->handleInput();
    }

    return 0;
}

// Output:
// current state: Locked.
// correct input!transitting to Inputing state!
// current state : Inputing.
// correct input!lock opened!
