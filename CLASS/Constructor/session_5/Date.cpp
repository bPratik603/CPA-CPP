#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <cassert>

// SERVER 
class Date{
    private: 
        int day, month, year; 

    public: 
        Date() : day(1), month(1), year(1970){

        }

        Date(int _day, int _month, int _year) : day(_day), 
                                                month(_month), 
                                                year(_year){

        }

        Date(const char* date_str){
            size_t L = strlen(date_str); 
            assert(L > 0); 
            char* clone_date_str = (char*)malloc(L+1);
            
            *(clone_date_str + L) = '\0'; 
            strncpy(clone_date_str, date_str, L); 
            
            day = atoi(strtok(clone_date_str, "/")); 
            month = atoi(strtok(NULL, "/")); 
            year = atoi(strtok(NULL, "/"));

            free(clone_date_str); 
            clone_date_str = NULL; 
        }

        void show(){
            printf("%d/%d/%d\n", day, month, year); 
        }
}; 

// CLIENT 
int main(void){
    Date myDate; // 1/1/1970
    Date cpaDate(28, 2, 2015); 
    Date yearEndDate("31/12/2023"); 

    myDate.show(); 
    cpaDate.show(); 
    yearEndDate.show(); 

    return (EXIT_SUCCESS); 
}