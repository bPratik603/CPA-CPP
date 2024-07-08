#include <thread> 
#include <vector> 
#include <mutex> 
#include <stdexcept> 

class Stack{
    private: 
        std::vector<int> ivec; 
        mutable std::mutex mtx;  

    public: 
        int pop() const{
            mtx.lock(); 
            if(ivec.empty()){
                mtx.unlock(); 
                throw std::runtime_error("Cannot pop from empty stack"); 
            }
            int ret = ivec[ivec.size()-1];  
            mtx.unlock(); 
            return ret; 
        }
}; 
