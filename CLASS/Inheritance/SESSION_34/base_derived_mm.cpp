#include <cstdio> 
#include <cstdlib> 

class B{
    private: 
        int n1; 
        int n2; 
        short s[8]; 
}; 

class D1 : public B{
    private: 
        double d1; 
        double d2; 
}; 

class D2{
    private: 
        double d1; 
        double d2; 
}; 

int main(void){
    printf("sizeof(B) = %llu\n", sizeof(B)); 
    printf("sizeof(D1) = %llu\n", sizeof(D1)); 
    printf("sizeof(D2) = %llu\n", sizeof(D2)); 
    return EXIT_SUCCESS; 
}