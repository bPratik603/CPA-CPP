#include <iostream> 
#include <stdexcept>
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
}; 

template <typename T> 
void Stack<T>::push(T const& element){
    elems.push(element); 
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

int main(void){
    Stack<int> intStack; 
    Stack<float> floatStack; 

    intStack.push(10); 
    intStack.push(20); 

    floatStack.push(1.1); 
    floatStack.push(2.2); 
    floatStack.push(3.3); 

    // intStack = floatStack;  // Compile Time Error 

    // Stack<int>& operator=(const Stack<float>& other); 
    // is not supported.  
    return 0; 
} 