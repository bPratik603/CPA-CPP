#include <iostream> 
#include "animal.hpp"
#include "dog.hpp"

int main(void){
    animal a1; 
    dog indie_dog("MOTI", 1); 

    std::cout << "START" << std::endl; 
    QObject::connect(
        &a1, 
        SIGNAL(shout()), 
        &indie_dog, 
        SLOT(barking())                
    ); 

    a1.trigger_shout(); 
     
    return (0); 
}