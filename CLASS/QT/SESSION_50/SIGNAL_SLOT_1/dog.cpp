#include "dog.hpp"
#include <iostream> 

dog::dog(const char* _name, int _dog_type) : QObject(), name(_name), dog_type(_dog_type){

}

const char* dog::get_name() const{
    return (name); 
}

int dog::get_type() const{
    return (dog_type); 
} 

void dog::barking(){
    switch(this->dog_type){
        case INDIE: 
            std::cout << "MEEK BARKING OF INDIE" << std::endl; 
            break; 
        case GOLDEN_RERIEVER: 
            std::cout << "GRACEFUL BARKING OF GOLDEN RETRIEVER" << std::endl; 
            break; 
        case PITBULL: 
            std::cout << "FEROCIOUS BARKING OF PITBULL" << std::endl; 
            break; 
        default: 
            std::cout << "STUPID HOOMAN!" << std::endl; 
    }
}

void dog::shouting_as_told(const char* msg){
    std::cout << msg << std::endl; 
}