#include <iostream> 
#include <string> 

int main(void){
    std::string s1; 
    std::string s2("Hello"); 
    std::string s3 = "Hello"; 
    std::string s4(s3); 

    std::string::size_type len_s2; 
    len_s2 = s2.size();

    for(
        std::string::size_type i = 0; 
        i != s2.size(); 
        ++i
    )
        std::cout   << "s2[" 
                    << i 
                    << "]:" 
                    << s2[i] 
                    << std::endl;
    
    for(
        std::string::iterator iter = s2.begin(); 
        iter != s2.end(); 
        ++iter
    )
        std::cout << "*iter = " << *iter << std::endl; 
    
    const char* p_str = s2.c_str(); 

    return 0; 
}