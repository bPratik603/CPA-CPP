#include <iostream>
#include <cassert> 
#include "stack.hpp"

int main(void)
{
    stack* pStack = new stack;
    data_t data; 
    
    assert(pStack->empty() == true); 
    assert(pStack->pop(&data) == STACK_EMPTY); 
    assert(pStack->top(&data) == STACK_EMPTY); 
    
    for(data = 0; data < 8; ++data)
        assert(pStack->push(data * 100) == SUCCESS); 

    assert(pStack->top(&data) == SUCCESS);
    std::cout << "TOP DATA:" << data << std::endl; 

    assert(pStack->pop(&data) == SUCCESS);
    std::cout << "POPED DATA:" << data << std::endl; 

    if(!pStack->empty()) 
        std::cout << "Stack is not empty" << std::endl; 

    while(!pStack->empty())
    {
        assert(pStack->pop(&data) == SUCCESS);
        std::cout << "POPED DATA:" << data << std::endl;  
    }

    delete pStack; 
    pStack = 0; 

    return EXIT_SUCCESS; 
}