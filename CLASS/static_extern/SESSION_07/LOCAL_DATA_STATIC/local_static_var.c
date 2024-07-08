void test(void){
    int m; 
    static int n; 
}

/* 
    local variable: 
        i)  allocation time : dynamic (after call to a function)
        ii) allocation strategy :  per function call 
        iii) lifetime : bound to a lifetime of function 
        iv) visibility : bound to a function containing definition statement 
        v)  allocation section in vritual address space : stack section 

    local-static variable: 
        i) allocation time: static (while building the exe) 
        ii) allocation strategy: allocate one copy (shared amongst all function calls)
        iii) lifetime:  
        iv) visibility:
        v) allocation section in virtual address space:  

*/