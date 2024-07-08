namespace cpa{
    template <typename T> 
    class shared_ptr{
        private:
            T* ptr; 
            size_t ref_cnt; 
        public: 
            shared_ptr(T* _ptr) : ptr(_ptr), ref_cnt(1){

            }

            T* get() const{
                return ptr; 
            }
    }; 
}

void test(void){
    int* p = new int(100); 
    cpa::shared_ptr<int> p_int(p); 

    int* ptr = p_int.get(); 

    if(p == ptr){
        std::cout << "YES!" << std::endl; 
    }
}