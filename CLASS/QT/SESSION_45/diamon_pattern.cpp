#include <iostream> 

// Diamond pattern and associated problems 

class B{
    public: 
        B(){
            std::cout << "this:" << std::hex << this << std::endl; 
            std::cout << "In B::B()" << std::endl; 
        }

        void f(){
            std::cout << "In B::f()" << std::endl;  
        }
}; 

class D1 : public B{

}; 

class D2: public B{

}; 

class D : public D1, D2{

}; 

int main(void){
    D objD; 
    objD.f(); 
    
    return (0); 
}



