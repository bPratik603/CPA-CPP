#include <iostream> 
#include <cstdlib> 

void foo(void); 

template <typename T> 
class Base{
    public: 
        void exit(int code){
            std::cout << "In Base::exit()" << std::endl; 
        }

        void foo(){
            std::cout << "Base::foo" << std::endl; 
        }
}; 

template <typename T> 
class Derived : public Base<T>{
    public: 
        void member_function(){
            exit(EXIT_FAILURE); // resolves to Base::exit() 
            foo();  // resolves to Base::foo() 
            // In older C++, 
            // this->exit(EXIT_FAILURE); 
            // this->foo(); 
            // was required. 
        }
};  

int main(void){
    Derived<int> d; 
    d.member_function(); 
    std::cout << "End of program" << std::endl; 
    return 0; 
}

void foo(void){
    std::cout << "In ::foo()" << std::endl; 
}