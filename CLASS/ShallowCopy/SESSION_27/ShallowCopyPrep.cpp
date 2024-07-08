class HasPtr
{
    private: 
        int n; 
        int* ptr; 
        static int ref_count; 

    public: 
        HasPtr(int _n, int _val) :  n(_n), 
                                    ptr(new int(_val))
        {

        } 

        //  I must override default version of 
        //  copy assignment operator so as to avoid 
        //  memory leak 
        HasPtr& operator=(const HasPtr& rhs_object)
        {
            //  What should I write here? 
        }

        ~HasPtr()
        {
            //  Should really delete this->ptr 
            //  What if there are other objects of 
            //  HasPtr whose ptr member contains 
            //  the same address as that of this->ptr 
            delete ptr; 
        }
}; 

int main(void)
{
    HasPtr* p_hp1 = new HasPtr(100, 200); 
    HasPtr* p_hp2 = new HasPtr(*p_hp1); 
    HasPtr* p_hp3 = new HasPtr(1000, 2000); 
    HasPtr* p_hp4 = new HasPtr(10000, 20000);

    /* 
        p_hp1->n == 100, p_hp2->n == 100
        p_hp1->ptr == p_hp2->ptr == x (*x == 200)
        p_hp3->n == 1000, p_hp3->ptr == y (*y == 2000)
        p_hp4->n == 10000, p_hp4->ptr == z (*z == 20000)
    */

   delete p_hp2; // p_hp1->ptr is dangling 

    *p_hp3 = *p_hp4; // y is a leaked memory 



    return (0); 
}


/* 
    Conceptual solution: 
        
        Every dynamically allocated  integer, whose address 
        is stored in ptr members of HasPtr objects, should be 
        aware of the total number HasPtr objects containing 
        its address. This count of objects is also known as the 
        reference count of dynamically allocated integer. 

        The destructor call for any HasPtr object MUST ensure 
        that the current HasPtr object is the last object containing 
        the address of integer before applying delete on ptr member. 

        This requires us to keep track of the reference count of dynamically 
        allocated object in general. Therefore, We must be aware of the places 
        where the reference count must be changed. 

        Therefore, we must override the default implementation of 
        1) Copy constructor 
        2) Copy assignment operator 
        3) Destructor  
*/

