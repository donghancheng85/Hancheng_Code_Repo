#include <string>
#include <sstream>
#include <iostream>
using namespace std;

// forward declaration
struct Value;
struct AdditionExpression;
struct MultiplicationExpression;

struct ExpressionVisitor
{
    // accept methods here :) "accept" here means "visit"
    virtual void accept(Value& v) = 0;
    virtual void accept(AdditionExpression& ae) = 0;
    virtual void accept(MultiplicationExpression& me) = 0;
};

struct Expression
{
    virtual void visit(ExpressionVisitor& ev) = 0;
};

struct Value : Expression
{
    int value;

    Value(int value) : value(value) {}

    void visit(ExpressionVisitor& ev) override
    {
        ev.accept(*this);
    }
};

struct AdditionExpression : Expression
{
    Expression &lhs, &rhs;

    AdditionExpression(Expression &lhs, Expression &rhs) : lhs(lhs), rhs(rhs) {}

    void visit(ExpressionVisitor& ev) override
    {
        ev.accept(*this);
    }
};

struct MultiplicationExpression : Expression
{
    Expression &lhs, &rhs;

    MultiplicationExpression(Expression &lhs, Expression &rhs)
        : lhs(lhs), rhs(rhs) {}
    
    void visit(ExpressionVisitor& ev) override
    {
        ev.accept(*this);
    }
};

struct ExpressionPrinter : ExpressionVisitor
{
    // accept methods here :)
    virtual void accept(Value& v) override
    {
        oss << v.value;
    }

    virtual void accept(AdditionExpression& ae) override
    {
        oss << "(";
        ae.lhs.visit(*this);
        oss << "+";
        ae.rhs.visit(*this);
        oss << ")";
    }

    virtual void accept(MultiplicationExpression& me) override
    {
        me.lhs.visit(*this);
        oss << "*";
        me.rhs.visit(*this);
    }

    std::string str() const { return oss.str(); }

private:
    std::ostringstream oss;
};

int main()
{
    Value v2{2};
    Value v3{3};
    AdditionExpression ae{v2, v3};
    MultiplicationExpression simple{v2,ae};
    ExpressionPrinter ep;
    ep.accept(simple);

    std::cout << ep.str() << "\n";

}