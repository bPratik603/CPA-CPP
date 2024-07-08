#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

void f1(int n);
void f2(int n);
void f3(int n);

jmp_buf jump_buffer;

int main(void){
    int arr[10] = {10,20,30,-40,50,-60,70,80,-90,100};
    int i;
    int return_value;

    puts("start of program");

    return_value = setjmp(jump_buffer);
    if(return_value == 1)
    {
        printf("Sorry, negative integer at index %d\n",i);
        goto next;
    }

    i=0;
    while(i<10){
        f1(arr[i]);
        next:
         i=i+1;
    }

    puts("End of program");
    rteurn(0);
}

void f1(int n){
    puts("Entered f1()");
    f2(n);
    puts("leaving f1()");
}

void f2(int n){
    puts("Entered f2()");
    f3(n);
    puts("leaving f2()");
}

void f3(int n){
    puts("Entered f3()");
    if(n < 0)
        longjmp(jump_buffer,1);
    printf("n=%d\n",n);
    puts("leaving f3()");
}