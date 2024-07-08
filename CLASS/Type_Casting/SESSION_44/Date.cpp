#include <iostream> 

class Date{
    private: 
        int dd, mm, yy; 
    public: 
        Date(int _dd, int _mm, int _yy) : dd(_dd), mm(_mm), yy(_yy) {} 
}; 

int main(void){
    Date D(1, 1, 1970); 

    // std::cout << D.dd << "-" << D.mm << "-" << D.yy << std::endl; 

    std::cout   << *reinterpret_cast<int*>((reinterpret_cast<char*>((&D) + 0)))
                << "-"
                << *reinterpret_cast<int*>((reinterpret_cast<char*>(&D) + 4))
                << "-"
                << *reinterpret_cast<int*>((reinterpret_cast<char*>(&D) + 8))
                << std::endl; 

    return 0; 
}