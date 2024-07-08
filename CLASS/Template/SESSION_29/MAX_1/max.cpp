#include <iostream> 
#include "max.hpp"

int main(void){
    int a = 100, b = 50; 
    char x = 'Z', y = 'a'; 
    double m = 200.200, n = 100.100; 

    int i_max = max<int>(a, b); 
    char c_max = max<char>(x, y); 
    double d_max = max<double>(m, n); 

    max(10, 20);
    max('a', 'z');
    max(2.3, 1.1);  

    std::cout << "max between " << a << " and " << b << " is " << i_max << std::endl; 
    std::cout << "max between " << x << " and " << y << " is " << c_max << std::endl; 
    std::cout << "max between " << m << " and " << n << " is " << d_max << std::endl; 

    return 0; 
}

// function_template_name<template argument list> (actual parameter list);
// class_template_name<template argument list> object_name(initialization_data);  



