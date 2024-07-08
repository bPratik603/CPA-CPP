#include <iostream> 

class Base{
    public: 
        Base(){
            std::cout << "In Base CC" << std::endl; 
        }
}; 

class Derived : public Base{
    public: 
        Derived(){
            std::cout << "In Derived CC" << std::endl; 
        }
};

class B{

}; 

class D{

}; 

int main(void){
    B* pB1 = new B;     // ok 
    B* pB2 = new D;     // error 

    Base* pBase1 = new Base;    // ok 
    Base* pBase2 = new Derived; // ok 

    delete pB1; 
    pB1 = 0; 

    delete pB2; 
    pB2 = 0; 

    delete pBase1; 
    pBase1 = 0; 

    delete pBase2; 
    pBase2 = 0; 

    return (0); 
}

class B{
    public: 
        void f(){

        }
}; 

class D : public B{
    public: 
};

int main(void){
    D objD; 

    objD.f(); // B::f(&objD); // D* -> B* 

    B* pB = new D; 
    
}