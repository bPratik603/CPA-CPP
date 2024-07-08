#include <stdio.h> 
#include <stdlib.h> 

struct A{
    unsigned int a; 
    unsigned int b; 
    unsigned long long int arr[3]; 
    unsigned int c;
} inA = {
        0xffffffff, 
        0xffffffff, 
        {
            0xa0b0c0d011223344, 
            0x55667788aabbccdd, 
            0x123456789abcdef0
        }, 
        0xffffffff
    }; 

struct B{
    int u; 
    int v; 
    int w; 
    int y; 
}; 

void showA(struct A* pA, const char* msg); 

int main(void)
{
    showA(&inA, "Before casting:");
    ((struct B*)&inA)->y = 0x00000000; 
    showA(&inA, "After Casting:"); 

    return (0); 
}


void showA(struct A* pA, const char* msg){
    int i; 

    printf("pA->a = %x\n", pA->a); 
     printf("pA->b = %x\n", pA->b); 
    for(i = 0; i < 3; ++i)
        printf("pA->arr[%d]:%llx\n", i, pA->arr[i]); 
    printf("pA->c = %x\n", pA->c); 
}

/* 
    struct A {
        int x; 
        char y; 
        float z; 
    }; 

    struct A inA; 

    inA.x 
    inA.y 
    inA.z 

    base address of inA
    (say addr)

    (expr1).mem_name

    type(expr1) struct X

    struct A* pA = &inA; 

    pA->z; 

    == 

    (*pA).z

*/

/* 
     ((struct B*)&inA)->y

     == 

    (*((struct B*)&inA)).y 

    type(inA) == struct A ... given by programmer 
    type(&inA) == struct A* .... inferred type 
    type(   ((struct (B*))&inA)     ) == struct B* 
    ... inferred type struct A* overridden by programmer to struct B*

    type((*((struct B*)&inA))) == struct B

*/
