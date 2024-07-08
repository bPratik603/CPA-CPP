#include <iostream> 

void func(const int* p, bool readonly_override);

const int gc_num = 100; 

int main(void){
    const int lc_num = 200; 
    int num = 300; 

    func(&gc_num, false); 
    func(&lc_num, false); 
    func(&num, false); 

    func(&num, true); 
    func(&lc_num, true); 
    std::cout << "second last statement" << std::endl; 
    func(&gc_num, true); // segmentation fault 
    std::cout << "last statement" << std::endl; 

    return (0); 
}

void func(const int* p, bool readonly_override){
    if(readonly_override == false){
        std::cout   << "ONLY READING FROM p" << std::endl 
                    << "*p=" << *p << std::endl;  
    }
    else if(readonly_override == true){
        *const_cast<int*>(p) = 1000; 
        std::cout << "Reading after writing 1000:" << *p << std::endl; 
    }
}
