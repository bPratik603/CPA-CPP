void f(){
    int* p = NULL; 
    p = (int*)malloc(sizeof(int)); 
    // YES
    g(); 
    // NO 

    free(p); 
}

class intptr{
    private: 
        int* p; 
    public: 
        intptr(int* _p) : p(_p){

        }

        int& operator*(){
            return *p; 
        }

        ~intptr(){
            free(p); 
        }
}; 

void f(){
    // f() is in the stack unwinding path of some exception 
    intptr p(malloc(sizeof(int))); 
    int m; 

    *p = 500;
    m = *p; 
}

template <typename T> 
class auto_ptr{
    private: 
        T* ptr; 
    public: 
        auto_ptr(T* _p) : ptr(_p){

        }

        T& operator*(){
            return *ptr; 
        }

        ~auto_ptr(){
            delete ptr; 
        }
}; 

void f(){
    auto_ptr<int> p_int(new int(100)); 
    auto_ptr<float> p_flt(new float(3.14f)); 

    
}