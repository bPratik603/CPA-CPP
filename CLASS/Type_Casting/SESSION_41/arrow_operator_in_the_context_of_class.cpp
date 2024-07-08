#include <iostream> 

class A{
    public: 
        void f(){
            std::cout << "In A::f()" << std::endl; 
        }
}; 

class B{
    public: 
        void g(){
            std::cout << "In B::g()" << std::endl; 
        }
}; 

int main(void){
    A objA; 
    B objB; 
    // objA.g(); // compile time error 
    ((B*)&objA)->g(); 
    objB.g(); 
    return (0); 
}