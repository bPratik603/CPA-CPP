#include <iostream> 
#include <string> 
#include <cstdlib> 

#include "stack2.hpp"

int main(void){
    try{
        Stack<int> intStack; 
        Stack<std::string> stringStack; 
        intStack.push(7);
        std::cout << intStack.top() << std::endl; 

        stringStack.push("Hello"); 
        std::cout << stringStack.top() << std::endl; 
        stringStack.pop(); 
        stringStack.pop(); 
    }catch(std::exception const& e){
        std::cerr << "exception:" << e.what() << std::endl; 
        return EXIT_FAILURE; 
    }

    return EXIT_SUCCESS; 
}