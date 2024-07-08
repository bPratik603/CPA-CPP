#include <iostream> 

class CPA_int
{
    private: 
        int N; 
    public: 
        CPA_int(int _N = 0) : N(_N)
        {
        }

        CPA_int operator+(CPA_int other) 
        {
            int result = this->N + other.N; 
            CPA_int summation_object(result); 
            /* 
                this->N == (*this).N

                type(this) == CPA_int*
                type(*this) == CPA_int
                type((*this).N) == type(member N in class CPA_int)
                type((*this).N) == int ... from type annotation 
                type(this->N) == int 

                type(other) == CPA_int 
                type(other.N) == type(member N in class CPA_int)
                type(other.N) == int 

                type(this->N) == int && type(other.N) == int 
                type(this->N + other.N) == int 
                therefore, we've annotated type of result as int 
            */

            return summation_object; 
        }
}; 

int main(void)
{
    CPA_int Ci_1(100), Ci_2(200); 
    CPA_int Ci_sum = Ci_1 + Ci_2; 
  
   
    return 0; 
}

