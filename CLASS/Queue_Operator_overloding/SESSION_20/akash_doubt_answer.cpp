/* 
    sir can you please explain scenarios where T and T& is used alternatively 
    for return values and accepting variable. Like, returning T but accepting T&, 
    returning T& but accepting T.
*/


#include <iostream> 

class T1 
{
    private: 
        int N;

    public: 
        T1(int _N = 0) : N(_N)
        {

        }

        T1& operator+(T1 rhs_object)
        {
            T1* p_sum_object = new T1(this->N + rhs_object.N); 
            return *p_sum_object;  
        } 

        
}; 

class T2 
{
    private: 
        int N; 

    public: 

        T2(int _N = 0) : N(_N)
        {

        }

        T2 operator+(T2& rhs_object)
        {
            T2 sum_object(this->N + rhs_object.N); 
            return sum_object;  
        } 

        void show() const 
        {
            std::cout << "N:" << N << std::endl; 
        }

}; 

void test1(void); 
void test2(void); 

int main(void) 
{
    test1(); 
    test2(); 
    return 0; 
}

void test1(void)
{
    T1 obj1(100), obj2(200); 

    T1& result = obj1 + obj2; 

    delete &result; 

}

void test2(void)
{
    T2 obj1(100), obj2(200);

    T2& result = obj1 + obj2;  
    result.show(); 
    std::cout << "returning from test2()" << std::endl; 

    // result 
}

/* 
    T1 result = obj1 + obj2; 

    T1 result =obj1 + obj2; 

    T1 result =obj1.operator+(obj2); 

    T1 result = T1::operator+(&obj1, obj2); 

    result = *p_sum_object
*/

/* 
    int m = 100; 
    int& ref = m; 

    int k = ref; 

*/