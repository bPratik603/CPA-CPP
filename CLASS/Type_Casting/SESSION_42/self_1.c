#include <stdio.h>
#include <stdlib.h>

void test(void);

struct A{
    int a;
    char b;
    float c;
};

#define OFFSET_OF(T,mem) ((unsigned long long int)(&(((T*)0)->mem)))

int main(void){
    unsigned long long int offset;

    offset = (unsigned long long int)(&((struct A*)0)->a);
    
}