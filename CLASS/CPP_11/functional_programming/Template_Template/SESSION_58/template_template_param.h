#include <iostream> 

template <typename T1, typename T2> 
class CONTAINER_1{
public:
    CONTAINER_1(){
        std::cout << "CONTAINER_1" << std::endl; 
    }
}; 

template <typename T1, typename T2> 
class CONTAINER_2{
public:
    CONTAINER_2(){
        std::cout << "CONTAINER_2" << std::endl; 
    }
}; 

template <typename T1, typename T2> 
class CONTAINER_3{
public:
    CONTAINER_3(){
        std::cout << "CONTAINER_3" << std::endl; 
    }
}; 

template <typename T1, typename T2, template <typename T1, typename T2> class CONT_TYPE> 
class X{
    private: 
        CONT_TYPE<T1, T2> OBJ; 
}; 
