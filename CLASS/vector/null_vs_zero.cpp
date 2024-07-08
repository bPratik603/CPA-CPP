/*
    void test(void){
        int* p = (int*)malloc(sizeof(int)); 
        // use p 

        free(p); 
        p = NULL; 
        p = 0; 
    }
*/

#include <iostream> 
#include <cstdlib> 

int main(void){
    int* p = malloc(sizeof(int)); 
    
    int* p = NULL; 

    return (0); 
}