#include <iostream> 

int main(void){
    int num = 10; // instance variable 
    int* p_num = &num; // pointer variable 
    int& ref_num = num; // lvalue reference variable 

    int&& rref_1 = 10;  // rvalue reference 
    int&& rref_2 = num + 15; // rvalue reference 

    return (0); 
}


 