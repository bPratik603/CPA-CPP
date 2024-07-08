#include <iostream> 

class Base{
    public: 
        virtual void f(){
            std::cout << "Base::f()" << std::endl;
        }
}; 

class Derived : public Base{
    public: 
        void f(){
            std::cout << "Derived::f()" << std::endl; 
        }
}; 

int main(void){
    Base* pB = new Derived; 
    Derived* pD = new Derived; 

    pB->f();    // Derived::f()  
    pD->f();    // Derived::f() 

    pB->Base::f();  // Base::f() 
    pD->Base::f();  // Base::f() 

    delete pB; 
    pB = 0; 

    delete pD; 
    pD = 0; 
}