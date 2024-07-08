#include <stdio.h> 
#include <stdlib.h> 

struct D 
{
    float fnum; 
    double dnum; 
}; 

struct C 
{
    int a; 
    char b; 
    struct D* pD; 
    float x; 
}; 

struct B
{
    double d1, d2; 
}; 