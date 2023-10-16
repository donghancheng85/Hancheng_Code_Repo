#include <iostream>
#include <string.h>

const char* min(const char* s, const char* t){ 
  return (strcmp(s,t) < 0) ? s : t;
}
float min(float x, float y){
    return (x < y) ? x : y;
}

int main() {
  const char* s = min("abc", "xyz");
  float f = min(4.45F, 1.23f);
  int f2 = min(2011, 2014);
  // float f3 = min("abc", 1.23f);

  std::cout << s << std::endl;
  std::cout << f << std::endl;
  std::cout << f2 << std::endl;
}