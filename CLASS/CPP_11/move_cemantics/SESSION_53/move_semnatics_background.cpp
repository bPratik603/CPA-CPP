#include <iostream> 

class T{
    private: 
        int num; 
        double d_num; 
    public: 
        T(int _num, double _d_num) : num(_num), d_num(_d_num){
        }

        T() = default; 
        ~T() = default; 
        T(const T&) = default; 
        T& operator=(const T& other) = default; 
        T(T&&) = default; 
        T& operator=(T&&) = default; 

        friend std::ostream& operator<<(std::ostream& os, const T& t); 
}; 

std::ostream& operator<<(std::ostream& os, const T& t){
    os  << "num:" << t.num << std::endl 
        << "d_num:" << t.d_num << std::endl; 
    return os; 
}

int main(void){
    T t1(100, 100.1); 
    T t2(200, 200.2); 
    T t3(300, 300.3); 

    std::cout << "t1:" << t1; // 100, 100.1
    std::cout << "t2:" << t2; // 200, 200.2
    std::cout << "t3:" << t3; // 300, 300.3

    T t4(std::move(t1)); 
    t3 = std::move(t2); 
    
    std::cout << "t1 has been moved to t4 while creating it" << std::endl; 
    std::cout << "t2 has been moved to t3. both t2 and t3 have been initialized using parameterized constructor" << std::endl; 
    std::cout << "t4:" << t4; // 100, 100.1
    std::cout << "t3:" << t3; // 200, 200.2

    std::cout << "After move:" << std::endl; 
    std::cout << "t1:" << t1; // 0, 0.0 (will not be as expected) t1 will retain its original content 
    std::cout << "t2:" << t2; // 0, 0.0 (will not be as expected) t2 will retain its original content 

    return (0); 
}