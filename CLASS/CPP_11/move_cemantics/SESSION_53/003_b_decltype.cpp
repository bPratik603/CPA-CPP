#include <iostream> 
#include <cstdlib> 
#include <ctime> 

void f(int a, int b)
{
    std::cout << "Test" << std::endl; 
}

/* 
Constant expression is the one whose value cannot be 
changed later and can be evaluated at compile time 
*/ 

void test(void);
unsigned long get_rand();  

int main(){
    srand(time(0)); 
    int a; 
    decltype(a) b = 500; 
    decltype(f)*pfn = f; 
    pfn(10, 20);  
    const int size = 100;           //  constant expression 
    const int max_size = size+50;   //  constant expression 
    const unsigned long num = get_rand();   //  not a constant expression 
                                            //  as it cannot be evaluated 
                                            //  at compile time 
}

unsigned long get_rand(){
    return rand(); 
}

// decltype(expr) -> used as a type-annotation in data definition statements 
