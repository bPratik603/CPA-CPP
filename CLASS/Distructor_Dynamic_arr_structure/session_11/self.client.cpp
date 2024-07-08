#include<iostream>
#include<cassert>
#include<ctime>
#include "self.hpp"

int main(void)
{
    array* pa = 0;
    array::status_t status;
    ssize_t N;

    N = 8;
    pa = new array(8);

    for(ssize_t i=0;i<pa->size();++i)
    {
        status = pa->set(i,(i+1) * 10);
        assert(status == array::status::SUCCESS);

    }

    pa->show("AFter Setting:");

    std::cout<<"Client fetching and showing each element:"<<std::endl;
    int element;

    for(ssize_t i = 0;i<pa->size();++i)
     {
        status = pa->get(i,&element);
        std::cout<<"a["<<i<<"]:"<<element<<std::endl;
        assert(status == array::status::SUCCESS);
     }

     
}
