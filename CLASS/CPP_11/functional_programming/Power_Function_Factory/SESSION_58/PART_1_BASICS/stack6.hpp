#include <iostream> 
#include <deque> 

template <typename T, typename CONT=std::deque<T, std::allocator<T>>> 
class Stack{
    private: 
        CONT elems; 

    public: 
        void push(T new_element); 
        void pop(); 
        T top() const; 
        bool empty() const; 

        template <typename T2, typename CONT2 = std::deque<T2, std::allocator<T2>>> 
        Stack<T, CONT>& operator=(const Stack<T2, CONT2>& other); 
}; 

template <typename T, typename CONT>
void Stack<T, CONT>::push(T new_elements){
    elems.push_back(new_elements); 
}

template <typename T, typename CONT> 
void Stack<T, CONT>::pop() {
    if(elems.empty())
        throw std::out_of_range("Stack<T>::pop() -> cannot pop from empty stack"); 
    elems.pop_back(); 
}

template <typename T, typename CONT> 
T Stack<T, CONT>::top() const {
    if(elems.empty())
        throw std::out_of_range("Stack<T>::pop() -> cannot top from empty stack");     
    return elems.back(); 
}

template <typename T, typename CONT> 
bool Stack<T, CONT>::empty() const{
    return elems.empty(); 
}

template <typename T, typename CONT> 
template <typename T2, typename CONT2> 
Stack<T, CONT>& Stack<T, CONT>::operator=(const Stack<T2, CONT2>& other){
    if(reinterpret_cast<void*>(this) == reinterpret_cast<void*>(const_cast<Stack<T2, CONT2>*>(&other)))
        return *this; 
    
    Stack<T2, CONT2> tmp(other);
    elems.clear(); 
    while(!tmp.empty()){
        elems.push_back(tmp.top()); 
        tmp.pop(); 
    }

    return *this; 
} 