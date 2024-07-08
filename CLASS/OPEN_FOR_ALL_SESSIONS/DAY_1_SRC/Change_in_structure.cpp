// server side structure declaration / definition is done only once 

// S-v1
struct date{
    int dd; 
    int mm; 
    int yy; 
}; 


// struct definition is USED at varaious different places 
void f1(void){
    struct date d; 
    // C1-v1
    d.dd = 21; 
    d.mm = 12; 
    d.yy = 2010; 
}


// S-v2 
struct date{
    int day, month, year; 
}; 

void f1(void){
    struct date d; 
    // C1-v1
    d.dd = 21;      // error : dd not present 
    d.mm = 12;      / error : mm not present 
    d.yy = 2010;    // error : yy not present 
}

// C1-v1 IS NOT COMPATIBLE WITH S-v2 