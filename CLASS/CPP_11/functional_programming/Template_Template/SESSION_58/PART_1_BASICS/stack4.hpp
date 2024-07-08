// Nontype class template parameter 

#include <stdexcept> 

template <typename T, int MAXSIZE> 
class Stack{
    private: 
        T elems[MAXSIZE]; 
        int current_number_of_elements; 

    public: 
        Stack();    // constructor 
        void push(T const& new_element); 
        void pop(); 
        T top() const; 
        bool empty() const; 
        bool full() const; 
}; 

template <typename T, int MAXSIZE> 
Stack<T,MAXSIZE>::Stack() : current_number_of_elements(0){

}

template <typename T, int MAXSIZE> 
void Stack<T,MAXSIZE>::push(T const& new_element){
    if(current_number_of_elements == MAXSIZE)
        throw std::out_of_range("Stack<T,MAXSIZE>::push() : Exception"); 

    elems[current_number_of_elements] = new_element; 
    ++current_number_of_elements; 
}

template <typename T, int MAXSIZE> 
void Stack<T,MAXSIZE>::pop(){
    if(current_number_of_elements == 0)
        throw std::out_of_range("Stack<T,MAXSIZE>::pop() : Stack is empty");
    --current_number_of_elements; 
}

template <typename T, int MAXSIZE> 
T Stack<T,MAXSIZE>::top() const {
    if(current_number_of_elements == 0)
        throw std::out_of_range("Stack<T,MAXSIZE>::top() : Stack is empty");
    return elems[current_number_of_elements-1]; 
}

template <typename T, int MAXSIZE> 
bool Stack<T,MAXSIZE>::empty() const {
    return (current_number_of_elements == 0); 
}

template <typename T, int MAXSIZE> 
bool Stack<T,MAXSIZE>::full() const {   
    return (current_number_of_elements == MAXSIZE); 
}