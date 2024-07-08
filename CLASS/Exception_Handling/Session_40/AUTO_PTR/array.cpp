#include <iostream> 
#include <cassert> 

class array{
    private: 
        int* p; 
        int N; 
    public: 
        array(int _N) : N(_N), p(new int[N]){
          
        }

        int& operator[](int i){
            assert(i >= 0 && i < N); 
            return *(p+i); 
        }

        ~array(){
            delete[] p; 
        }
}; 

