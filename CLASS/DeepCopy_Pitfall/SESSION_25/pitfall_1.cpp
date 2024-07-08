#include <iostream> 

class HasPtr
{
    private: 
        int num; 
        int* p; 
    
    public: 
        HasPtr(
            int _num, 
            int _n
        ) : num(_num), 
            p(new int(_n))
        {
        }

        int get_num() const 
        {
            return num; 
        } 

        int* get_ptr() const 
        {
            return (p); 
        }

        int get_ptr_val() const 
        {
            return (*p); 
        }

        void set_ptr_val(int new_val)
        {
            *p = new_val; 
        }

        ~HasPtr()
        {
            delete p; 
            p = 0; 
        }
}; 

int main(void)
{
    // p_hp1->_num == 100
    // p_hp1->p == addr of integer object 
    //          placed on heap memory 
    // *p_hp1->p == 200 
    //  The integer object placed on memory will 
    //  be initialized to 200
    HasPtr* p_hp1 = new HasPtr(100, 200); 
    
    //  There is no explcit constructor written 
    //  which will initialize the newly allocated 
    //  object by exiting object. 
    //  Yet the initialization shown below does not 
    //  yield an error. 
    //  Why? Synthesized Copy Constructor 
    //  What is copy constructor? 
    //  What is synthesized copy constructor? 
    //  What is the default behaviour of the synthesized 
    //  copy constructor 
    HasPtr* p_hp2 = new HasPtr(*p_hp1); 
    //  p_hp2->num == p_hp1->num 
    //  p_hp2->ptr == p_hp2->ptr 

    if(p_hp1->get_num() == p_hp2->get_num())
        std::cout   << "value in num of p_hp1 and p_hp2 is same" 
                    << std::endl; 

    if(p_hp1->get_ptr() == p_hp2->get_ptr())
        std::cout << "addr in ptr member of p_hp1 and p_hp2 is same"
                  << std::endl; 

    //  Integer object allocated on heap while allocating the first 
    //  object is now shared by the second object as well. 
    std::cout   << "BEFORE:p_hp2->get_ptr_val():" 
                << p_hp2->get_ptr_val() 
                << std::endl; 
    p_hp1->set_ptr_val(500); 
    std::cout   << "AFETR:p_hp2->get_ptr_val():" 
                << p_hp2->get_ptr_val() 
                << std::endl; 

    //  soft pitfall: objects pointed by p_hp1 and p_hp2 have shared integer 
    //  object. The change made through one is visible in the other. 

    //  hard pitfall 1 : if one of the objects is deleted then the destructor 
    //  call for that object will free the shared object on heap 
    //  making pointer in another object a dangling pointer. 
    //  De-referencing such pointer will lead to a seg fault. 
    //  POTENTIAL SEGFAULT 
    
    /*
    delete p_hp2; 
    std::cout   << "p_hp1->get_ptr_val():" 
                << p_hp1->get_ptr_val() 
                << std::endl; 
    */

   //   hard pitfall 2: if one object is assigned to the other then it will 
   //   cause a memory leak 
   HasPtr* p_hp3 = new HasPtr(1000, 2000); 

    //  assignment operator is not explicitly overloaded for class HasPtr 
    //  yet the following assignment does not emit an error. 
    //  Why? Because of synthesized overload assignment operator. 
    //  p_hp1->num == p_hp2->num 
    //  p_hp1->ptr == p_hp2->ptr 
   *p_hp1 = *p_hp3; 
   //   addr in p_hp1->ptr before assignment will be overwritten 
   //   without deleting causing a memory leak 
 
    delete p_hp1; 
    p_hp1 = 0; 

    delete p_hp2; 
    p_hp2 = 0;
}