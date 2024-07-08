#include <cstdio> 
#include <cstdlib> 

namespace X{
    int n; 

    void sort(int* a, int n){
        int i, j; 
        int key; 

        for(j = 1; j < n; ++j){
            key = a[j]; 
            i = j - 1;
            while(i > -1 && a[i] > key){
                a[i+1] = a[i]; 
                i = i - 1; 
            }
            a[i+1] = key; 
        }
    }

    void show(int* a, int n, const char* msg){
        if(msg){
            puts(msg); 
        }

        int i; 
        for(i = 0; i < n; ++i)
            printf("a[%d]:%d\n", i, a[i]); 
    }

    class Date{
        private: 
            int day, month, year; 
        public: 
            Date(int _day, int _month, int _year) : day(_day), 
                                                    month(_month), 
                                                    year(_year){

            }

            void show(){
                printf("%d/%d/%d\n", day, month, year); 
            }
    };

    namespace Y{
        class Test{
            public: 
                Test(){
                    puts("In Test::Test()"); 
                }

                void f(){
                    puts("In Test::f()"); 
                }
        }; 
    } 
}

void test_namespace_1(void); 
void test_namespace_2(void); 
void test_namespace_3(void); 

int main(void){
    test_namespace_1(); 
    test_namespace_2(); 
    return EXIT_SUCCESS;  
}

void test_namespace_1(void){
    puts("In test_namspace_1():"); 
    ::X::n = 40; 
    printf("X::n=%d\n", X::n); 

    X::Date independenceDay(15, 8, 1947); 
    independenceDay.show(); 

    int a[] = {50, 40, 30, 20, 10}; 
    X::show(a, 5, "Before sort:"); 
    X::sort(a, 5);
    X::show(a, 5, "After sort:");

    ::X::Y::Test t; 
    t.f();  
}

void test_namespace_2(void){
    puts("In test_namespace_2():"); 
    using namespace X; 
    n = 40; 
    printf("n = %d\n", n); 
    
    Date independenceDay(15, 8, 1947); 
    independenceDay.show(); 

    int a[] = {50, 40, 30, 20, 10}; 
    show(a, 5, "Before sort:"); 
    sort(a, 5);
    show(a, 5, "After sort:");

    Y::Test t; 
    t.f();  

}

void test_namespace_3(void){
    puts("In test_namspace_3():"); 
    using X::Date; 
    using X::Y::Test; 
    
    ::X::n = 40; 
    printf("X::n=%d\n", X::n); 

    Date independenceDay(15, 8, 1947); 
    independenceDay.show(); 

    int a[] = {50, 40, 30, 20, 10}; 
    X::show(a, 5, "Before sort:"); 
    X::sort(a, 5);
    X::show(a, 5, "After sort:");

    Test t; 
    t.f();    
}