#include <iostream> 
#include <cstdlib> 

class Date{
    private: 
        int day = 1; 
        int month = 1; 
        int year = 1970;
    public: 
        Date(){}; 
        
        Date(int init_day, int init_month, int init_year) : day(init_day),
                                                            month(init_month), 
                                                            year(init_year){

        } 
        
        void show(){
            std::cout << day << "-" << month << "-" << year << std::endl; 
        } 
}; 

class Employee{
    private: 
        Date emp_joining_date{12, 11, 2020}; 
        Date emp_birth_date;
    public: 
        void show(){
            emp_joining_date.show();  
            emp_birth_date.show(); 
        } 
}; 

int main(void)
{
    Employee e; 
    e.show(); 

    return (0); 
}

