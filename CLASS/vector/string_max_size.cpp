#include <iostream> 
#include <string> 

int main(void){
    std::string s("Hello"); 

    std::cout << "s.size():" << s.size() << std::endl; 
    std::cout << "s.max_size():" << s.max_size() << std::endl; 
    return 0; 
}