#include <stdio.h> 
#include <stdlib.h> 

void test(void); 

struct A
{
    int a; 
    char b; 
    float c; 
}; 

#define OFFSET_OF(T, mem) ((unsigned long long int)(&(((T*)0)->mem)))

int main(void)
{
    unsigned long long int offset; 

    offset = (unsigned long long int)(&((struct A*)0)->a); 
    printf(
            "offset of member 'a' relative to struct A = %llu\n", 
            offset
        ); 

    offset = (unsigned long long int)(&((struct A*)0)->b); 
    printf(
            "offset of member 'b' relative to struct A = %llu\n", 
            offset
        );

    offset = (unsigned long long int)(&((struct A*)0)->c); 
    printf(
            "offset of member 'c' relative to struct A = %llu\n", 
            offset
        );

    test(); 

    return (0); 
}

void test(void)
{
    struct A inA; 
    unsigned long long int off_a, off_b, off_c; 

    // int* 
    off_a = (unsigned long long int)&inA.a - (unsigned long long int)&inA;
    // char*
    off_b = (unsigned long long int)&inA.b - (unsigned long long int)&inA; 
    // float* 
    off_c = (unsigned long long int)&inA.c - (unsigned long long int)&inA;
    printf("off_a=%llu, off_b=%llu, off_c=%llu\n", 
            off_a, off_b, off_c); 
    
    off_a = 100; 
    off_b = 100; 
    off_c = 100; 

    printf("off_a=%llu, off_b=%llu, off_c=%llu\n", 
            off_a, off_b, off_c); 
    
    off_a = OFFSET_OF(struct A, a); 
    off_b = OFFSET_OF(struct A, b); 
    off_c = OFFSET_OF(struct A, c); 
    printf("off_a=%llu, off_b=%llu, off_c=%llu\n", 
            off_a, off_b, off_c); 

}

/* 
type(0) -> int .... by type inference 
type((struct A*)0) -> struct A* (overridden by type casting)

((strut A*)0)->c 
(*((struct A*)0)).c 

unsigned long long int off_c; 

off_c = (unsigned long long int)(&((*((struct A*)0)).c))

.section .bss 
    .comm   off_c, 8, 8 

.section .text 
    movq    8, off_c

struct A* p = NULL; 

lhs = p->c; 
p->c = rhs; 

&p->c 

&(expr)

&10; 

a + b; 

&(a+b)

float* pf = &(p->c); 

unsigned long long int n = (unsigned long long int)&(((struct A*)0)->c); 

struct list_head{
    struct list_head* prev; 
    struct list_head* next; 
}; 

struct int{
    int data; 
    struct list_head links; 
}; 

struct student 
{
    int roll; 
    float marks; 
    float attnd; 
    struct list_head links; 
}; 


*/

