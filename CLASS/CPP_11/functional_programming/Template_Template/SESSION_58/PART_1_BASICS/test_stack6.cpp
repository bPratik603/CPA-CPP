#include <iostream> 
#include <cstdlib> 
#include <vector> 

#include "stack6.hpp"

int main(void){
    Stack<int> intStack; 
    Stack<float, std::vector<float, std::allocator<float>>> floatStack; 

    for(int data = 10; data <= 50; data += 10) 
        intStack.push(data); 

    for(float data = 1.1; data <= 15.5; data += 1.5)
        floatStack.push(data); 

    intStack = floatStack; 
    while(!intStack.empty()){
        std::cout << "intStack::top():" << intStack.top() << std::endl; 
        intStack.pop(); 
    }

    return (EXIT_SUCCESS); 
}