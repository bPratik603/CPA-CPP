#ifndef _COMPLEX_H 
#define _COMPLEX_H 

#include <iostream> 

class complex 
{
    private: 
        double x, y; 
    public: 
        // parameterized + default constructor 
        complex(double _x = 0.0, double _y = 0.0); 

        // arithmetic operator overload 
        complex operator+(const complex& rhs_object) const; 
        complex operator-(const complex& rhs_object) const; 
        complex operator*(const complex& rhs_object) const; 
        complex operator/(const complex& rhs_object) const; 

        // comparison operator overload 
        bool operator==(const complex& rhs_object) const; 
        bool operator!=(const complex& rhs_object) const; 

        // cin operator overload - friend function decl 
        friend std::istream& operator>>(std::istream& is, complex& complex_object); 
        friend std::ostream& operator<<(std::ostream& os, const complex& complex_object); 
}; 

std::istream& operator>>(std::istream& is, complex& complex_object);
std::ostream& operator<<(std::ostream& os, const complex& complex_object);

#endif /* _COMPLEX_H */