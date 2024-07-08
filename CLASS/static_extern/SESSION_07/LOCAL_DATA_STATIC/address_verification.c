#include <stdio.h> 

void test(int k){
    int m; 
    static int n; 

    if(k > 0)
    {
        printf("Addr(m)=%llu\n", (unsigned long long)&m); 
        printf("Addr(n)=%llu\n", (unsigned long long)&n);
        test(k-1); 
    } 
}

int main(void){
    test(5); 
    return (0); 
}