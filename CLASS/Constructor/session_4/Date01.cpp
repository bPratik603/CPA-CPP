#include <cstdio> 

class Date{
    private: 
        int day, month, year; 
    public: 
        Date(){
            printf("Date::Date():%p\n", this); 
        }
}; 

int main(void){
    Date d1, d2; 
    printf("main():&d1=%p, &d2=%p\n", &d1, &d2); 
    return (0); 
}