// Default template arguments 

#include <vector> 
#include <stdexcept> 

template <typename T, typename CONT = std::vector<T>> 
class Stack{
    private: 
        CONT elems;     
    public: 
        void push(T const&); 
        void pop(); 
        T top() const; 
        bool empty() const; 
}; 

template <typename T, typename CONT> 
void Stack<T, CONT>::push(T const& element){
    elems.push_back(element); 
}

template <typename T, typename CONT> 
void Stack<T, CONT>::pop(){
    if(elems.empty())
        throw std::out_of_range("Stack<T,CONT>::pop : Stack empty"); 
    elems.pop_back();
}

template <typename T, typename CONT> 
T Stack<T, CONT>::top() const {
    if(elems.empty())
        throw std::out_of_range("Stack<T,CONT>::pop : Stack empty"); 
    return elems.back(); 
}

template <typename T, typename CONT> 
bool Stack<T, CONT>::empty() const {
    return elems.empty(); 
}
