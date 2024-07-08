#include <iostream>

void func(const int* p,bool RO);

int gc_num = 100;

int main(void){
    const int lc_num = 200;
    int num = 300;
    
    func(&gc_num,false);
    func(&lc_num,false);
    func(&num,false);

    func(&num,true);
    func(&lc_num,true);
    func(&gc_num,true);

   return 0;
}

void func(const int* p,bool RO){
    if(RO == false)
      std::cout<<"Only Reading from p : "<< *p<<std::endl;
    else if(RO == true)
        *const_cast<int*>(p) = 1000;
      std::cout<<"Reading after writging 1000:"<<*p<<std::endl;
}