#include <stdio.h> 

unsigned long long int n = 0xffffffffffffffff; 

// in the first assignment statement only first byte 
// should be set to 0, rest should remain intact.

// in the second assignment, only byte number 2 and 3 
// should be set to 0, rest of the byte should be untouched 

int main(void){
    printf("n = %llx\n", n); 
    *(char*)&n = 0x00; 
    printf("n = %llx\n", n); 



    return (0); 
}

/* 
struct A inA; 
unsigned long long int i; 
char c; 
for(i = 0; i < sizeof(struct A); ++i)
    c = *(char*)((char*)&inA + i);
*/

