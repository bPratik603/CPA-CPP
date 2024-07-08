#include <iostream> 
#include <cstdlib> 

class A{
    private: 
        int m, n, k; 
    public: 
        A() : m(0), n(0), k(0) {} 

        void f(){
            std::cout << "In A::f()" << std::endl; 
        }

        void show(){
            std::cout   << "m:" << std::hex << m << std::endl 
                        << "n:" << std::hex << n << std::endl 
                        << "k:" << std::hex << k << std::endl; 
        }
}; 

class B{
    private: 
        float x; 
        short y, z; 
        float w; 
    public: 
        void g(){
            std::cout << "In B::g()" << std::endl; 
            y = 0xff; 
        }
}; 

int main(void){
    A objA;

    // (&objA)->g();   // type(lhs_of(->)) == A* // class A does not have a member g() 
    objA.show(); 
    (reinterpret_cast<B*>(&objA))->g(); 
    objA.show(); 

    return (0); 
}

