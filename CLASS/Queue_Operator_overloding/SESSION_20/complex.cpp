#include <iostream> 

class complex 
{
    private: 
        double re, im; 

    public: 
        complex(double _re = 0.0, double _im = 0.0) : re(_re), im(_im)
        {

        }

        complex operator+(const complex& other) const 
        {
            double re = this->re + other.re; 
            double im = this->im + other.im; 
            complex addition_object(re, im); 
            return addition_object; 
        }

        bool operator==(complex* other)
        {
            return (this->re == other->re && this->im == other->im); 
        }
}; 

int main(void)
{
    complex* pc1 = new complex(1.1, 2.2); 
    complex* pc2 = new complex(1.1, 2.2); 

    if(pc1 == pc2)
        std::cout << "two complex numbers are equal" << std::endl; 
    else 
        std::cout << "two complex numbers are not equal" << std::endl; 

    delete pc1; 
    pc1 = 0; 

    delete pc2; 
    pc2 = 0; 

    return 0; 
}