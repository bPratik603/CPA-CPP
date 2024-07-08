#include <stdio.h> 
#include <stdlib.h> 

//      5000     5001    5002    5003
// LE   0d       0c      0b      0a 
// BE   0a       0b      0c      0d  
// if v is a variable then irrespective of 
// the endianness of the machine &v is the least 
// or the base address of v. 

int main(void){
    int n = 0x0a0b0c0d; 

    if(*(char*)&n == 0xd)
        puts("Little Endian"); 
    else if(*(char*)&n == 0xa)
        puts("Big Endian"); 
    else 
        puts("The control flow should never some here"); 

    return (0); 
}