#include <iostream>
#include "self.hpp"
#include <cassert>

complex complex::operator+(const complex& rhs_obj) const
{
    return complex(this->x+rhs_obj.x,this->y+rhs_obj.y);
}

complex complex::operator-(const complex& rhs_obj) const
{
    return complex(this->x-rhs_obj.x,this->y-rhs_obj.y);
}

complex complex::operator*(const complex& rhs_obj) const
{
    return complex((this->x*rhs_obj.x - this->y*rhs_obj.y), this->x*rhs_obj.y + rhs_obj.x*this->y);
}

complex complex::operator/(const complex& rhs_obj) const
{
    return complex((this->x*rhs_obj.x + this->y*rhs_obj.y) / (rhs_obj.x * rhs_obj.x),
                    ((-this->x*rhs_obj.y + rhs_obj.x*this->y) / (rhs_obj.x+rhs_obj.x + rhs_obj.y * rhs_obj.y)));
}

complex operator>>(std::istream& is,complex& complex_obj)
{
    std::cout<<"Enter x:";
    is >> complex_obj.x;
    std::cout<<"Enter y";
    is >> complex_obj.y;

    return is;
}

complex operator<<(std::ostream& os,const complex& complex_obj)
{
    os << "("<<complex_obj.x<<") + i("<<complex_obj.y<<")";
    return (os);
}

bool operator==(const complex& rhs_obj)
{
    return (this->x == rhs_obj.x && this->y == rhs_obj.y);
}

bool operator!=(const complex& rhs_obj)
{
    return(this->x != rhs_obj.x || this->y != rhs_obj.y);
}

