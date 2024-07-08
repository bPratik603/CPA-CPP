#include <iostream> 
#include <cstdlib> 

class Callable
{
    private: 
        int (*pfn)(int, int); 

    public: 
        Callable(int(*_pfn)(int, int)) : pfn(_pfn)
        {

        }

        int operator()(int ap1, int ap2)
        {
            return pfn(ap1, ap2); 
        }

        void set(int(*_pfn)(int, int))
        {
            pfn = _pfn; 
        }
}; 

int my_add(int m, int n); 
int my_sub(int m, int n); 
int my_mul(int m, int n); 
int my_div(int m, int n); 

int main(void)
{
    Callable cobj(my_add); 
    int m = 100, n = 200; 
    int rs; 

    rs = cobj(m, n); 
    std::cout << "addition:" << rs << std::endl; 

    cobj.set(my_sub); 
    rs = cobj(m, n); 
    std::cout << "subtraction:" << rs << std::endl; 

    cobj.set(my_mul); 
    rs = cobj(m, n); 
    std::cout << "multiplication:" << rs << std::endl; 

    cobj.set(my_div); 
    rs = cobj(m, n); 
    std::cout << "quotient:" << rs << std::endl; 

    return 0; 
}

int my_add(int m, int n)
{
    return (m+n); 
}

int my_sub(int m, int n)
{
    return (m-n); 
}

int my_mul(int m, int n)
{
    return (m*n); 
}

int my_div(int m, int n)
{
    return (m/n); 
}
