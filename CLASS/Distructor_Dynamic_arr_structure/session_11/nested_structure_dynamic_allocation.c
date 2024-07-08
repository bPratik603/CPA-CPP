/* PREP CODE FOR DESTRUCTOR IN C++*/
#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 

struct C{
    int a; 
    float b; 
    char c; 
}; 

struct B{
    int a; 
    struct C* pC; 
    double d; 
}; 

struct A{
    int a[5]; 
    struct B* pB; 
    short s[8]; 
}; 

int main(void){
    struct A* pA = NULL; 
    
    pA = (struct A*)malloc(sizeof(struct A)); 
    assert(pA); 

    int i; 
    for(i = 0; i < 5; ++i)
        pA->a[i] = (i+1) * 10; 
    for(i = 0; i < 8; ++i)
        pA->s[i] = (i+1) * 100; 
    
    pA->pB = (struct B*)malloc(sizeof(struct B)); 
    assert(pA->pB); 
    pA->pB->a = 100; 
    pA->pB->d = 100.100; 
    pA->pB->pC = (struct C*)malloc(sizeof(struct C)); 
    assert(pA->pB->pC); 
    pA->pB->pC->a = 1000; 
    pA->pB->pC->b = 3.14f; 
    pA->pB->pC->c = 'Z'; 

    /* Accessing all members */
    puts("Showing non-structure members of pA");
    for(i = 0; i < 5; ++i)
        printf("pA->a[%d]:%d\n", i, pA->a[i]); 
    for(i = 0; i < 8; ++i)
        printf("pA->s[%d]:%hd\n", i, pA->s[i]); 
    
    puts("showing nonstructure members of pA->pB"); 
    printf("pA->pB->a=%d, pA->pB->d=%.3lf\n", pA->pB->a, pA->pB->d); 

    puts("Showing non-structure members of pA->pB->pC"); 
    printf("pA->pB->pC->a=%d, pA->pB->pC->b=%.3f, pA->pB->pC->c=%c\n", 
            pA->pB->pC->a, pA->pB->pC->b, pA->pB->pC->c); 

    /* freeing all structure instances */
    free(pA->pB->pC); 
    free(pA->pB); 
    free(pA); 
    pA = NULL; 

    return (EXIT_SUCCESS); 
}