#include <iostream> 
#include <vector> 
#include <deque> 

#include "stack7.hpp" 

int main(void){
    Stack<int, std::vector> iStack1; 
    Stack<float, std::deque> iStack2; 
   
    for(int data = 10; data <= 50; data += 8)
        iStack1.push(data); 

    std::cout << "TOP ELEM:" << iStack1.top() << std::endl; 

    int element; 
    while(!iStack1.empty()){
        element = iStack1.top(); 
        iStack1.pop(); 
        std::cout << "POPED ELEMENT:" << element << std::endl; 
    }

    try{
        iStack1.pop(); 
    }catch(std::exception& e){
        std::cerr << "Exception:" << e.what() << std::endl; 
        return EXIT_FAILURE; 
    }

    return EXIT_SUCCESS; 
}


