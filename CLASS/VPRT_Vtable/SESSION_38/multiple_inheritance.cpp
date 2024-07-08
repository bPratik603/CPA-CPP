#include <iostream> 

class IX{
    public: 
        virtual void f1() = 0; 
        virtual void f2() = 0; 
}; 

class IY{
    public: 
        virtual void g1() = 0; 
        virtual void g2() = 0; 
}; 

class IZ{
    public: 
        virtual void h1() = 0; 
        virtual void h2() = 0; 
}; 

class C: public IX, public IY, public IZ{
    private: 
        int n1; 
        int n2; 
        double d1; 

    public: 
        void f1(){
            std::cout << "C::f1()" << std::endl;          
        }

        void f2(){
            std::cout << "C::f2()" << std::endl;  
        }

        void g1(){
            std::cout << "C::g1()" << std::endl;          
        }

        void g2(){
            std::cout << "C::g2()" << std::endl;  
        }

        void h1(){
            std::cout << "C::h1()" << std::endl;          
        }

        void h2(){
            std::cout << "C::h2()" << std::endl;  
        }
}; 

int main(void){
    C* pC = new C; 

    IX* pX = pC; 
    IY* pY = pC; 
    IZ* pZ = pC; 

    pX->f1(); 
    pX->f2(); 

    pY->g1(); 
    pY->g2(); 

    pZ->h1(); 
    pZ->h2(); 

    dynamic_cast<IY*>(dynamic_cast<C*>(pX))->g1(); 
    dynamic_cast<IZ*>(dynamic_cast<C*>(pY))->h2(); 

    delete pC; 
    pC = 0; 

    return 0; 
}

/* 

class IUnknown{
    virtual HRESULT STDCALL QueryInterface(IID, void** ppI) = 0; 
}; 


pX->QueryInterface(IID_IY, reinterpret_cast<void**>(&pY)); 

*/