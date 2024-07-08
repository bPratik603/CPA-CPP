#include <stdio.h> 
#include <stdlib.h> 

int main(void){
    int* p = NULL; 

    p = malloc(sizeof(int)); 

    free(p); 
    p = NULL; 

    return (0); 
}