#include<cstdio>

int main(void)
{
    int m = 10;
    int n = 20;
   const int* const p1 = &m;

    printf("m = %d\n",m);
    printf("p1 = %d\n",*p1);
    p1 = 200;
    printf("p1 = %d\n",*p1);

    return(0); 
}