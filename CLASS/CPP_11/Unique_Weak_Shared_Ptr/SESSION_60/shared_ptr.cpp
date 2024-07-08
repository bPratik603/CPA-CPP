#include <iostream> 
#include <cstdlib> 

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

            shared_ptr<T>(const shared_ptr<T>& other) : ptr(other.ptr), (++ref_cnt){
                
            }

            shared_ptr<T>& operator=(const shared_ptr<T>& other){
                if(--refcnt == 0)
                    delete ptr;
                this->ptr = other.ptr; 
                other.ref_cnt += 1; 
                this->ref_cnt = other.ref_cnt; 
                return *this; 
            }

            shared_ptr<T>& operator=(std::nullptr_t& other){
                if(--refcnt == 0)
                    delete ptr;
                this->ptr = 0; 
                this->ref_cnt = 0;  
            }

            T& operator*(){
                return *ptr; 
            }

            T* operator->(){
                return ptr; 
            }

            ~shared_ptr(){
                if(--ref_cnt == 0){
                    std::cout << "RC(" << std::hex << this << ") == 0" << std::endl; 
                    delete ptr; 
                }
            }

            size_t use_count() const {
                return ref_cnt; 
            }
    }; 
}

class Date{
    private: 
        int day, month, year; 
    public: 
        Date(int _day, int _month, int _year) : day(_day), 
                                                month(_month), 
                                                year(_year){

        }

        int get_day() const {
            return day; 
        }

        void set_day(int new_day) {
            day = new_day; 
        }
}; 

int main(void){
    int* p = new int(100); 
    cpa::shared_ptr<int> p_int(p); 

    int* ptr = p_int.get(); 
    std::cout << "ptr:" << std::hex << ptr << std::endl; 
    if(p == ptr){
        std::cout << "YES!" << std::endl; 
    }

    std::cout << "*p_int:" << *p_int << std::endl; 

    cpa::shared_ptr<Date> pDate(new Date(1, 1, 1970)); 

    std::cout << "pDate->get_day():" << pDate->get_day() << std::endl; 
    pDate->set_day(5); 
    std::cout << "pDate->get_day():" << pDate->get_day() << std::endl; 
    std::cout << "DatePtr:" << std::hex << pDate.get() << std::endl; 

    std::cout << "&p_int:" << std::hex << &p_int << std::endl; 
    std::cout << "&pDate:" << std::hex << &pDate << std::endl; 

    return EXIT_SUCCESS; 
}