#include <vector> 
#include "template_server.hpp"

class Date{

}; 

class Book{

}; 

void test(void); 

int main(void){
    test(); 
    return (0); 
}

void test(void){
    X1<10> objX1; 
    X2<int> objX2; 
    X3<int, float> objX3_1; 
    X3<Date, Book> objX3_2; 
    X3<int, Book> objX3_3; 
    X3<Date, float> objX3_4;

    X3<int, X2<Book>> objX3_5; 
    X3<Book, X2<Book>> objX3_6; 
    X3<float, std::vector<float>> objX3_7; 


    XX1<X2> objXX1; 
    XX2<X3> objXX2; 
    XX3<X2, X3> objXX3; 
    XX4<X4> objXX4; 


    
}
