#include <iostream>
#include "self_quadrilateral.hpp"

int main(void){
    Quadrilateral* qobj = new Quadrilateral(10.5, 7.6, 6.9, 9.2);
    double perimeter = qobj->perimeter();
    double area = qobj->area();

    std::cout<<"perimeter: "<<perimeter<<std::endl;
    std::cout<<"area: "<<area<<std::endl;

    delete qobj;
    qobj = 0;

    return 0;
}