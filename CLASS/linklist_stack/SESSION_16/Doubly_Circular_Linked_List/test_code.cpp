#include <iostream> 

class Test
{
    private: 
        void helper()
        {
            std::cout << "In helper function" << std::endl; 
            std::cout << "this:" << std::hex << this << std::endl; 
            std::cout << "Returning from helper_function()" << std::endl; 
        }

    public: 
        
        void member_function()
        {
            std::cout << "In member_function()" << std::endl; 
            std::cout << "this:" << std::hex << this << std::endl; 
            helper(); 
            std::cout << "Returned to member_function()" << std::endl; 
            std::cout << "Returning from member_function()" << std::endl; 
        }
}; 

int main(void)
{
    Test t; 

    std::cout << "main:&t:" << std::hex << &t << std::endl; 
    t.member_function(); 

    return EXIT_SUCCESS; 
}
