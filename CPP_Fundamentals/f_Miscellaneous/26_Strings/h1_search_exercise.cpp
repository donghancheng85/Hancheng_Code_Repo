#include <iostream>
#include <string>

int main()
{
  std::string str;

  str= {"dkeu84kf8k48kdj39kdj74945du942"};
  std::string str2{"84"};

  /**
   * variation1 :
   * size_type find( const basic_string& str, size_type pos = 0 ) const noexcept;
   * Finds the first substring equal to str.
  */
  auto pos1 = str.find(str2);
  if (pos1 == std::string::npos)
    std::cout << "not find str2 in str, staring pos=0\n";
  else
    std::cout << "find str2 in str, staring pos=0, in pos:" << pos1 << "\n";
  
  auto pos2 = str.find(str2, 10);
  if (pos2 == std::string::npos)
    std::cout << "not find str2 in str, staring pos=10\n";
  else
    std::cout << "find str2 in str, staring pos=10, in pos:" << pos2 << "\n";
  
  std::cout << "\n";

  /**
   * variation2 :
   * size_type find( const CharT* s, size_type pos, size_type count ) const;
   * Finds the first substring equal to the range [s, s+count). This range may contain null characters.
  */
  auto pos3 = str.find("kf", 0, 2);
  if (pos3 == std::string::npos)
    std::cout << "not find char* in str, staring pos=0\n";
  else
    std::cout << "find char* in str, staring pos=0, in pos:" << pos3 << "\n";

  std::cout << "\n";

  /**
   * variation3 :
   * size_type find( const CharT* s, size_type pos = 0 ) const;
   * Finds the first substring equal to the character string pointed to by s. 
   * The length of the string is determined by the first null character using Traits::length(s).
  */
  auto pos4 = str.find("kdj", 0);
  if (pos4 == std::string::npos)
    std::cout << "not find char* in str, staring pos=0\n";
  else
    std::cout << "find char* in str, staring pos=0, in pos:" << pos4 << "\n";

  /**
   * variation4 :
   * size_type find( CharT ch, size_type pos = 0 ) const noexcept;
   * Finds the first character ch 
  */
  auto pos5 = str.find('e', 0);
  if (pos5 == std::string::npos)
    std::cout << "not find char in str, staring pos=0\n";
  else
    std::cout << "find char in str, staring pos=0, in pos:" << pos5 << "\n";

  /**
   * variation5 :
   * variation 5 is based on StringView, which is on C++17
  */

}