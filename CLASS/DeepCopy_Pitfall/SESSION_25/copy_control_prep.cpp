#include <iostream> 

class X 
{
    public: 
        X(); 
        X(int, int); 

       
}; 

int main(void)
{
    X objX;             //  default. X::X()
    X objX1(100, 200);  //  parameterized: X::X(int, int)
    X objX2(objX1);     //  X::X(X objX) {}
                        //  X::X(X& refobjX) {}
                        //  X::X(const X& refobjX) {} 

    // X objX3(100, 200, 1.1, 4.5);    // CTE 
                                    // X::X(int, int, double, double)

    X* pX = new X(objX1); 

    delete pX; 
    pX = 0; 

    return 0; 
}

/* 

X(const X& other)
{
    // memcpy(
    //      (void*)this,
    //      (const void*)&other, 
    //       sizeof(X) 
    // ); 
    this->mem1 = other.mem1; 

    this->memn = other.memn; 
}

X* pX = new X; 

X objX = *pX; 


class X 
{
    public: 
        X(); 
        X(int, int, int); 

        X(const X&)
        {
            
        }
};       
*/