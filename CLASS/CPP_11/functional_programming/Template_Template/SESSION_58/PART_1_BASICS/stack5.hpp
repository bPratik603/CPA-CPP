#include <deque> 

template <typename T> 
class Stack{
    private: 
        std::deque<T> elems; 
    public: 
        void push(T const& element); 
        void pop(); 
        T top() const; 
        bool empty() const; 

        template <typename T2> 
        Stack<T>& operator=(const Stack<T2>& other); 
}; 

template <typename T> 
void Stack<T>::push(T const& element){
    elems.push_back(element); 
}

template <typename T> 
void Stack<T>::pop(){
    if(elems.empty())
        throw std::out_of_range("Stack<T>::pop() -> Cannot pop from empty stack"); 
    elems.pop_back(); 
}

template <typename T> 
T Stack<T>::top() const {
    if(elems.empty())
        throw std::out_of_range("Stack<T>::pop() -> Cannot top from empty stack"); 
    return elems.back(); 
}

template <typename T> 
bool Stack<T>::empty() const {
    return elems.empty(); 
}

template <typename T> 
template <typename T2> 
Stack<T>& Stack<T>::operator=(const Stack<T2>& other){
    if(reinterpret_cast<void*>(this) == reinterpret_cast<void*>(const_cast<Stack<T2>*>(&other)))
        return *this; 

    Stack<T2> tmp(other); 
    elems.clear(); 
    while(!tmp.empty()){
        elems.push_front(tmp.top()); 
        tmp.pop(); 
    } 

    return *this; 
}
