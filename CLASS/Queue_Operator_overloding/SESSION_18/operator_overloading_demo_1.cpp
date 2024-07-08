#include <iostream> 

class Test 
{
    public:

        Test operator+(const Test& second_object) const
        {
            std::cout << "----In Test::operator+()-----" << std::endl; 
            std::cout << "this:" << std::hex << this << std::endl; 
            std::cout << "&second_object:" << std::hex << &second_object << std::endl; 
            std::cout << "----Returning from Test::operator+()-----" << std::endl; 

            Test t = Test(); 
            return t; 
                   
        }

        bool operator*() 
        {
            std::cout << "--------In Test::operator*()--------" << std::endl; 
            std::cout << "this:" << std::hex << this << std::endl;
            std::cout << "--------Returning from Test::operator*()--------" << std::endl;  
            return true; 
        }

     
}; 

int main(void)
{
    Test t1, t2, result; 
    bool ret; 

    std::cout << "main:&t1:" << std::hex << &t1 << std::endl 
              << "main:&t2:" << std::hex << &t2 << std::endl;
    // address of &t1 in main() and address in this in operator+() 
    // should be identical 
    // address of &t2 in main() and address of &second_object in 
    // operator+() should be identical  

    result = t1 + t2;
    
    ret = *t1;

    return (0);   
}

//  t1 + t2 
//  t1.operator+(t2)
//  Test::operator+(&t1, t2)