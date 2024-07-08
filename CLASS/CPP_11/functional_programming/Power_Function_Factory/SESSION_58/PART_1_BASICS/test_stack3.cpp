#include <iostream>
#include <deque> 

#include "stack3.hpp"

int main(void){
    try{
        Stack<int> intStack1; 
        Stack<int, std::deque<int>> intStack2; 

        intStack1.push(7); 
        intStack2.push(7); 

        std::cout << "intStack1.top():" << intStack1.top() << std::endl; 
        std::cout << "intStack2.top():" << intStack2.top() << std::endl; 

        intStack1.pop(); 
        intStack2.pop(); 
        intStack2.pop();
    }catch(std::exception const& ex){
        std::cerr << "Exception:" << ex.what() << std::endl; 
        return EXIT_FAILURE; 
    }

    return EXIT_FAILURE; 
}