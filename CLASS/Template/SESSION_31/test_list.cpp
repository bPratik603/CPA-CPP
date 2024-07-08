#include "list.hpp"

int main(void){
    cpa::dsa::list<int> lst; 
    for(int data = 0; data < 5; ++data)
        lst.insert_end((data+1) * 100); 
    std::cout   << "After insert_start():" << std::endl
                <<  lst; 
    return 0; 
}

