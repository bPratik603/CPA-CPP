// Partial Specialization 

#include <iostream> 
#include <typeinfo> 

template <typename T1, typename T2> 
class TestClass{
    private: 
        T1 data1; 
        T2 data2;
    public: 
        TestClass(){
            std::cout << "template <typename T1, typename T2>" 
                      << std::endl; 
            std::cout << "typeid(data1):" << typeid(data1).name() 
                      << std::endl
                      << "typeid(data2):" << typeid(data2).name()
                      << std::endl; 
        } 
}; 

template <typename T> 
class TestClass<T, T>{
    public: 
        TestClass(){
            std::cout << "class TestClass<T, T>" << std::endl; 
            std::cout << "typeid(T):" << typeid(T).name() << std::endl; 
        }
}; 

template <typename T1, typename T2> 
class TestClass<T1*, T2*>{
    public: 
        TestClass(){
            std::cout << "class TestClass<T1*, T2*>" << std::endl; 
            std::cout << "typeid(T1*):" << typeid(T1*).name() 
                      << std::endl
                      << "typeid(T2*):" << typeid(T2*).name() 
                      << std::endl; 
        }
}; 
