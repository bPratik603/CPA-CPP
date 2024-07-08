#include <iostream> 
#include <cassert> 
#include "complex.hpp"

// parameterized + default constructor 
complex::complex(double _x, double _y) : x(_x), y(_y)
{
}

// arithmetic operator overload 
complex complex::operator+(const complex& rhs_object) const
{
    return complex(this->x + rhs_object.x, this->y + rhs_object.y);
}

complex complex::operator-(const complex& rhs_object) const
{
    return complex(this->x - rhs_object.x, this->y - rhs_object.y);
}

complex complex::operator*(const complex& rhs_object) const
{
    return complex(
        this->x * rhs_object.x - this->y * rhs_object.y, 
        this->x * rhs_object.y + rhs_object.x * this->y
    ); 
}

complex complex::operator/(const complex& rhs_object) const
{
    assert(rhs_object.x != 0.0 || rhs_object.y != 0.0); 
    
    return complex(
        (this->x*rhs_object.x + this->y * rhs_object.y)/
        (rhs_object.x*rhs_object.x + rhs_object.y*rhs_object.y), 
        (-this->x*rhs_object.y + rhs_object.x * this->y)/
        (rhs_object.x*rhs_object.x + rhs_object.y*rhs_object.y)
    ); 
}

// comparison operator overload 
bool complex::operator==(const complex& rhs_object) const
{
    return (this->x == rhs_object.x && this->y == rhs_object.y); 
}

bool complex::operator!=(const complex& rhs_object) const
{
    return (this->x != rhs_object.x || this->y != rhs_object.y); 
}

// cin cout operator overload 
std::istream& operator>>(std::istream& is, complex& complex_object)
{
    std::cout << "Enter x:"; 
    is >> complex_object.x; 
    std::cout << "Enter y:"; 
    is >> complex_object.y; 
    return is; 
}

std::ostream& operator<<(std::ostream& os, const complex& complex_object)
{
    os  <<  "(" 
        << complex_object.x 
        << ")+i(" 
        <<  complex_object.y 
        << ")";
    return os;  
}