#include <iostream> 
#include <vector> 

int main(void){
    
    std::vector<int> ivec1; 
    std::vector<int> ivec2(10);     // 10 elements preallocation 
    std::vector<int> ivec3(5, 15);  // 5 elements, each initialized to 15
    std::vector<int> ivec4(ivec3); 
    std::vector<int> ivec5 = {100, 200, 300, 400, 500};

    for(std::vector<int>::size_type i = 0; 
        i != ivec5.size(); 
        ++i)
            std::cout << ivec5[i] << std::endl; 

    for(std::vector<int>::iterator iter = ivec5.begin(); 
        iter != ivec5.end(); 
        ++iter) 
            std::cout << "*iter=" << *iter << std::endl; 

    ivec1.push_back(100); 
    ivec1.pop_back(); 

    return 0; 
}