#include <string>
#include <ostream>
#include <vector>
#include <iostream>
using namespace std;

/// @brief Better to define the class block as a signal class, which will be easier scaleable
struct CodeVar
{
    std::string name;
    std::string type;

    friend std::ostream& operator<<(std::ostream& os, const CodeVar& obj)
    {
        os << "  " << obj.type << " " << obj.name << ";\n";
        return os;
    }
};

/// @brief Class body, holds a vector for CodeVar, which represents the function body
struct Code
{
    std::string class_name;
    std::vector<CodeVar> variable; // name, type

    friend std::ostream& operator<<(std::ostream& os, const Code& obj)
    {
        os << "class " << obj.class_name << "\n";
        os << "{" << "\n";
        for (auto var : obj.variable)
        {
            os << var;
        }
        os << "};" << "\n";
        return os;
    }
};


class CodeBuilder
{
private:
    Code root;
public:
    CodeBuilder(const std::string& class_name)
    {
        root.class_name = class_name;
    }

    CodeBuilder& add_field(const std::string& name, const std::string& type)
    {
        root.variable.emplace_back(CodeVar{name, type});
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const CodeBuilder& obj)
    {
        os << obj.root;
        return os;
    }
};

int main()
{
    auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age", "int");
    std::cout << cb;
}