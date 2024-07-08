#include <iostream> 

void test(int num = 10); 

int main(void){
    test(1000); 
    return 0; 
}

void test(int num){
    std::cout << "num:" << num << std::endl; 
}

