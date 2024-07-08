#include <iostream> 
#include <cassert> 

class cpa_array
{
    private: 
        int* pa; 
        size_t N; 

    public: 
        cpa_array(size_t _N) : pa(new int[_N]), N(_N)
        {
        }

        ~cpa_array()
        {
            delete[] pa; 
            pa = 0; 
            N = 0; 
        }

        size_t size() const 
        {
            return N; 
        }

        int& operator[](size_t i)
        {
            std::cout << "In cpa_array::operator[]:LHS" << std::endl; 
            assert(i < N); 
            return *(pa + i); 
        }

        const int& operator[](size_t i) const 
        {
            std::cout << "In cpa_array::operator[]:RHS" << std::endl; 
            assert(i < N); 
            return *(pa+i); 
        }
}; 


int main(void)
{
    cpa_array A(10); 

    for(
        int i = 0; 
        i != A.size();  
        ++i
    )
        A[i] = (i+1) * 10; 

    for(
        int i = 0; 
        i != A.size(); 
        ++i
    )
        std::cout   << "A["
                    <<  i 
                    << "]:"
                    << A[i]
                    << std::endl; 

    return EXIT_SUCCESS; 
}