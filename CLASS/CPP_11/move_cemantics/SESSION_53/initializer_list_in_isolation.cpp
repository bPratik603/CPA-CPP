#include <iostream> 

int main(void){
    std::initializer_list<int> i_lst = {100, 200, 300, 400, 500}; 

    for(
        std::initializer_list<int>::iterator iter = i_lst.begin();
        iter != i_lst.end(); 
        ++iter
    )
        std::cout << "*iter = " << *iter << std::endl; 


    std::cout << "------------------------------------------" << std::endl; 
    std::initializer_list<double> d_lst = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8}; 

    for(
        std::initializer_list<double>::iterator iter = d_lst.begin(); 
        iter != d_lst.end(); 
        ++iter
    )
        std::cout << "*iter = " << *iter << std::endl; 
}

