#include <iostream> 
#include <cstdlib> 
#include "quadrilateral.hpp"

int main(void){
    Quadrilateral* pQuad = new Quadrilateral(10.5, 7.6, 6.9, 9.2); 
    double perimeter = pQuad->perimeter(); 
    double area = pQuad->area(); 

    std::cout   << "perimeter:" << perimeter << std::endl 
                << "area:" << area << std::endl; 

    delete pQuad; 
    pQuad = 0; 

    return EXIT_SUCCESS; 
}