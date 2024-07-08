template <typename T> 
class C{
    private: 
        T data; 
    public: 
        void f(T data){
            // some code 
        }
}; 

void testC(void){
    C<int> objC; 
    objC.f(100); 

    C<float> objCf; 
    objCf.f(1.1f); 
}