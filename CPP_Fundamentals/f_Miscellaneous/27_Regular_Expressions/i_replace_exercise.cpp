#include <iostream>
#include <regex>
#include <string>

/**
 * $: The dollar sign is used to reference captured groups in the regex pattern. 
 * $1 refers to the first captured group, 
 * $2 refers to the second captured group, and so on. 
 * These captured groups are defined using parentheses in the regex pattern.
 * 
 * &: The ampersand represents the entire matched substring. 
 * If you use & in the replacement pattern, it will be replaced with the entire matched substring.
 * 
 * \: The backslash is an escape character. 
 * If you want to include a literal dollar sign, ampersand, or backslash in the replacement pattern, 
 * you need to escape it with a backslash (\$, \&, \\).
*/

int main()
{
    std::string ger_str {"+0,85 -13,2 1,0 ,45 -13,7 1,03425 10134,25"};
    std::regex ger_reg {R"(,)"};

    std::string us_str{std::regex_replace(ger_str, ger_reg, ".")};

    std::cout << us_str << "\n";
}