#include <stdio.h> 
#include <stdlib.h> 

#define OFFSET_OF(T, mem) ((unsigned long long int)(&(((T*)0)->mem)))
#define CONTAINER_OF(addr, T, mem) ((T*)((unsigned long long int)(addr) - OFFSET_OF(T, mem)))

void func(float*); 

struct A 
{
    int a; 
    char b; 
    float c; 
}; 

int main(void)
{  
    struct A inA1 = {10, 'a', 1.1}; 
    struct A inA2 = {20, 'b', 2.2}; 
    struct A inA3 = {30, 'c', 3.3}; 

    func(&inA1.c); 
    func(&inA2.c); 
    func(&inA3.c); 

    return (0); 
}

void func(float* pf)
{
    /* 
    Precondition: 
        pf contains address of member 'c' of some 
        instance of struct A
    Post condition: 
        access to every element of instance of 
        struct A whose 'c' member address is in pf. 
    */
    struct A* pA = NULL; 

    pA = (struct A*)((unsigned long long int)pf - OFFSET_OF(struct A, c)); 

    printf(
            "pA->a = %d, pA->b = %c, pA->c = %.1f\n", 
            pA->a, pA->b, pA->c
        ); 

    pA = NULL; 
    if(pA == NULL)
        puts("pA is NULL"); 
        
    puts("pA is being set to the output of CONTAINER_OF"); 
    pA = CONTAINER_OF(pf, struct A, c); 

    printf(
        "pA->a = %d, pA->b = %c, pA->c = %.1f\n", 
        pA->a, pA->b, pA->c
    ); 
}

/* 
    lhs = rhs; (type mismatch)

    int n; 

    n = 'Z'; 
    n = (int)'A';

    'A' -> 0x41 
    (int)'A' -> 0x00000041

    int n = 0x0a0b0c0d; 
    unsigned char uc;

    uc = n; 

    uc = (unsigned char)n;  

    printf("%hhu");

    ((float)n2) / n1; 

    div 
    idiv 

    / 
        -> signed int -> idiv (idivb, idivw, idivl, idivq)
        -> unsigned int -> div (div, divw, divl divq)
        -> float -> fdivs 
        -> double fdivl 

    drived_object.inherited_member()

    Base* ptr = new Derived; 
    


*/