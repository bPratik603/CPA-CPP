#include <iostream> 

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

int main(void)
{
    int m = 100; 
    const int n = 200;  //  const int n = m; 
                        //  will work but constexpr int cint_expr_1 = n; will break
    constexpr int cint_expr_1 = n; 
    // constexpr int cint_expr_2 = m; 
    constexpr Date d(1, 1, 1970);
    
    int dd=10, mm=2, yy=2000; 
    const Date X(dd, mm, yy); 
    constexpr Date Y(dd, mm, yy); // CTE 
    constexpr Date Z(1, 1, 1970); 
    
    const int dd1 = 10;     // if initializer of dd1, mm1 or yy1 
    const int mm1 = 3;      // cannot be resolved statically then 
    const int yy1 = 1989;   // constexr Date W(dd1, mm1, yy1) will break 
    constexpr Date W(dd1, mm1, yy1); 



    return (0); 
}