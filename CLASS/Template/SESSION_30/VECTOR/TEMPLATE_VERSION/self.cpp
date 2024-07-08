#include <iostream>
#include <cstring>
#include "self.hpp"

int main(void)
{
    Vector<int> v;

    for(ssize_t i=0;i<100;i++)
       v.push_back(i);

       std::cout<<v<<std::endl;
    const char* s = "CoreCode Programming Acadmy";
   
     Vector<char> cvec;
    for(ssize_t i=0;i<strlen(s);i++)
      cvec.push_back(s[i]);

    std::cout<<cvec<<std::endl;

    return EXIT_SUCCESS;
}