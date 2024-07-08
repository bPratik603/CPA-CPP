#ifndef _TEMPLATE_SERVER_HPP 
#define _TEMPLATE_SERVER_HPP 

#include <vector> 

template <size_t N> 
class X1{}; 

template <typename T> 
class X2{

};

template <typename T1, typename T2> 
class X3{

}; 

template <template <typename T> class T1>
class XX1{}; 

template <template <typename TT1, typename TT2> class T2>
class XX2{}; 

template <  
            template <typename TT1> class T1, 
            template <typename TT2, typename TT3> class T2
        >
class XX3{

}; 

template <typename T1, typename T2 = std::vector<int>>  
class X4{
}; 

template <template<typename T1, typename T2 = std::vector<int>> class TT1>
class XX4{
};

#endif 