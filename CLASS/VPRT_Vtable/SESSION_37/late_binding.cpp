#include <iostream> 
#include <cstdlib> 

class ITestClass 
{
    public: 
        virtual void f() = 0; 
}; 

class CImpl_1 : public ITestClass
{
    public: 
        void f()
        {
            std::cout << "In CImpl_1" << std::endl; 
        }
}; 

class CImpl_2 : public ITestClass
{
    public: 
        void f()
        {
            std::cout << "In CImpl_2" << std::endl; 
        }
}; 

class CImpl_3 : public ITestClass
{
    public: 
        void f()
        {
            std::cout << "In CImpl_3" << std::endl; 
        }
}; 

int main(void)
{
    ITestClass* p = 0; 

    switch(rand() % 3) 
    {
        case 0: 
            p = new CImpl_1; 
            break; 
        case 1: 
            p = new CImpl_2; 
            break; 
        case 2:
            p = new CImpl_3; 
            break;  
    }

    p->f(); 
    delete p; 
    p = 0; 

    return 0; 
}