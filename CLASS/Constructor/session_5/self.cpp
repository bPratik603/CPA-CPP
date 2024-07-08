#include<iostream>
#include<cstdio>

namespace X
{
    int n;

    void sort(int* p_arr,int n)
    {
        int i,j,tmp;
        for(j=1;j<n;j++)
        {
            tmp = p_arr[j];
            i = j-1;

            while(i > -1 && p_arr[i] > tmp)
            {
                p_arr[i+1] = p_arr[i];
                i = i-1;
            }

            p_arr[i+1] = tmp;
        }
    }

    class Date
    {
        private:
          int day,month,year;

        public:
           Date(int init_day,int init_month,int init_year) : day(init_day),month(init_month),year(init_year)
           {

           }

        void show()
        {
            printf("%d-%d-%d\n",day,month,year);
        }
    };

    void show(int* p_arr,int n,const char* msg)
    {
        puts(msg);
        int i;
        for(i=0;i<n;i++)
        {
            printf("p_arr[%d] : %d\n",i,p_arr[i]);
        }
    }

    namespace Y
    {
        class Test
        {
            public:

            Test()
            {
                puts("inside Test() : ");
            }

           void f()
            {
                puts("inside f() : ");
            }
        };
    }
}


void test_function_1(void);
void test_function_2(void);
void test_function_3(void);

int main(void)
{
    test_function_1();
    test_function_2();
    test_function_3();
    
}

void test_function_1(void)
{
    X::n = 40;
    printf("X::n = %d\n",X::n);

    X::Date myDate(1,1,2023);
    myDate.show();

    int arr[] = {50,40,30,20,10};
    X::show(arr,5,"Before sort : ");
    X::sort(arr,5);
    X::show(arr,5,"After sort : ");

     X::Y::Test t;
     t.f();
}

void test_function_2(void)
{
    puts("inside test_function_2()");
    using namespace X;

    n = 40;
    printf("X::n = %d\n",n);

    Date myDate(1,1,2023);
    myDate.show();

    int arr[] = {50,40,30,20,10};
    show(arr,5,"Before sort");
    sort(arr,5);
    show(arr,5,"After show");

    Y::Test t;
    t.f();
} 

void test_function_3(void)
{
    puts("inside test_function_3");

    using X::Date;
    using X::Y::Test;

    X::n = 40;
    printf("X::n = %d\n",X::n);

    Date myDate(1,1,2023);
    myDate.show();

    int arr[] = {50,40,30,20,10};
    X::show(arr,5,"Before sort : ");
    X::sort(arr,5);
    X::show(arr,5,"After sort : ");

    Test t;
    t.f();
} 