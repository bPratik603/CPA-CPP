#include <stdio.h> 

int main(void){
    int m = 10, n = 10; 

    const int* const p = &m; 

    // p = &n;     // CTE : expression must be modifiable lvalue
    //*p = 100;   // CTE : expression must be modifiable lvalue

    return 0; 
}

/* 
    non-const pointer to non-const type 
    T* p; 

    const pointer to non-const type 
    T* const p = &objT; 

    non-const pointer to const type 
    const T* p; 

    const pointer to const type 
    const T* const p = &objT; 

*/