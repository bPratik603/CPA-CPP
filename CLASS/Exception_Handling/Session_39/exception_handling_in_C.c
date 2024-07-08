/* 
    array 10 of integers: it will contain positive and negative integers 
    negative integer is undesirable condition 

    main() function iterates through array, passes each element of array 
    to f1() by calling it. 
    f1() passes the same element to f2() by calling it 
    f2() passes the same element to f3() by calling it. 

    f3() checks for the sign of integer. If it is positive or 0 
    then it prints the integer. But if its negative then it wants 
    to report an error. But there is no use to report an error 
    to f2(), or f1() because f2() is simply passing on the data 
    recevied from f1() and f1() likewise from main() 

    Therefore, there must be a way to directly report the error to the main 
    function. 

    Is it possible to do so in C? 
    If yes, How? 
    This code will explain. 
*/

#include <stdio.h> 
#include <stdlib.h> 
#include <setjmp.h> 

void f1(int n); 
void f2(int n); 
void f3(int n); 

jmp_buf jump_buffer; 

int main(void){
    int arr[10] = {10, 20, 30, -40, 50, -60, 70, 80, -90, 100}; 
    int i; 
    int return_value; 

    puts("start of program"); 

    return_value = setjmp(jump_buffer); 
    if(return_value == 1){
        printf("Sorry, negative integer at index %d\n", i); 
        goto next; 
    }

    i = 0; 
    while(i < 10){
        f1(arr[i]);
    next: 
        i = i + 1; 
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
    puts("entered f3()"); 
    if(n < 0)
        longjmp(jump_buffer, 1); 
    printf("n = %d\n", n); 
    puts("leaving f3()"); 
}

