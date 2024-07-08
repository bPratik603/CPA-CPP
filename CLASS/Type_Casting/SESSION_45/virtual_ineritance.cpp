#include <iostream> 

class B{
    public: 
        B(){
            std::cout << "In B::B()" << std::endl; 
        }

        void f(){
            std::cout << "In B::f()" << std::endl; 
        }
}; 

class D1 : virtual public B{

}; 

class D2: virtual public B{

}; 

class D : public D1, D2{

}; 

int main(void){
    D objD;
    objD.f(); 
    return (0); 
}

