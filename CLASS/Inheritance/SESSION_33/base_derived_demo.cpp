#include <cstdio> 

class A{
    public: 
        void f1(){
            puts("In A::f1()"); 
        }

        void f2(){
            puts("A::f2()"); 
        }

        void f3(){
            puts("A::f3()"); 
        }
}; 

class C : public A{
    public: 
        void g1(){
            puts("C::g1()"); 
        }

        void g2(){
            puts("C::g2()"); 
        }
}; 

int main(void){
    C objC; 

    objC.f1(); 
    objC.f2(); 
    objC.f3(); 
    objC.g1(); 
    objC.g2(); 

    return 0; 
}

/* 
class C: public A
{

}; 

class C: protected A 
{

}; 

class C: A
{

}; 

class C : private A{

}; 
*/