#include <iostream> 
#include <cstdlib> 
#include <cassert> 
#include <cstring> 

class vector_int
{
    private: 
        int* p_arr; 
        size_t size; 
    public: 
        vector_int() : p_arr(0), size(0) {} 
    
        vector_int(size_t arr_size, int default_val=0)
        {
            assert(arr_size > 0); 
            p_arr = new int[arr_size]; 
            size = arr_size; 
            for(size_t i = 0; i < arr_size; ++i)
                p_arr[i] = default_val; 
        }

        vector_int(std::initializer_list<int> init_lst)
        {
            size = init_lst.size(); 
            p_arr = new int[size]; 
            size_t index = 0; 
            for(std::initializer_list<int>::iterator iter = init_lst.begin(); 
                iter != init_lst.end(); 
                ++iter)
            {
                p_arr[index] = *iter; 
                index += 1; 
            }
        }

        void show(const char* msg) const
        {
            if(msg)
                puts(msg); 
            for(size_t index = 0; index < size; ++index)
                std::cout << "A[" << index << "]:" << p_arr[index] << std::endl; 
        }

        ~vector_int()
        {
            delete[] p_arr; 
            p_arr = nullptr; 
        }
}; 

int main(void)
{
    vector_int ivec_1(10, 5); 
    vector_int ivec_2{100, 200, 300, 400}; 
    vector_int* p_ivec = new vector_int{1000, 2000, 3000, 4000}; 

    ivec_1.show("ivec_1:"); 
    ivec_2.show("ivec_2:"); 
    p_ivec->show("ivec_3:"); 

    delete p_ivec; 
    p_ivec = 0; 

    return (0); 
}

/* 
std::initializer_list<int>::iterator tmp = init_lst.begin(); 
std::initializer_list<int>::iterator iter = init_lst.begin(); 

std::initializer_list<int>::iterator::operator=(&iter, init_list.begin()); 

namespace std
{
    template <typename T> 
    class initializer_list 
    {
        public: 
            class iterator 
            {
                // synethsized member function 
                iterator& operator=(const iterator& other)
                {
                    // member wise copying
                    return *this;   
                }
            }; 
    }; 
}

*/

/* 
#include <vector> 

void test(void)
{
    std::vector<int> ivec_1;    // empty 
    std::vector<int> ivec_2(5); // storage for 5 ints is pre-callocated 
                                // ivec_2[0] to ivec_2[4]
    std::vector<int> ivec_3(10, 300); // storage for 10 ints is pre-allocated 
                                        // each int is initialized to 300 
    std::vector<int> ivec_4(ivec_3); 

    // C++ 11 onwards 
    std::vector<int> ivec_5 = {100, 200, 300, 400, 500}; 
    std::list<double> d_list = {1.1, 2.2, 3.3}; 
    std::map<int, double> myMap = {
        std::pair<int, double>(1, 1.1), 
    }

    int a[] = {13, 56, 23, 98, 74}; 
    std::vector<int> ivec; 

    for(size_t i = 0; i < sizeof(a)/sizeof(a[0]); ++i)
        ivec.push_back(a[i]); 

    std::vector<int> ivec = {13, 56, 23, 98, 74}; 
}

*/

/* 

template <typename T> 
class vector{
    private: 
        T* arr; 
        size_t N; 
    public: 
        vector(std::initializer_list<T> init_lst){
            size_t _N = init_lst.size(); 
            N = _N; 
            arr = new T[N]; 
            size_t i = 0; 
            std::initializer_list<T>::iterator iter = init_lst.begin(); 
            while(i < N)
            {
                arr[i] = *iter; 
                ++i; 
                ++iter; 
            }
        }
}; 

*/