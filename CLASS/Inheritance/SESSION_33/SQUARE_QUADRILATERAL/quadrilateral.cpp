#include <iostream> 
#include <cmath> 
#include "quadrilateral.hpp"

Quadrilateral::Quadrilateral(
    double init_s1, 
    double init_s2, 
    double init_s3, 
    double init_s4
) : s1(init_s1), 
    s2(init_s2), 
    s3(init_s3), 
    s4(init_s4){
        if(
            (s1 + s2 + s3) < s4 || 
            (s2 + s3 + s4) < s1 || 
            (s3 + s4 + s1) < s2 || 
            (s1 + s2 + s4) < s3 
        ){
            std::cout << "Invalid sides for quadrialteral" << std::endl; 
            exit(EXIT_FAILURE); 
        } 
} 

double Quadrilateral::perimeter() const{
    return (s1 + s2 + s3 + s4);
}

double Quadrilateral::area() const{
    double s = (s1 + s2 + s3 + s4) / 2.0;
    return sqrt((s-s1) * (s-s2) * (s-s3) * (s-s4));  
}