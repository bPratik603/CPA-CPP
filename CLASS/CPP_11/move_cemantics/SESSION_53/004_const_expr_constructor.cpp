#include <iostream> 

void test_function(void); 

class Date{
    private: 
        int day, month, year; 

    public: 
        constexpr Date(int i_day, int i_month, int i_year) :  day(i_day), 
                                                        month(i_month), 
                                                        year(i_year){

        }

        void set_day(int new_day){
            day = new_day; 
        }

        void show() const {
            std::cout << day << "-" << month << "-" << year << std::endl; 
        }
}; 

class Employee{
    private: 
        Date dob; 
        Date doj; 

    public: 
        constexpr Employee(Date dobi, Date doji) : dob(dobi), doj(doji) { }
        void show() 
        {
            dob.show(); 
            doj.show(); 
        }
};

int main(void){
    int dd=10, mm=1, yy=2021; 

    Date d1(10, 1, 2021);   // d1 10, 1, 2021 
    Date d2(dd, mm, yy);    // d2 dd, mm, yy 
    d1.show(); 
    d2.show();
    d1.set_day(11); 
    d1.show();  
    

    constexpr Date d3(10, 1, 2021); 
    // d3.show(); 
    /* 
    // d3.set_day(24); 
    d3.show(); 

    const Date d4(dd, mm, yy); 
    d4.show(); 
    //d4.set_day(16); 

    Date dob1(1, 1, 1970); 
    Date doj1(2, 2, 1990); 
    Employee e1(dob1, doj1); 
    e1.show(); 

    constexpr Employee e2({1, 1, 1970}, {2, 2, 1990}); 
    e2.show(); 
*/ 

    return (0); 
}

void test_function(void)
{
    int m = 100; 
    const int n = m; 
    // constexpr int k = m; 
}

// constexpr = const + literal expression 