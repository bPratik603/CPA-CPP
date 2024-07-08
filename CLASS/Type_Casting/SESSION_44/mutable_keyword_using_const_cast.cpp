#include <iostream> 

class Number{
    private: 
        int n;
        int cnt;  //mutable int cnt 
    public: 
        Number(int _n) : n(_n){

        }

        int get() const {
            // cnt += 1; // error. type(this) == const Number*
            const_cast<Number*>(this)->cnt += 1;     
            // if you want to avoide casting this pointer 
            // while everytime modifying cnt 
            // then declare int cnt to be mutable in class 
            return n; 
        }

        void set(int new_n){
            n = new_n; 
        }

        int getter_frequency() const {
            return cnt; 
        }
}; 

int main(void){
    Number N(10); 

    for(int i = 0; i < 5; ++i)
        std::cout << "N=" << N.get() << std::endl; 

    std::cout << "Getter frequency on N:" << N.getter_frequency() 
              << std::endl; 

    return 0; 
}