#include <iostream> 
#include <cstdlib> 

struct IntPtr 
{
    int* p; 
    int ref_count;
}; 

class HasPtr 
{
    private: 
        int n; 
        struct IntPtr* p_int_ptr; 

    public: 

        // Parameterized constructor 
        HasPtr(int _n, int _val)
        {
            this->n = _n; 
            this->p_int_ptr = new IntPtr; 
            this->p_int_ptr->p = new int(_val); 
            this->p_int_ptr->ref_count = 1; 
        }

        HasPtr(const HasPtr& other)
        {
            this->n = other.n; 
            this->p_int_ptr = other.p_int_ptr; 
            this->p_int_ptr->ref_count += 1; 
        }

        HasPtr& operator=(const HasPtr& rhs_object)
        {
            if(this == &rhs_object)
                return *this; 
                
            this->n = rhs_object.n; 
            this->p_int_ptr->ref_count -= 1; 
            if(this->p_int_ptr->ref_count == 0)
            {
                delete this->p_int_ptr->p; 
                delete this->p_int_ptr; 
            }
            this->p_int_ptr = rhs_object.p_int_ptr; 
            this->p_int_ptr->ref_count += 1; 
            return *this; 
        }

        ~HasPtr()
        {
            this->p_int_ptr->ref_count -= 1; 
            std::cout << "Decremented the ref count:this:" << std::hex << this << std::endl; 
            std::cout << "Refcount(After decrement):" << std::dec << this->p_int_ptr->ref_count 
                        << std::endl; 
            if(this->p_int_ptr->ref_count == 0)
            {
                std::cout << "deleting p_int_ptr:this" << std::hex << this << std::endl; 
                delete this->p_int_ptr->p; 
                delete this->p_int_ptr; 
            }
        }

        int getrefcount() const 
        {
            return this->p_int_ptr->ref_count; 
        }
}; 

int main(void)
{
    HasPtr* php1 = new HasPtr(100, 200); 
    std::cout   << "php1->getrefcount():" 
                << php1->getrefcount()      // 1 
                << std::endl;
    HasPtr* php2 = new HasPtr(1000, 2000); 
    std::cout   << "php2->getrefcount():" 
                <<  php2->getrefcount()     // 1 
                <<  std::endl;

    HasPtr* php3 = new HasPtr(*php1); 
    std::cout   << "php1->getrefcount():" 
                << php1->getrefcount()      //2 
                << std::endl;
    std::cout   << "php3->getrefcount():" 
                << php3->getrefcount()      //2 
                << std::endl;

    *php1 = *php2; 
    std::cout   << "php3->getrefcount():" 
                << php3->getrefcount()      //1
                << std::endl;
    std::cout   << "php2->getrefcount():" 
                << php2->getrefcount()      //2 
                << std::endl;
    
    delete php1; 
    php1 = 0; 

    delete php2; 
    php2 = 0; 

    delete php3; 
    php3 = 0; 

    return (EXIT_SUCCESS); 
}
