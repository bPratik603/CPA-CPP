#include <iostream> 
#include <cstdlib> 

/*
class Date{
    private: 
        int day=1, month=1, year=1970; 
    public: 
        Date() = default; 
        Date(int init_day, int init_month, int init_year) : day(init_day), month(init_month), year(init_year){}
        Date(int init_day): Date(init_day, 7, 2021){}

        Date(int mm) : Date(1, mm, 1970) {} 
        void show(){
            std::cout << day << "-" << month << "-" << year << std::endl; 
        }
}; 

int main(void){
    Date d1; 
    Date d2(11, 7, 2021); 
    Date d3(20); 
    d1.show(); 
    d2.show(); 
    d3.show(); 
    return (0); 
}

*/

/* 
    typedef enum DateMember{
        DAY=1, 
        MONTH,
        YEAR
    }DateMemberType; 

    MOTIVATION CODE: 
    // 1-1-1970 -> default 
    class Date{
        public: 
            Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy) {} 
            Date(int dd) : day(dd), month(1), year(1970) {} 
            Date(int mm) : day(1), month(mm), year(1970) {} 
            Date(int yy) : day(1), month(1), year(yy) {} 
            Date(int dd, int mm) : day(dd), month(mm), year(1970) {} 
            Date(int dd, int yy) : day(dd), month(1), year(yy) {}
            Date(int mm, int yy) : day(1), month(mm), year(yy) {}
            Date() : day(1), month(1), year(1970) {} 
    }; 

*/



class Date{
    private: 
        int day, month, year; 

    public: 
        typedef enum DateMember{
            DAY     = 1, 
            MONTH   = 2,
            YEAR    = 4
        }DateMemberType; 

        // delegating constructor 
        Date(int dd, int mm, int yy) : day(dd), month(mm), year(yy) {} 

        Date(int field, DateMemberType ty){
            switch(ty){
                case DAY: 
                    Date(field, 1, 1970);
                    break; 
                case MONTH: 
                    Date(1, field, 1970); 
                    break; 
                case YEAR: 
                    Date(1, 1, field); 
                    break;  
            }
        }

        Date(int field_1, int field_2, int flag){
            bool day_flag = false, month_flag=false, year_flag=false; 
            if(flag & DAY)
                day_flag = true; 

            if(flag & MONTH)
                month_flag = true; 

            if(flag & YEAR)
                year_flag = true; 

            if(day_flag && month_flag)
                Date(field_1, field_2, 1970); 

            if(day_flag && year_flag)
                Date(field_1, 1, field_2); 

            if(month_flag && year_flag)
                Date(1, field_1, field_2); 
        }

}; 

int main(void)
{
    Date d1(15, Date::DAY); 
    Date d2(7, Date::MONTH); 
    Date d3(2024, Date::YEAR); 

    Date d4(15, 7, Date::DAY | Date::MONTH); 
    Date d5(7, 2024, Date::MONTH | Date::YEAR); 
    Date d6(4, 2024, Date::DAY | Date::YEAR);   

    return (0);   
}