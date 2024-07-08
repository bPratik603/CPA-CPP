#include <iostream>
#include <cstdio>
#include <cstdlib> 
#include <cctype> 
#include <cstdarg> 

class cpa_array{
    private: 
        int* p_arr; 
        size_t size; 
    public: 
        cpa_array(...){
            va_list ap; 
            va_start(ap, this);
            int a = va_arg(ap, int); 
            std::cout << "a:" << a << std::endl;
            va_end(ap); 
            std::cout << "sizeof(ap):" << sizeof(ap) << std::endl;   
        }
}; 

int main(void){
    cpa_array A{10, 20, 30, 40, 50}; 
    return (0); 
}

/* 
void test(void)
{
    std::vector<int> v1; // empty 
    std::vector<int> v2(5); // vector with five preallocated slots for integer 
                            // value in those five slot is the default value for type 
    std::vector<int> v3(5, 100); 

    std::vector<int> v4{100, 200, 300, 400, 500}; 
    std::list<int> v5 = {100, 200, -400, -500}; 

    array A{100, 200, 300}; 
}*/ 