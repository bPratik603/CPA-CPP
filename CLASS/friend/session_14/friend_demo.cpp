#include <iostream> 
#include <cstdlib> 

void some_func(void); 
void test_class_c1(void); 
void test_class_c2(void); 

class Test{
    private: 
        int a; 
        char b; 
        float c; 

    public: 
        friend void some_func(void);
        friend class C2; 
        Test() : a(100), b('Z'), c(3.14f){

        }
}; 

class C1{
    public: 
        void c1_func1(){
            Test t; 
            // std::cout << "t.a:" << t.a << std::endl;  // CTE 
            //std::cout << "t.b:" << t.b << std::endl;  // CTE
            //std::cout << "t.c:" << t.c << std::endl;  // CTE 
        }

        void c1_func2(){
            Test t; 
            //std::cout << "t.a:" << t.a << std::endl;  // CTE 
            //std::cout << "t.b:" << t.b << std::endl;  // CTE
            //std::cout << "t.c:" << t.c << std::endl;  // CTE
        }
}; 

class C2{
    public: 
        void c2_func1(){
            Test t; 
            std::cout << "t.a:" << t.a << std::endl;  // CTE 
            std::cout << "t.b:" << t.b << std::endl;  // CTE
            std::cout << "t.c:" << t.c << std::endl;  // CTE 
        }

        void c2_func2(){
            Test t; 
            std::cout << "t.a:" << t.a << std::endl;  // CTE 
            std::cout << "t.b:" << t.b << std::endl;  // CTE
            std::cout << "t.c:" << t.c << std::endl;  // CTE
        }
}; 

int main(void){
    Test t; 

    //std::cout << "t.a:" << t.a << std::endl;  // CTE 
    //std::cout << "t.b:" << t.b << std::endl;  // CTE
    //std::cout << "t.c:" << t.c << std::endl;  // CTE

    some_func(); 
    test_class_c1(); 
    test_class_c2(); 
    
    return (0); 
}

void some_func(void){
    Test* pTest = new Test; 
    std::cout << "Inside some_func():" << std::endl; 
    std::cout << "some_func:a:" << pTest->a << std::endl; 
    std::cout << "some_func:b:" << pTest->b << std::endl; 
    std::cout << "some_func:c:" << pTest->c << std::endl; 
    delete pTest; 
    pTest = 0; 
    std::cout << "-----------END some_func()-------------" << std::endl; 
}

void test_class_c1(void){
    std::cout << "Inside test_class_C1():" << std::endl; 
    C1 objC1; 

    objC1.c1_func1(); 
    objC1.c1_func2(); 

    std::cout << "------------END test_class_C1()--------" << std::endl; 
}

void test_class_c2(void){
    std::cout << "Inside test_class_C2():" << std::endl; 
    C2 objC2; 

    objC2.c2_func1(); 
    objC2.c2_func2();   

    std::cout << "------------END test_class_C2()--------" << std::endl; 
}