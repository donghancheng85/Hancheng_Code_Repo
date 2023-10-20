#include <map>
#include <string>
#include <regex>
#include <vector>
#include <iostream>
using namespace std;


struct ExpressionProcessor
{
  std::map<char,int> variables;

  int calculate(const std::string& expression)
  {
    int result = 0;

    //regular express of +-
    std::vector<std::string> match_sequence;
    std::regex marks{R"([-+])"};
    std::smatch match;
    
    std::string cpy_expression = expression;

    enum op {nothing, plus, minus};
    auto next_op = nothing;
    while(std::regex_search(cpy_expression, match, marks))
    {
        match_sequence.push_back(match.prefix());
        match_sequence.push_back(match.str());
        cpy_expression = match.suffix();
    }
    match_sequence.push_back(cpy_expression);

    for (auto& m : match_sequence)
    {
        if (m == "+") 
        {
            next_op = plus;
            continue;
        }
        else if(m == "-") 
        {
            next_op = minus;
            continue;
        }
        
        int value;
        try{
            value = std::stoi(m);
        }catch (const invalid_argument&){
            if (m.length() == 1 &&
                variables.find(m[0]) != variables.end())
            {
                value = variables[m[0]];
            }
            else
                return 0;
        }
        
        switch (next_op)
        {
        case nothing:
            result = value;
            break;
        case plus:
            result += value;
            break;
        case minus:
            result -= value;
            break;
        default:
            return 0;
            break;
        }

    }

    return result;
  }
};

int main()

{
    // std::string s = "a+b+c+1919-56+10+x";
    // //int is = std::stoi(s);
    // //std::cout << is << "\n";
    
    // std::regex reg_char{R"((([A-Za-z]|([0-9]+))[-+])+([A-Za-z]|[0-9]+))"};
    
    // std::cout << std::boolalpha;
    // std::cout << std::regex_match(s, reg_char)  << "\n";

    // std::regex reg_single{R"(([0-9]+)|[A-Za-z]|[-+])"};
    // auto exp_begin = std::sregex_iterator(s.begin(), s.end(), reg_single);
    // auto exp_end = std::sregex_iterator();
    // for(std::sregex_iterator it = exp_begin; it != exp_end; it++)
    //   std::cout << "'" << (it->str()=="+") << "'  ";

    ExpressionProcessor ep;
    ep.variables.insert({'x', 5});

    std::cout << ep.calculate("1") << "\n";


}