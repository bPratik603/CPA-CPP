#include <iostream> 
#include <memory> 

void test(void); 

int main(void){
    std::cout << "calling test()" << std::endl; 
    test(); 
    std::cout << "returning from test()" << std::endl; 
    return (0); 
}

void test(void){
    int n = 100; 
    std::shared_ptr<int> p_int(&n); 
    std::cout << "*p_int:" << *p_int << std::endl; 
    std::cout << "last line in test()" << std::endl; 
}

/* 
std::make_shared<T>(initialization data for new object oF T)

== 

new T(initialization data for new object oF T)

*/