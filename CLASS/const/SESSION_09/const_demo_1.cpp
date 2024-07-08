#include <cstdio>
#include <cstdlib> 

const int g_num = 100; 

int main(void){
    const int l_num = 200; 
    int* p1 = NULL; 
    int* p2 = NULL; 

    //g_num = 1000; // CTE: LHS expression must be a modifiable lvalue 
    //l_num = 2000; // CTE: LHS expression (on LHS) must be a modifiable lvalue 
   
    /* p1 = const_cast<int*>(&g_num); */
    // p1 = &g_num; // CTE : cannot convert const int* to int* 
    // p2 = &l_num; // CTE : cannot convert const int* to int* 

    printf("BEFORE:*p2 = 2000:*p2 = %d\n", *p2); 
    *p2 = 2000; 
    printf("AFTER:*p2 = 2000:*p2 = %d\n", *p2); 

    printf("BEFORE:*p1 = 1000:*p1 = %d\n", *p1); 
    *p1 = 1000; // MEMORY VIOLATION EXCEPTION 
    printf("AFTER:*p1 = 1000:*p1 = %d\n", *p1); 

    return 0; 
}

/* 
    l-value mentions const object. 

    int g_num; -> data definition statement 

    int -> type annotation 
    g_num -> identifier 

    cosnt int g_num = 100; 

    100 -> initializer 
    g_num -> identifier 
    int -> type annotation 
    const -> qualification 

    int -> data type naav 
    const int -> data type naav 
*/

