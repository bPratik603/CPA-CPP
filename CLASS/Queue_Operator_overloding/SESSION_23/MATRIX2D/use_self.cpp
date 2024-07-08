#include <iostream> 
#include "mat2d.hpp"

int main(void)
{
    mat2d m1(3, 3); 
    mat2d m2(3, 3); 

    for(
        mat2d::size_type i = 0; 
        i != m1.rows(); 
        ++i
    )
        for(
            mat2d::size_type j = 0; 
            j != m1.cols(); 
            ++j
        )
        m1.set(i, j, (i+j)); 

    for(
        mat2d::size_type i = 0; 
        i != m2.rows(); 
        ++i
    )
        for(
            mat2d::size_type j = 0; 
            j != m2.cols(); 
            ++j
        )
        m2.set(i, j, (i+1) * (j+1)); 

    mat2d mat_sum = m1 + m2; 
    mat2d mat_sub = m1 - m2; 
    mat2d mat_mul = m1 * m2; 

    std::cout << "m1:" << m1 << std::endl; 
    std::cout << "m2:" << m2 << std::endl; 
    std::cout << "mat sum:" << mat_sum << std::endl; 
    std::cout << "mat sub:" << mat_sub << std::endl; 
    std::cout << "mat mul:" << mat_mul << std::endl; 

    return EXIT_SUCCESS; 
}

