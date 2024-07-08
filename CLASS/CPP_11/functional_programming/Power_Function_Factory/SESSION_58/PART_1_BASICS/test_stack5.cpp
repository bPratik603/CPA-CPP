#include <iostream> 
#include <string> 
#include "stack5.hpp"

int main(void){
    Stack<int> intStack; 
    Stack<float> floatStack; 
    Stack<std::string> stringStack; 

    for(int data = 1; data <= 3; ++data)
        intStack.push(data * 10); 

    for(float data = 1.1; data < 4.4; data += 1.0)
        floatStack.push(data); 

    intStack = floatStack; 
    std::cout << "Showing intStack after assigning it to floatStack" << std::endl; 
    while(!intStack.empty()){
        std::cout << intStack.top() << std::endl; 
        intStack.pop(); 
    }

    //floatStack = stringStack; // Type mismatch 

    return 0; 
}