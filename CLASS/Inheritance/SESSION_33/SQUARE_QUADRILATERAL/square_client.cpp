#include <iostream> 
#include <cstdlib> 
#include "square.hpp"

void main(void){
    Square* pSquare = new Suqare(10); 
    double perimeter = pSquare->perimeter(); 
    double area = pSquare->area(); 
    double diag_len = pSquare->diagonal_legth();  

    std::cout   << "Perimeter:" << perimeter << std::endl 
                << "Area:" << area << std::endl 
                << "Diagonal Length:" << diag_len << std::endl; 

    delete pSquare; 
    pSquare = 0; 

    return (EXIT_SUCCESS); 
}

// perimeter : sum of all sides of square 
// area : side * side 
// diagonal length : sqrt(2) * side 
