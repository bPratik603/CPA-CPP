#include <iostream> 

class B{
    public: 
        void f1(){
            std::cout << "B::f1()" << std::endl; 
        }

        virtual void f2(){
            std::cout << "B::f2()" << std::endl; 
        }

        void f3(){
            std::cout << "B::f3()" << std::endl; 
        }

        void f4(){
            std::cout << "B::f4()" << std::endl; 
        }
};

class D : public B{
    public: 
        void f2(){
            // replacer 
            std::cout << "D::f2()" << std::endl; 
        }

        void f3(){
            B::f3(); 
            std::cout << "D::f3()" << std::endl; 
        }

        void g1(){
            std::cout << "D::g1()" << std::endl; 
        }

        void g2(){
            std::cout << "D::g2()" << std::endl; 
        }
}; 

// fB = {f1, f2, f3, f4}
// fD = {f2, f3, g1, g2}
// fB U fD = {f1, f2, f3, f4, g1, g2}
// fB-fD = {f1, f4} (INHERITORS)
// fD-fB = {g1, g2} (DERIVED SPECIFIC MEMBERS )
// fB intersection fD = {f2, f3} (OVERRIDDEN MEMBERS )
// D has replaced f2 in B 
// D has extended f3 in B 

int main(void){
    B* pB = new B; 
    D* pD = new D; 
    B* pB1 = new D; 

    pB->f1();   // B::f1() 
    pB->f2();   // B::f2() 
    pB->f3();   // B::f3() 
    pB->f4();   // B::f4()   

    pD->f1();   //  B::f1() [fB-fD]
    pD->f2();   //  D::f2() 
    pD->f3();   //  D::f3()
    pD->f4();   //  B::f4() [fB-fD]
    pD->g1();   //  D::g1() [fD-fB]
    pD->g2();   //  D::g2()  [fD-fB]

    pB1->f1(); 
    pB1->f2(); 
    pB1->f3(); 
    pB1->f4(); 
    // pB1->g1(); // CTE 
    // pB1->g2(); // CTE 
    delete pB; 
    pB = 0; 

    delete pD; 
    pD = 0; 

    delete pB1; 
    pB1 = 0; 

    return (0);  
}
