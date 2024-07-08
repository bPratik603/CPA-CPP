#include <cstdio> 

// SERVER 
class Date{
    private: 
        int day, month, year; 

    public: 
        Date(int init_day, int init_month, int init_year){
            printf("Intializing newly created Date object at: %p\n", this); 
            printf("Initialization data:%d, %d, %d\n", init_day, init_month, init_year); 
           
            // initialization by explicit assignment 
            day = init_day; 
            month = init_month; 
            year = init_year; 
        }

        void show(){
            printf("%d-%d-%d\n", day, month, year); 
        }
}; 

// CLIENT
int main(void){
    Date d1(1, 1, 1970);    // Date::Date(&d1, 1, 1, 1970)
    Date d2(28, 2, 2015);   // Date::Date(&d2, 28, 2, 2015)

    printf("&d1=%p, &d2=%p\n", &d1, &d2); 

    d1.show(); 
    d2.show(); 

    return (0); 
}

/* 
    class T : (DOCUMENTATION )

    T(T1, T2, T3, ..., Tn)

    CLIENT 

    T var(objT1, objT2, ..., objTn); 

*/

/* 
    Application of general principle: 

    Let T be a class. 
    Let objT be an object of class T. 

    CLIENT DESIRE: 

    Tr ret = objT.func(data_t1, data_t2, ..., data_tn); 
    // DESIRED BEHVAIOUR 

    SERVER SIDE RESPONSIBILITY 

    class T{
        private: 
            T1 mem1; 
            T2 mem2; 

            Tm mem_m;
        public: 
            Tr func(t1 p1, t2 p2, ...., tn pn){
                // Write an algorithm to yield 
                // desired behaviour 
                // algorithm can act on follow data 
                // p1:t1, p2:t2, ..., pn:tn 
                // members of calling object 
                // this->mem1, this->mem2, ..., this->memn 
            }
    }; 

*/

