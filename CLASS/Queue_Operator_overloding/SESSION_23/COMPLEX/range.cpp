#include <iostream> 
#include <cassert> 

class range 
{
    private: 
        int n_start, n_end; 
    public: 
        range(int _end) : n_start(0), n_end(_end-1)
        {
            assert(_end > 0); 
        } 

        range(int _start, int _end) : n_start(_start), n_end(_end-1)
        {
            assert(_start < _end); 
        } 

        class iterator 
        {

        }; 

}; 

int main(void)
{
    range R1(10); 
    range R2(10, 20); 

    range::iterator iter = R1.begin();  
    while(iter != R1.end())
    {
        *iter
        ++iter; 
    }

/*
    container_class_name::iterator iter = container_object.begin(); 
    while(iter != container_object.end())
    {   
        (*iter) // access object 
        ++iter; 
    }
*/

    return 0; 
}
