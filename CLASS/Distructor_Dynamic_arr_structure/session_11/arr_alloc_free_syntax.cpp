#include <cassert>

class T{

}; 

typedef unsigned long long int size_t; 

void test(void){
    /* Let T be any defined type in program. May be user defined | May be built in */
    /* Let N be a positive integer*/
    size_t N = 10; 
    assert(N > 0); 

    /* To allocate array of size N of elements of type T */

    T* p_arr = new T[N]; 

    /* To free such array */
    delete[] p_arr; 
    p_arr = 0; 
}