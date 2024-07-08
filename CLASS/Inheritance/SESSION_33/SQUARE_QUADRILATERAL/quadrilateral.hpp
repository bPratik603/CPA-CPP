#ifndef _QUADRILATERAL_HPP
#define _QUADRILATERAL_HPP

class Quadrilateral{
    private: 
        double s1, s2, s3, s4; 
    public: 
        Quadrilateral(
            double init_s1, 
            double init_s2, 
            double init_s3, 
            double init_s4
        ); 

        double perimeter() const; 
        double area() const; 
}; 

#endif // _QUADRILATERAL_HPP