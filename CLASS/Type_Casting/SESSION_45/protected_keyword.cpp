#include <cstdio> 

class B{
    private: 
        int m; 
    protected: 
        int n; 
    public: 
        int k; 
}; 

class D1 : public B{
    public: 
        void test_func(){
            printf("this->k=%d, this->n=%d\n", 
                    this->k, this->n); 
        }
}; 

class D11 : public D1{
    public: 
        void func(){
            this->k; 
            this->n; 
        }
}; 

class D2 : protected B{
    public: 
    void test_func(){
        B objB; 
        printf("this->k=%d, this->n=%d\n", 
                    this->k, this->n); 
    }
}; 

class D22 : public D2{
    public: 
        void func(){
            this->n; 
            this->k; 
        }
}; 

class D3 : private B{
    public: 
    void test_func(){
            printf("this->k=%d, this->n=%d\n", 
                    this->k, this->n); 
        }
}; 

class D33 : public D3{
    public: 
        void func(){
            this->k; 
        }
}; 

int main(void){
    B objB; 

    printf("main():objB.k:%d\n", objB.k); 
    // objB.n, objB.m are not accessible 
    // because a function which is not a member 
    // function or a member function of derived class 
    // does not have an access to protected or private members 

    D1 objD1; 
    D2 objD2; 
    D3 objD3; 

    objD1.test_func(); 
    objD2.test_func(); 
    objD3.test_func(); 

    objD1.k; 
    objD2.k; // objD2->B instance -> PUBLIC  
    objD3.k; 
}