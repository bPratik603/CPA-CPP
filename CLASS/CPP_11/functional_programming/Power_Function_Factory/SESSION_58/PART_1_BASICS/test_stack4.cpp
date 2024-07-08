#include <iostream> 
#include <cstdlib> 
#include "stack4.hpp"

int main(void){
    try{
        Stack<int, 5> intStack; 
        for(int i = 0; i < 5; ++i)
            intStack.push(i * 100);
        std::cout << "top:" << intStack.top() << std::endl; 
        while(!intStack.empty())
            intStack.pop(); 
        intStack.pop(); 
    }catch(std::exception const& ex){
        std::cout << "Exception:" << ex.what() << std::endl; 
        return EXIT_FAILURE; 
    }
    return EXIT_SUCCESS; 
}
