// This code will explore validity and legality of various different 
// combinations available for writing formal parameters of 
// operator overloading member functions 

#include <cstdio> 

class Test_1
{
    public: 

        bool operator+(Test_1 t) 
        {
            puts("In Test_1::operator+"); 
            return true; 
        }
}; 

class Test_2
{
    public: 
        bool operator+(Test_2& t) 
        {
            puts("In Test_2::operator+"); 
            return true; 
        }
}; 

class Test_3 
{
    public: 
        bool operator+(Test_3* p_Test)
        {
            puts("In Test_3::operator+"); 
            return true; 
        }
}; 

void test1(void); 
void test2(void); 
void test3(void); 

int main(void)
{
    test1(); 
    test2(); 
    test3(); 

    return (0); 
}

void test1(void)
{
    bool ret; 
    Test_1 t1, t2; 
    Test_1 *p1 = new Test_1, *p2 = new Test_1; 
    Test_1** pp = &p1; 
    Test_1** pp2 = &p2; 

    ret = t1 + t2;      // 1 
    ret = *p1 + *p2;    // 2 
    ret = **pp + *p2;   // 3 
    ret = t1 + **pp2;   // 4 

    delete p1; 
    p1 = 0; 

    delete p2; 
    p2 = 0; 
}

/* 
    type(t1) == Test_1  ... annotated by programmer 
    type(&t1) == Test_1* 
*/

void test2(void)
{
    Test_2 t1, t2; 
    Test_2* p1 = new Test_2, *p2 = new Test_2; 
    Test_2** pp1 = &p1; 
    Test_2** pp2 = &p2; 
    bool ret; 

    ret = t1 + t2;      // 1  
    ret = *p1 + t2;     // 2 
    ret = **pp1 + t2;   // 3 

    ret = t1 + *p2;     // 4 
    ret = t1 + **pp2;   // 4 

    delete p1; 
    p1 = 0; 

    delete p2; 
    p2 = 0; 
} 

void test3(void)
{
    Test_3 t1, t2; 
    Test_3* p1 = new Test_3, *p2 = new Test_3; 
    bool ret; 

    ret = t1 + &t2; // 1 
    ret = *p1 + p2; // T OP T*  

   

    delete p1; 
    p1 = 0; 

    delete p2; 
    p2 = 0; 
}

