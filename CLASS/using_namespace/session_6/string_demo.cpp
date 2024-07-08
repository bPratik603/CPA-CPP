#include <iostream> 
#include <string> 
#include <cstdio>

int main(void){
    std::string s1; 
    std::string s2("Hello"); 
    std::string s3 = "World"; 
    std::string s4(s3); 

    std::cout   << "s1:" << s1 << std::endl 
                << "s2:" << s2 << std::endl
                << "s3:" << s3 << std::endl 
                << "s4:" << s4 << std::endl; 

    s1 = "New string 1"; 
    s2 = "New string 2"; 
    s3 = "New string 3"; 
    s4 = "New string 4"; 

    std::cout   << "s1:" << s1 << std::endl 
                << "s2:" << s2 << std::endl
                << "s3:" << s3 << std::endl 
                << "s4:" << s4 << std::endl; 

    // character by character access : through indexing 
    for(std::string::size_type i = 0; i != s4.size(); ++i)
        std::cout << "s4[" << i << "]:" << s4[i] << std::endl; 

    // char by char access using iterator 
    for(std::string::iterator iter = s4.begin(); 
        iter != s4.end(); 
        ++iter)
        std::cout << "*iter=" << *iter << std::endl; 

    // Fetching C style string 
    const char* str = s4.c_str(); 
    printf("str = %s\n", str); 

    return 0; 
}
