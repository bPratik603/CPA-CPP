#include <iostream> 

class B{
    public: 
        virtual void f(){
            std::cout << "In  B::f()" << std::endl; 
        }

        void level_0(void){
            std::cout << "In B::level_0()" << std::endl; 
        }
}; 

class B1 : public B{
    public: 
        void f(){
            std::cout << "In B1::f()" << std::endl; 
        }

        void level_1_1(){
            std::cout << "In B1::level_1_1()" << std::endl; 
        }
}; 

class B2 : public B{
    public: 
        void f(){
            std::cout << "In B2::f()" << std::endl; 
        }

        void level_1_2(){
            std::cout << "In B2::level_1_2()" << std::endl; 
        }
}; 

class D11 : public B1{
    public: 
        void f(){
            std::cout << "In D11::f()" << std::endl; 
        }

        void level_2_1(){
            std::cout << "In D11::level_2_1" << std::endl; 
        }
}; 

class D12 : public B1{
    public: 
        void f(){
            std::cout << "In D12::f()" << std::endl; 
        }

        void level_2_2(){
            std::cout << "In D11::level_2_2" << std::endl; 
        }
}; 

class D21 : public B2{
    public: 
        void f(){
            std::cout << "In D21::f()" << std::endl; 
        }

        void level_2_3(){
            std::cout << "In D21::level_2_3" << std::endl; 
        }
}; 

class D22 : public B2{
    public: 
        void f(){
            std::cout << "In D22::f()" << std::endl; 
        }

        void level_2_4(){
            std::cout << "In D21::level_2_4" << std::endl; 
        }
}; 

int main(void){
    D11 obj_D11; 

    B* pB = (&obj_D11); 

    // object D11 contains object B1 and object B1 contains object of B
    std::cout << "B* pB = &objD11:" << std::endl; 
    std::cout << "Accessing all member functions in class B from pB" << std::endl; 
    pB->B::f();     // By default pB->f() will invoke D11:f()
                    // overriding it using pB->B::f() 
    pB->level_0();  // Inheritor 
    

    std::cout << "Accessing all member functions in class B1 from pB" << std::endl; 
    (dynamic_cast<B1*>(pB))->B1::f(); 
    (dynamic_cast<B1*>(pB))->level_1_1();   // inheritor  

    std::cout << "Accessing all member functions in class D11 from pB" << std::endl; 
    pB->f(); // because f() is declared as virtual in class B, and address of object 
             // of type B in pB, the role of dynamic_cast<D11*>(pB) is fulfilled by 
             // the virtual keyword itself 
    (dynamic_cast<D11*>(pB))->level_2_1();   // inheritor  
    ////////////////////////////////////////////////////////////

    std::cout << "Accessing all member functions using &obj_D11:" << std::endl;
    std::cout << "All D11 member functions:" << std::endl; 
    (&obj_D11)->level_2_1();
    (&obj_D11)->f(); 

    std::cout << "All B1 member functions:" << std::endl; 
    (dynamic_cast<B1*>(&obj_D11))->level_1_1(); 
    (dynamic_cast<B1*>(&obj_D11))->B1::f();

    std::cout << "all B member functions:" << std::endl; 
    (dynamic_cast<B*>(&obj_D11))->level_0(); 
    (dynamic_cast<B*>(&obj_D11))->B::f();

    return 0; 
}