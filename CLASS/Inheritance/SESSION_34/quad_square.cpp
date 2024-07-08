#include <cstdio> 
#include <cstdlib> 
#include <cassert> 
#include <cmath> 
#include <iostream> 

class Quadrilateral{
    private: 
        double s1, s2, s3, s4; 

    public: 
        Quadrilateral(
            double init_s1, 
            double init_s2, 
            double init_s3, 
            double init_s4
        ) : s1(init_s1), 
            s2(init_s2), 
            s3(init_s3), 
            s4(init_s4){
                assert(
                    (s1 + s2 + s3 < s4) && 
                    (s1 + s2 + s4 < s3) && 
                    (s1 + s3 + s4) < s2 && 
                    (s2 + s3 + s4) < s1
                ); 
        } 

        double perimeter() const{
            return (s1 + s2 + s3 + s4); 
        }

        double area() const{
            double s = (s1 + s2 + s3 + s4) / 2.0; 
            return sqrt((s - s1) * (s - s2) * (s - s3) * (s - s4)); 
        }
}; 

class Square : public Quadrilateral{
    private: 
        double s; 
    public: 
        Square(double _s) : Quadrilateral(_s, _s, _s, _s), s(_s){      
        }
 
        double area() const {
            return s * s; 
        }

        double diagonal_length() const {
            return sqrt(2) * s; 
        }
}; 

int main(void){
    Square* pSquare = new Square(10.0); 
    std::cout << "Area:" << pSquare->area() << std::endl; 
    std::cout << "Perimeter:" << pSquare->perimeter() << std::endl; 
    std::cout << "Diagonal:" << pSquare->diagonal_length() << std::endl; 
    delete pSquare; 
    pSquare = 0; 
    return 0; 
}

// Derived class object = Base + Derived member functions applicable 
// D is an object of derived class. 
// D.f() call is successfully placed. 

// f belongs to Bf UNION Df 
// IMPLIES THAT 
// f belongs to Bf - Df -> f is present only in Base class (INHERITOR)
// OR 
// f belongs to Df - Bf  -> f is present only in Derived class (DERVIED SPECIFIC MEMBER FUNCTIONS)
// OR 
// f belongs to Bf INTERSECTION Df -> f is present both in the Base and the Derived class 
// OVERRIDDEN MEMBER FUNCTION 
// 1) EXTENDOR 
// 2) REPLACOR 

class Employee{
    public: 
        double getSalary() const{

        }
}; 

class Manager : public Employee{
    public: 
        double getSalary() const {
            double base_sal = Employee::getSalary(); 
            // apply some perks and allowances on base_sal 
            // return computed_sal 
        }
}; 
