#include <iostream> 

void ref_to_ptr(void); 

void test_1(int* p); 
void test_2(int& x); 

int main(void){
    int num = 10; 
    int& z = num; 
    
    std::cout << "&num=" << std::hex << &num << std::endl 
                << "&z=" << std::hex << &z << std::endl; 
    std::cout << "num:" << std::dec << num << std::endl 
                << "z:" << z << std::endl;  
    ref_to_ptr(); 

    test_1(&num); 
    test_2(num); 

    return 0; 
}

void ref_to_ptr(){
    typedef float* float_ptr_t; 
    float f = 3.14f; 
    float* pf = &f; 
    float*  &y1 = pf; 
    float_ptr_t& y2 = pf; 
    std::cout << "*y1 = " << *y1 << std::endl; 
    std::cout << "*y2 = " << *y2 << std::endl; 
}

void test_1(int* p){
    std::cout << "test_1():*p=" << *p << std::endl;
    std::cout << "test_1():p=" << std::hex << p << std::endl;    
}

void test_2(int& x){
    std::cout << "test_2():x=" << std::dec <<  x << std::endl; 
    std::cout << "test_2():&x=" << std::hex << &x << std::endl; 
}