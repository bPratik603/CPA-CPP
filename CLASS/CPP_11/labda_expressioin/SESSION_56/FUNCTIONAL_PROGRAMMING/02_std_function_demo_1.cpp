#include <iostream> 
#include <functional> 

int my_add(int, int); 

int main(void) 
{
    // std::function; /* function template */

    std::function<int(int, int)> func_obj(my_add); 

    int result = func_obj(100, 200); 
    std::cout << "Result=" << result << std::endl; 

    return (0); 
}

int my_add(int a, int b)
{
    return a + b; 
}


/* Generalized syntax: 

ret_type fun_name(T1 v1, T2 v2, ...., Tn vn); 

ret_type(T1, T2, T3, ..., Tn); 

TYPE ANNOTATION. 


int my_add(int, int); 

int(int, int); 
*/

