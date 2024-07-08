#include <iostream> 
#include <cassert> 

class Date{
    private: 
        int day, month, year; 
    public: 
        Date() : day(1), month(1), year(1970){

        }

        void show(const char* msg){
            std::cout   << msg << std::endl << day << "-" 
                        << month << "-" << year << std::endl; 
        }
}; 

Date& get_date(void); 

int main(void){
    Date myDate; 

    myDate.show("myDate.show()"); 
    Date* pDate = new Date; 
    pDate->show("pDate->show()"); 

    Date& refDate = *(new Date); 
    refDate.show("refDate.show()"); 

    delete pDate; 
    pDate = 0; 

    delete &refDate; 

    return 0; 
} 

//Date& get_date(void){

//}


//  int num; 
//  int& n = num; 

//  Let T be any data type in program source 
//  T& ref = expr which evaluates to type T 

//  Date myDate; 
//  Date& x = myDate; 
//  Date* pDate = new Date; 
//  type(pDate) == Date*, type(*pDate) == Date
//  Date& y = *pDate; 
//  Date& z = *(new Date); 

/*

// wrong -> dangling ref 
Date& get1(){
    Date myDate; 
    return (myDate); 
}

// ok : but not good if you want to write 
// thread safe code 
Date& get2(){
    static Date myDate; 
    return myDate; 
}

Date& get3(){
    Date* pDate = new Date; 
    assert(pDate); 
    return (*pDate); 
}

void test_get_calls(){
    Date& r1 = get1(); 
    Date& r2 = get2(); 
    // Date& r = <expr>; 
}

*/
