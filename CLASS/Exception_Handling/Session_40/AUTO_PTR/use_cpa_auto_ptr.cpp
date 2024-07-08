#include <iostream> 
#include "cpa_auto_ptr.hpp"

void test(void); 

int main(void){
    test(); 
    return (0); 
}

void test(void){
    cpa_auto_ptr<int> p_int(new int(100)); 

    std::cout << "*p_int=" << *p_int << std::endl; 
    *p_int = 500; 
    std::cout << "*p_int=" << *p_int << std::endl; 
}