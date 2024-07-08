#include<iostream>
#include<cstdlib>
#include "self.hpp"

int main(void){

    vector v1;
    vector v2(5);
    vector v3(5,88);
    vector v4(v3);

    v1.show("v1");
    v2.show("v2");
    v3.show("v3");
    v4.show("v4");

    
    vector::ssize_t size;

    size = v4.size();
    std::cout<<"v4.size(): "<<size<<std::endl;

    size = v4.max_size();
    std::cout<<"v4.max_size(): "<<size<<std::endl;

    for(vector::ssize_t i=0;i<100;i+=10)
    {
           v1.push_back(i);
    }

    while(true)
    {
        int data;
       vector::status_t status;
       status = v1.pop_back(&data);

       if(status == vector::VECTOR_EMPTY)
       {
              break;
       }

       std::cout<<"poped data : "<<data<<std::endl;
    }

    return(0);
}