// Class template 

#include <vector> 
#include <stdexcept> 

template <typename T> 
class Stack{
    private: 
        std::vector<T> elems; 

    public: 
        void push(T const&); 
        void pop(); 
        T top () const; 
        bool empty() const; 
}; 

template <typename T> 
void Stack<T>::push(T const& element){
    elems.push_back(element); 
}

template <typename T> 
void Stack<T>::pop(){
    if(elems.empty())
        throw std::out_of_range("Stack<>::pop() : empty");
    elems.pop_back();          
}

template <typename T> 
T Stack<T>::top() const {
    if(elems.empty())
        throw std::out_of_range("Stack<>:top() : empty"); 
    return elems.back(); 
}

template <typename T> 
bool Stack<T>::empty() const {
    return elems.empty(); 
}