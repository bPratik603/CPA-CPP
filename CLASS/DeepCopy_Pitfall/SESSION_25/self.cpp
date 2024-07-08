#include <iostream>

class HasPtr
{
    private:
    int num;
    int* p;

    public:
     HasPtr(int _num,int _p) : num(_num),p(new int(_p))
     {}

     int get_num()
     {
        return num;
     }

     int* get_ptr()
     {
        return p;
     }

     int get_ptr_val()
     {
        return *p;
     }

};

int main(void)
{
    HasPtr* p_hp1 = new HasPtr(100,200);

    HasPtr* p_hp2 = new HasPtr(*p_hp1);

    if(p_hp2->get_num() == p_hp1->get_num())
    {
        std::cout<<"p_hp2->num == p_hp1->num"<<std::endl;
        std::cout<<p_hp2->get_num()<<"             "<<p_hp1->get_num()<<std::endl;
    }

    if(p_hp2->get_ptr() == p_hp1->get_ptr())
    {   
       std::cout<<"p_hp2->get_ptr() == p_hp1->get_ptr()"<<std::endl;
       std::cout<<p_hp2->get_ptr()<<"    "<<p_hp1->get_ptr()<<std::endl;
    }  

    if(p_hp2->get_ptr_val() == p_hp1->get_ptr_val())
    {
         std::cout<<"p_hp2->get_ptr_val() == p_hp1->get_ptr_val()"<<std::endl;
         std::cout<<p_hp2->get_ptr_val()<<"         "<<p_hp1->get_ptr_val()<<std::endl;
    }

    HasPtr* p_hp3 = new HasPtr(1000,2000);

    *p_hp1 = *p_hp3;

    std::cout<<"p_hp1->get_num()  "<<p_hp1->get_num()<<"  "
              <<p_hp1->get_ptr()<<"  "<<p_hp1->get_ptr_val()<<std::endl;

    delete p_hp1;
     p_hp1 = 0;

    delete p_hp2;
     p_hp2 = 0;

}