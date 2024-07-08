#include <cstdio> 
#include <cstring> 
#include <cstdlib> 

class Date{
    private: 
        int day, month, year; 
    public: 
        Date(char* str_date) :  day(atoi(strtok(str_date, "-"))), 
                                month(atoi(strtok(NULL, "-"))), 
                                year(atoi(strtok(NULL, "-")))
        {
   

        }
}; 

