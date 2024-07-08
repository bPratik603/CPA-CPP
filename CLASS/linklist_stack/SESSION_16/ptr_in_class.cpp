#include <cstdio> 
#include <cstdlib> 

class Test_2
{
    private: 
        int* p; 

    public: 
        Test_2(int val)
        {
            printf("In Test_2::Test_2():this:%p\n", this); 
            this->p = (int*)malloc(sizeof(int)); 
            if(this->p == NULL)
            {
                puts("Error in allocating memory"); 
                exit(EXIT_FAILURE); 
            }
            *this->p = val; 
        }

        int get() 
        {
            printf("In Test_2::get():this:%p\n", this);
            return *this->p; 
        }

        int set(int new_val)
        {
              printf("In Test_2::set():this:%p\n", this);
            *this->p = new_val; 
        }

        ~Test_2()
        {
            printf("In Test_2::~Test_2():this:%p\n", this);
            free(p); 
            p = 0; 
        }
}; 

int main(void)
{
    Test_2* pt = 0; 

    pt = new Test_2(100); 
    printf("main():pt:%p\n", pt); 
    printf("main():val:%d\n", pt->get()); 
    pt->set(200); 
    printf("main():val:%d\n", pt->get()); 
    delete pt; 
    pt = 0; 

    return 0; 
}