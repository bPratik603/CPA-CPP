#include <cstdio> 

class B{
    public: 
        // type(this) == B*
        void f(){
            puts("B::f()");             
        }
}; 

class D: public B{

};

int main(void){
    D objD; 

    objD.f();   //  B::f(&objD); 
                //  type(objD) == D 
                //  type(&objD) == D*
                //  parameter passing B* this = &objD; 
                //  type(LHS) == B*
                //  type(RHS) == D*

    B* pB = new D; 
}