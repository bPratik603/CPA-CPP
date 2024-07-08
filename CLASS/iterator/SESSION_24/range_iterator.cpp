#include <iostream> 
#include <cstdlib> 
#include <cassert> 

class range 
{
    private: 
        int n_start; 
        int n_end; 
    public: 
        class iterator; 

        range(int _end) :   n_start(0), 
                            n_end(_end)
        {
            assert(_end > 0); 
        }

        range(int _start, int _end) :   n_start(_start), 
                                        n_end(_end)
        {
            assert(_end > _start); 
        }

        iterator begin() 
        {
            return iterator(n_start); 
        }

        iterator end()
        {
            return iterator(n_end); 
        }

        class iterator 
        {
            private: 
                int n; 
            public: 
                iterator(int _n = 0) : n(_n)
                {

                }

                iterator operator++()
                {
                    ++n; 
                    return *this; 
                }

                iterator operator++(int)
                {
                    iterator tmp_iter(n); 
                    ++n; 
                    return tmp_iter; 
                }

                iterator operator--()
                {
                    --n; 
                    return *this; 
                }

                iterator operator--(int)
                {
                    iterator tmp_iter(n); 
                    --n; 
                    return tmp_iter; 
                }

                int operator*() 
                {
                    return n; 
                }

                bool operator==(const iterator& other) const
                {
                    return (this->n == other.n); 
                }

                bool operator!=(const iterator& other) const
                {
                    return (this->n != other.n); 
                }
        }; 
};

int main(void)
{
    range r1(5); 
    range r2(5, 10); 

    std::cout << "Iterating over r1:" << std::endl; 
    for(
        range::iterator iter = r1.begin(); 
        iter != r1.end(); 
        ++iter
    )
        std::cout << "*iter=" << *iter << std::endl; 

    std::cout << "Iterating over r2:" << std::endl; 
    for(
        range::iterator iter = r2.begin(); 
        iter != r2.end(); 
        ++iter
    )
        std::cout << "*iter=" << *iter << std::endl; 

    return EXIT_SUCCESS;  
}
