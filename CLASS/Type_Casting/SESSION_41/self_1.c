#include <stdio.h>

unsigned long long int n = 0xffffffffffffffff;

int main(void){
    printf("n = %llx\n",n);

    *(char*)&n = 0x00;
    printf("n = %llx\n",n);

    *(unsigned short*)((char*)&n+1) = 0x0000;
     printf("n = %llx\n",n);

     *(unsigned int*)((char*)&n+3) = 0x00000000;
     print("n = %llx\n",n);

     *(unsigned char*)((char*)&n+7) = 0x0;
     printf("n = %llx\n",n);

     return(0);

}