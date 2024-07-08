#include <iostream> 

class Base{
    public: 
        void f(){
            std::cout << "In Base::f()" << std::endl; 
        }
}; 

class Derived : public Base{
    public: 
        void f(){
            std::cout << "In Derived::f()" << std::endl; 
        }
}; 

int main(void){
    Derived objD; 
    Base* pB = &objD; 

    pB->f();    // will go to B::f()
                // despite the fac that pB stores an object of class Derived 
                // and derived class has an overridden version of f() 

    reinterpret_cast<Derived*>(pB)->f(); 
    return 0; 
}