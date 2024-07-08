#ifndef _CPA_AUTO_PTR_HPP 
#define _CPA_AUTO_PTR_HPP

#include <iostream> 

template <typename T> 
class cpa_auto_ptr{
    private: 
        T* ptr; 
    public: 
        cpa_auto_ptr(T* _p) : ptr(_p){

        }

        T& operator*(){
            return *ptr; 
        }

        ~cpa_auto_ptr(){
            std::cout << "In Destructor" << std::endl; 
            delete ptr; 
        }
}; 

#endif 