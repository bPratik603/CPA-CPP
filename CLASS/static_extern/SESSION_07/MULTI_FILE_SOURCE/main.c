#include <stdio.h> 
#include <stdlib.h> 

extern static double mul_init_val; 

extern double angle; 

extern double cpa_sin(double x); 
extern double cpa_cos(double x); 

int main(void){
    double result; 
    mul_init_val = 500.500; 
    result = cpa_sin(angle); 
    printf("result=%.3lf\n", result); 
    result = cpa_cos(angle); 
    printf("result=%.3lf\n", result); 
    return (0); 
}

[extern/static] [const] type variable_name

int float num; 


