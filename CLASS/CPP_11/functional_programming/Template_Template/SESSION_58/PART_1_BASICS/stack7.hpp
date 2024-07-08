#pragma once 

#include <iostream> 
#include <stdexcept>

template <typename T, template <typename C, typename Allocator = std::allocator<C>> class CONT_TYPE> 
class Stack{
    private: 
        CONT_TYPE<T> container; 
    public: 
        void push(T const& elem); 
        T top(); 
        void pop(); 
        bool empty() const; 
}; 

template <typename T, template <typename T, typename Allocator> class CONT_TYPE> 
void Stack<T, CONT_TYPE> ::push(T const& element){
    container.push_back(element); 
}

template <typename T, template <typename T, typename Allocator> class CONT_TYPE> 
void Stack<T, CONT_TYPE>::pop(){
    if(empty())
        throw std::runtime_error("Cannot pop() from empty stack"); 
    return container.pop_back(); 
}

template <typename T, template <typename T, typename Allocator> class CONT_TYPE> 
T Stack<T, CONT_TYPE>::top(){
     if(empty())
        throw std::runtime_error("Cannot top() from empty stack"); 
    return container.back(); 
}

template <typename T, template <typename T, typename Allocator> class CONT_TYPE> 
bool Stack<T, CONT_TYPE>::empty() const{
    return container.empty();
}