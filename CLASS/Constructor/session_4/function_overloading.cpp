#include <cstdio> 
#include <cstdlib> 

struct Date{
    int day; 
    int month; 
    int year; 
}; 

void init_date(struct Date* pDate, int day, int month, int year); 
void init_date(struct Date* pDate, const char* str_date); 

int main(void){
    struct Date cpaDate; 

    init_date(&cpaDate, 28, 2, 2015); 
    init_date(&cpaDate, "28-2-2015"); 

    return 0; 
}

void init_date(struct Date* pDate, int day, int month, int year){
    puts("Initialization using three integer values"); 
}

void init_date(struct Date* pDate, const char* str_date){
    puts("Initialization using string"); 
}

