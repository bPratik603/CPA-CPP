#include <cstdio> 

class X{
    //  Synthesized constructor / synthesized default 
};  


class Y{
    public: 
        // Default constructor 
        Y(){
            puts("Inside Y::Y()"); 
        }
}; 

class Z{
    public: 
        // Parameterized constructor 
        Z(int _n, double _d){
            printf("Inside Z::Z():_n=%d, _d=%.3lf\n", _n, _d); 
        }
}; 

int main(void){
    X objX; 
    Y objY; 
    Z objZ(10, 3.14);

    return 0;  
}
