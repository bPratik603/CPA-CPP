#include <cstdio> 
typedef unsigned long long addr_t; 

class B{
   public:
        int m, n; 
}; 

class D1: virtual public B{
    public: 
        float a, b, c, d; 
}; 

class D2: virtual public B{
    public:
        double d1, d2, d3; 
}; 

class D : public D1, public D2{
    public: 
        char c; 
}; 

int main(void){
    D objD; 

    printf("&objD=%llu\n", (addr_t)&objD); 
    printf("&objD.m=%llu\n", (addr_t)&objD.m); 
    printf("&objD.a=%llu\n", (addr_t)&objD.a); 
    printf("&objD.d1=%llu\n", (addr_t)&objD.d1); 
    printf("&objD.c=%llu\n", (addr_t)&objD.c); 
   

    return 0; 
    
}