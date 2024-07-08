#include <iostream> 

class A 
{
    private: 
        int m, n; 
    public: 
        A() : m(100), n(200){} 
        void show() const 
        {
            std::cout   << "m:" << m 
                        << "\tn:" << n 
                        << std::endl; 
        }

        class B
        {
            private: 
                double d1;
                double d2; 
            public: 
                B() : d1(10.10), d2(20.20) 
                {

                }

                void show() const 
                {
                    std::cout << "d1:" << d1 
                              << "\td2:" << d2 
                              << std::endl; 
                }
        };  
};  

int main(void)
{
    std::cout << "sizeof(A):" << sizeof(A) << std::endl; 
    std::cout << "sizeof(B):" << sizeof(A::B) << std::endl; 

    A objA; 
    A::B objB; 

    objA.show(); 
    objB.show(); 

    std::cout << "sizeof(objA):" << sizeof(objA) << std::endl; 
    std::cout << "sizeof(objB):" << sizeof(objB) << std::endl; 

    return 0; 
}