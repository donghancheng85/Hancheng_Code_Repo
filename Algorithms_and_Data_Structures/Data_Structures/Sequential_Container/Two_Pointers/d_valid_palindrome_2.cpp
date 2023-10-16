#include <string>
#include <algorithm>
#include <iostream>

bool validPalindrome(const std::string& arr)
{
    auto diff = std::mismatch( arr.begin(), arr.begin() + arr.length()/2, 
                               arr.rbegin(), arr.rbegin() + arr.length()/2);
    if ( diff.first == arr.begin() + arr.length()/2)
        return true;

    return ( std::equal(diff.first+1, diff.first+1 + (diff.second.base() - (diff.first+1))/2,
                        diff.second,  diff.second + (diff.second.base() - (diff.first+1))/2 ) ) ||
           ( std::equal(diff.first, diff.first + ((diff.second+1).base() - (diff.first))/2,
                        diff.second+1,  diff.second+1 + ((diff.second+1).base() - (diff.first))/2 ) );

}

int main()
{
    std::string str = "eeccccbebaeeabebccceea";

    std::cout << std::boolalpha;
    std::cout << validPalindrome(str) << "\n\n";

}