// Template Specialization 

#include <deque> 
#include "stack1.hpp"

template <>
class Stack<std::string>{
    private: 
        std::deque<std::string> elems; 
    public: 
        void push(std::string const&); 
        void pop(); 
        std::string top() const; 
        bool empty() const; 
}; 

void Stack<std::string>::push(std::string const& new_str){
    elems.push_back(new_str); 
}

void Stack<std::string>::pop(){
    if(elems.empty())
        throw std::out_of_range("Stack<std::string>: empty"); 
    elems.pop_back(); 
}

std::string Stack<std::string>::top() const{
    if(elems.empty())
        throw std::out_of_range("Stack<std::string>: empty");
    return elems.back();
}

bool Stack<std::string>::empty() const{
    return elems.empty(); 
}