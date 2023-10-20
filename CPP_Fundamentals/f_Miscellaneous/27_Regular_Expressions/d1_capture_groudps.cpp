#include <regex>
 
#include <iomanip>
#include <iostream>
#include <string>
 
void showCaptureGroups(const std::string& regEx, const std::string& text){
 
  // regular expression holder
  std::regex rgx(regEx);
 
  // result holder
  std::smatch smatch;
 
  // result evaluation
  if (std::regex_search(text, smatch, rgx)){
    std::cout << std::setw(10) << regEx << std::setw(30) << text << std::setw(30) << smatch[0]  << std::setw(25) << smatch[1] << std::setw(28) << smatch[2] << std::setw(36) << smatch[3] << std::setw(30) << smatch[4] << std::endl;
  }
 
}
 
int main(){
 
  std::cout << std::endl;
 
  std::cout << std::setw(10) << "reg Expr" << std::setw(30) << "text" << std::setw(30) << "smatch[0]" << std::setw(30) << "smatch[1]" << std::setw(30) << "smatch[2]" << std::setw(30) << "smatch[3]" << std::setw(30) << "smatch[4]" << std::endl;
 
  showCaptureGroups("abc+", "abccccc");
 
  showCaptureGroups("(a+)(b+)(c+)", "aaabccc");
 
  showCaptureGroups("((a+)(b+)(c+))", "aaabccc");
 
  showCaptureGroups("(ab)(abc)+", "ababcabc");
 
  std::cout << std::endl;
   
}