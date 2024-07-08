#include <iostream> 

class B{
    public: 
        void f(){
            std::cout << "B::f()" << std::endl; 
        }
}; 

class D : public B{
    public: 
        void f(){
            std::cout << "D::f()" << std::endl; 
        }
}; 

int main(void){
    B* pB1 = new B;     // scenario 1: Base ptr, Base object 
    D* pD1 = new D;     // scenario 2: Derived ptr, Derived object 
    B* pB2 = new D;     // scenario 3: Base Ptr, Derived object, call to overridden method 
                        // but overridden method is not virtual in Base 

    pB1->f();   // B::f() 
    pD1->f();   // D::f() 
    pB2->f();   // B::f() 

    delete pB1; 
    pB1 = 0; 

    delete pD1; 
    pD1 = 0; 

    delete pB2; 
    pB2 = 0; 

    return (0); 
}