#include "partial_specialization.hpp"

int main(void){
    TestClass<int, float> tc1; 
    TestClass<int, int> tc2; 
    TestClass<int*, float*> tc3; 
    TestClass<int**, float*> tc4; 
    return 0; 
}
