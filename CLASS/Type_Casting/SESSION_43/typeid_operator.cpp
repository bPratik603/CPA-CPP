#include <iostream> 
#include <cstdlib> 
#include <typeinfo> 

char c; 
unsigned short us; 
int n; 
unsigned long int uln; 
long long int lln; 
float f; 
double d; 

int Arr[10]; 
int* p; 
int** pp; 

struct A{
    int a; char b; float c; 
}; 

struct A inA; 
struct A* pA; 
struct A A_arr[5]; 

class B{
    private: 
        int n; 
    public: 
        B() : n (0) {} 
        int getn() const { return n; }
        void setn(int new_n) { n = new_n; }
      
        virtual ~B(){

        }
}; 

B objB; 
B* pB; 

class D : public B {
    public: 
        D() : B() {} 
        void test() { std::cout << "in D::test" << std::endl; }
         
}; 

int main(void){
    std::cout << "typeid(c):" << typeid(c).name() << std::endl; 
    std::cout << "typeid(us):" << typeid(us).name() << std::endl; 
    std::cout << "typeid(n):" << typeid(n).name() << std::endl; 
    std::cout << "typeid(uln):" << typeid(uln).name() << std::endl; 
    std::cout << "typeid(lln):" << typeid(lln).name() << std::endl; 
    std::cout << "typeid(f):" << typeid(f).name() << std::endl; 
    std::cout << "typeid(d):" << typeid(d).name() << std::endl; 

    std::cout << "typeid(Arr):" << typeid(Arr).name() << std::endl; 
    std::cout << "typeid(p):" << typeid(p).name() << std::endl; 
    std::cout << "typeid(pp):" << typeid(pp).name() << std::endl; 
    std::cout << "typeid(inA):" << typeid(inA).name() << std::endl; 
    std::cout << "typeid(pA):" << typeid(pA).name() << std::endl; 
    std::cout << "typeid(A_arr):" << typeid(A_arr).name() << std::endl; 
    
    std::cout << "typeid(objB):" << typeid(objB).name() << std::endl; 
    std::cout << "typeid(pB):" << typeid(pB).name() << std::endl;

    B* pB1 = new B; 
    B* pB2 = new D; 

    std::cout << "typeid(*pB1):" << typeid(*pB1).name() << std::endl; // class B
    std::cout << "typeid(*PB2):" << typeid(*pB2).name() << std::endl; // class D
    
    delete pB1; 
    pB1 = 0; 

    delete pB2; 
    pB2 = 0; 

    return 0; 
}