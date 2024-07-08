#include <iostream> 
#include <vector> 
#include <deque>
#include <typeinfo>

template <typename T> 
class Stack{
    private: 
        std::deque<T> elems; 

    public: 

    template <typename T2> 
    Stack<T>& operator=(const Stack<T2>& other); 
    
}; 

template <typename T> 
template <typename T2> 
Stack<T>& Stack<T>::operator=(const Stack<T2>& other){
    std::cout   << "type(*this):"
                << typeid(*this).name() 
                << std::endl; 
    std::cout   << "type(other):"
                << typeid(other).name() 
                << std::endl; 
    return *this; 
}