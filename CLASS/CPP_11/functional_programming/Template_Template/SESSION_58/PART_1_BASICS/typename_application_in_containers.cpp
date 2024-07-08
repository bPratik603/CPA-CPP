#include <iostream> 
#include <vector> 

template <typename T>
void test_function(T const& container){
    typename T::const_iterator pos; 
    typename T::const_iterator e_iter(container.end());

    for(pos = container.begin(); pos != e_iter; ++pos)
        std::cout << "*pos=" << *pos << std::endl;  
}

int main(void){
    std::vector<int> v{100, 200, 300, 400, 500}; 
    test_function<std::vector<int>>(v); 
    return 0; 
}