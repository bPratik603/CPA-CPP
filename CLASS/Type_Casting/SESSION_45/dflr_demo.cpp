#include <cstdio> 

class B1{
public: 
        void f(){
            puts("B1::f()"); 
        }
};  

class B2{
public: 
        void f(){
            puts("B2::f()"); 
        }
}; 

class B3{
public: 
        void f(){
            puts("B3::f()"); 
        }
}; 

class B4{
public: 
        void f(){
            puts("B4::f()"); 
        }
}; 

class D1 : public B1, public B2{
public: 
        void f(){
            puts("D1::f()"); 
        }
}; 

class D2: public B4, public B3{
public: 
        void f1(){
            puts("D2::f()"); 
        }
}; 

class D : public D2, public D1{
    public: 
        void f1(){
            puts("D::f()"); 
        }
};

int main(void){
    D objD; 

    objD.f(); 

    return (0); 
}