#include <cstdio> 

class C{
    private: 
        int a; 
        char b; 
        float c; 
    public: 
        int d; 
        
        void test_func(){
            printf("a=%d, b=%c, c=%.3f\n", this->a, this->b, this->c); 
        }

        void set_float(float new_val){
            c = new_val; 
        }

}; 

/* 
    struct C{
        int a; 
        char b; 
        float c; 
    };

    struct C inC;
    inC.a; 
    inC.b
    inC.c 

*/

int main(void){
    C objC; 
    // objC.a = 100;    // CTE: because a is private
    objC.d = 200;       // OK: because d is public
    objC.test_func();   
    objC.set_float(9.99);   

    // C::set_float(&objC, 9.99); 
    return 0; 
}

// objT.member_func(p1, p2, ...pn) 
// T::member_func(&objT, p1, p2, ..., pn)

// class T{

//    public: 
//       void member_func(T* this, T1 p1, ..., Tn pn){

//      }
//}