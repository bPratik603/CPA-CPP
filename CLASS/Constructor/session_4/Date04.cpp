#include <cstdio> 
#include <cstdlib> 
#include <cstring> 

class Date{
    private: 
        int day, month, year; 
    public: 
        Date(const char* str_date){
            
            size_t L = strlen(str_date); 
            
            char* cc_strdate = (char*)malloc(L+1); 
            if(cc_strdate == NULL){
                puts("error in allocating memory"); 
                exit(EXIT_FAILURE); 
            }

            *(cc_strdate + L) = '\0';
            strncpy(cc_strdate, str_date, L);

            char* str_day = strtok(cc_strdate, "-"); 
            char* str_month = strtok(NULL, "-"); 
            char* str_year = strtok(NULL, "-"); 

            day = atoi(str_day); 
            month = atoi(str_month); 
            year = atoi(str_year); 

            free(cc_strdate); 
            cc_strdate = NULL; 
        }

        void show(){
            printf("%d-%d-%d\n", day, month, year); 
        }
}; 

int main(void){
    Date cpaDate("28-02-2015"); 
    cpaDate.show(); 
    return 0; 
}