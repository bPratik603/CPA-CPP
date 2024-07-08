#include <stdio.h>

struct A{
    unsigned int a;
    unsigned int b;
    unsigned long long int arr[3];
    unsigned int c;
} inA = {0xffffffff,
         0xffffffff,
         {
            0xa0b0c0d011223344, 
            0x55667788aabbccdd, 
            0x123456789abcdef0},
            0xffffffff};

struct B{
    int u;
    int v;
    int w;
    int y;
};

void show(struct A* pA,const char* msg);

int main(void){
    show(&inA,"Before casting");
    ((struct B*)&inA)->y = 0x00000000;
    show(&inA,"After casting");

    return (0);
}

void show(struct A* pA,const char* msg){
    puts(msg);

    int i;

    printf("pA->a = %x\n",pA->a);
    printf("pA->b = %x\n",pA->b);
    for(i=0;i<3;i++)
      printf("pA->arr[%d]:%llx\n",i,pA->arr[i]);

    printf("pa->c = %x\n",pA->c);
}