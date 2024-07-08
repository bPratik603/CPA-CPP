#ifndef _SELF_H
#define _SELF_H

#include <iosteam>

class complex
{
    private:
     double x,y;

    public:
      complex(double _x,double _y) : x(_x),y(_y)
      {}

    complex operator+(const complex& rhs_obj) const;
    complex operator-(const complex& rhs_obj) const;
    complex operator*(const complex& rhs_obj) const;
    complex operator/(const complex& rhs_obj) const;

    bool operator==(const complex& rhs_obj) const;
    bool operator!=(const complex& rhs_obj) const;

    friend std::istream operator>>(std::istream& is,complex& complex_obj);
    friend std::ostream operator<<(std::ostream& os,const complex* complex_obj);
}

std::istream& operator>>(std::istream& is,complex& complex_obj);
std::ostream& operator<<(std::ostream& os, const complex& complex_obj);

#endif