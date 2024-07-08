#include <iostream> 
#include "complex.hpp"

int main(void)
{
    complex c1; 
    complex c2; 

    std::cin >> c1; 
    std::cin >> c2;  

    complex c_sum = c1 + c2; 
    complex c_sub = c1 - c2; 
    complex c_mul = c1 * c2; 
    complex c_div = c1 / c2; 

    std::cout   << "c1:" << c1 << std::endl 
                << "c2:" << c2 << std::endl 
                << "c_sum:" << c_sum << std::endl 
                << "c_sub:" << c_sub << std::endl 
                << "c_mul:" << c_mul << std::endl
                << "c_div:" << c_div << std::endl; 

    if (c1 == c2)
        std::cout << c1 << " and " << c2 << " are equal to each other" << std::endl; 

    if (c1 != c2)
        std::cout << c1 << " and " << c2 << " are not equal to each other" << std::endl; 

    return 0; 
}