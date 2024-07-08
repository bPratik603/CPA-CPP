#include <iostream> 

class IntPtr 
{
    friend class HasPtr;

    private: 
        int* p; 
        int ref_count; 
        
        IntPtr(int _val) : p(new int(_val)), ref_count(1)
        {

        }
        
        ~IntPtr()
        {
            delete p; 
        }
}; 

class HasPtr 
{
    private: 
        int n; 
        IntPtr* pIntPtr; 
    
    public: 
        HasPtr(int _n, int _val): n(_n), pIntPtr(new IntPtr(_val))
        {
        }

        HasPtr(const HasPtr& other) : n(other.n), pIntPtr(other.pIntPtr)
        {
            pIntPtr->ref_count += 1; 
        }

        HasPtr& operator=(const HasPtr& other) 
        {
            n = other.n; 
            if(--pIntPtr->ref_count == 0)
                delete pIntPtr; 
            pIntPtr = other.pIntPtr; 
            pIntPtr->ref_count += 1; 
            return *this; 
        }

        ~HasPtr()
        {
            if(--pIntPtr->ref_count == 0)
                delete pIntPtr; 
        }

        int getrefcount() const 
        {
            return pIntPtr->ref_count; 
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

    std::cout << "End of application" << std::endl; 
    return (EXIT_SUCCESS); 
}