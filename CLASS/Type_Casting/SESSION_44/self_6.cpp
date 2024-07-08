#include <iostream>

class Base{
    public:
    void f(){
        std::cout<<"In Base::f()"<<std::endl;
    }
};

class Derived : public Base{
    public:
      void f(){
        std::cout<<"In Derived::f()"<<std::endl;
      }
};

int main(void){
    Derived objD;
    Base* pB = &objD;

    pB->f();

    reinterpret_cast<Derived*>(pB)->f();
    return 0;
}