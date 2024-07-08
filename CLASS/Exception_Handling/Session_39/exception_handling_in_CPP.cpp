#include <iostream> 
#include <stdexcept> 
#include <string> 
#include <cstring> 
#include <stdlib.h> 

void f1(int n); 
void f2(int n); 
void f3(int n); 

int main(void){
    int a[10] =  {10, 20, 30, -40, 50, -60, 70, 80, -90, 100};
    int i; 

     for(i = 0; i < 10; ++i)
        try{
            f1(a[i]); 
        }catch(std::runtime_error& ref){
            std::cout << ref.what() << std::endl; 
        }

    puts("End of program"); 
    return (0); 
}

void f1(int n){
    puts("entered f1()");
    f2(n); 
    puts("leaving f1()");  
}

void f2(int n){
    puts("entered f2()"); 
    f3(n); 
    puts("leaving f2()"); 
}

void f3(int n){
    char buffer[16]; 
    puts("entered f3()"); 
    if(n < 0){
        memset((void*)buffer, 0, 16); 
        sprintf(buffer, "%d", n); 
        std::string s1 = "Negative Number Was Encountered=" + std::string(buffer); 
        throw std::runtime_error(s1.c_str()); 
    }
    printf("n = %d\n", n); 
    puts("leaving f3()"); 
}