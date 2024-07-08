#include <cstdio> 

class Date{
    private: 
        int day, month, year; 
    public: 
    // initialization by initializer list 
        Date(int init_day, int init_month, int init_year) : day(init_day), 
                                                            month(init_month), 
                                                            year(init_year) 
        {
            printf("In Date::Date():this==%p\n", this); 
            printf("Initialization data:%d, %d, %d\n", init_day, init_month, init_year); 
        }

        void show(){
            printf("%d-%d-%d\n", day, month, year); 
        }
}; 

int main(void){
    Date d1(1, 1, 1970); 
    Date d2(28, 2, 2015); 

    printf("&d1=%p, &d2=%p\n", &d1, &d2); 
    d1.show(); 
    d2.show(); 

    return 0; 
}

/*
    Generalization of initializer syntax 

    class T{
        private: 
            T1 mem1; 
            T2 mem2; 

            Tk memk; 

        public: 
            T(T1 init_1, ..., Tm init_m) :  mem1(expr->T1), 
                                            mem2(expr->T2), 

                                            memr(expr->Tr)
            {
                // other stuff if required 
                // otherwise keep empty 
            }

    }; 
*/

const int n = 10; 