#include <iostream>
#include "self.hpp"

int main(void)
{
    int a=10,b=20;
    char p='a',q='z';
    double x=100.200,y=300.400;

    int int_max = max<int>(a,b);
    int char_max = max<char>(p,q);
    int double_max = max<double>(x,y);

    std::cout << "max between " << a << " and " << b << " is " << int_max << std::endl; 
    std::cout << "max between " << p << " and " << q << " is " << (char)char_max << std::endl; 
    std::cout << "max between " << x << " and " << y << " is " << double_max << std::endl; 

}