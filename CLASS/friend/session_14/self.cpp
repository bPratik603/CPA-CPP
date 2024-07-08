#include<iostream>

class Test
{
    private:
      int a;
      float b;
      char c;
    
    public:
      friend void some_fun(void);
      friend class c2;

      Test() : a(0),b(7.14),c('A'){

      }
};

class c1{
    public:
    Test t1;

    void fun1(void)
    {
        //std::cout<<t1.a;
        //std::cout<<t1.b;
        //std::cout<<t1.c;
    }

    void fun2(void){
        //std::cout<<t1.a;
        //std::cout<<t1.b;
        //std::cout<<t1.c;
    }
};

class c2{
    public:
    Test t1;

    void fun1(void){
        std::cout<<t1.a<<std::endl;
        std::cout<<t1.b<<std::endl;
        std::cout<<t1.c<<std::endl;
    }

    void fun2(void){
        std::cout<<t1.a;
        std::cout<<t1.b;
        std::cout<<t1.c;
    }
};

void some_fun(void){
    Test t1;

    std::cout<<t1.a;
    std::cout<<t1.b;
    std::cout<<t1.c;
}

int main(void){
    Test t;

    some_fun1();
    some_fun2();

    

    some_fun();

    return(0);
}

void some_fun1(void){
    c1 c;
    c.fun1();
    c.fun1();
}

void some_fun2(void){
    c2 c;
    c.fun1();
    c.fun2();
}