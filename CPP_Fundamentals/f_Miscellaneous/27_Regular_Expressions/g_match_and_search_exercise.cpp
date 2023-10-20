#include <regex>
#include <string>
#include <iostream>

int main()
{
    //std::regex email_rgx{R"(\b[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,}\b)"};
    std::regex email_rgx{"(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+"};
    std::string str = "this is only for test ggh@fft.com try to match";

    std::smatch smatch_res;

    if(std::regex_search(str, smatch_res, email_rgx))
    {
        std::cout << "Find email addreass in str!\n"
                  << "The match is: "
                  << smatch_res[0] << "\n"
                  << "Before the email address: " << smatch_res.prefix() << "\n"
                  << "After the email address: " << smatch_res.suffix() << "\n";
                  
    }
    else
    {
        std::cout << "No email address find in str!\n";
    }

}