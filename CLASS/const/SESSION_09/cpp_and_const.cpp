#include <stdio.h> 

class Test{
    private: 
        const int n; 
    public: 
        Test(int _n) : n(_n){
        }

        void show(){
            printf("n = %d\n", n);             
        }
}; 

class Date{
    private: 
        int day, month, year; 
    public: 
        Date(int _d, int _m, int _y) : day(_d), month(_m), year(_y){}
        int get_day() const {
            return day; 
        }

        int get_month() const; 
}; 

int Date::get_month() const{
    return month; 
} 

int main(void){
    Test t(100); 
    t.show();
    return (0); 
}