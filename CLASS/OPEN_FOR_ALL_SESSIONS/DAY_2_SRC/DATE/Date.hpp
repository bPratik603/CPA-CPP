#ifndef _DATE_H 
#define _DATE_H 

class Date{
    private: 
        int day; 
        int month; 
        int year; 
        // auxillary (helper) functions
        static bool is_valid(int day, int month, int year); 
    public: 
        //  Constructors 
        Date(); // Default 
        Date(int _dd, int _mm, int _yy); // Parameterized 
        
        // getters 
        int get_day() const; 
        int get_month() const; 
        int get_year() const; 

        // setters 
        void set_day(int new_day); 
        void set_month(int new_month); 
        int set_year(int new_year); 

        // display 
        void show() const; 
}; 


#endif 