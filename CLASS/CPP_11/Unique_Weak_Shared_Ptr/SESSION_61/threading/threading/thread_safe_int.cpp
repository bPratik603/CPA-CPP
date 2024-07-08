#include <pthread.h> 

typedef union int_type{
    char c_mem;
    unsigned char uc_mem; 
    short s_mem; 
    unsigned short us_mem; 
    int i_mem; 
    unsigned int ui_mem; 
    long int li_mem; 
    unsigned long int uli_mem; 
    long long int lli_mem; 
    unsigned long long int ulli_mem; 
}integer_t;

typedef enum tag_INT_TYPE_CONSTANTS{
    CHAR=0, 
    UNSIGNED_CHAR, 
    SHORT, 
    UNSIGNED_SHORT, 
    INT, 
    UNSIGNED_INT, 
    LONG, 
    UNSIGNED_LONG, 
    LONGLONG,
    UNSIGNED_LONGLONG 
}INT_TYPE_CONSTANTS; 

class thread_safe_int{
    private: 
        integer_t data;
        INT_TYPE_CONSTANTS int_type_choice;  
        pthread_mutex_t mu_lck; 
    public: 
        thread_safe_int(INT_TYPE_CONSTANTS choice) : int_type_choice(choice){
            pthread_mutex_init(&mu_lck, NULL); 
        }

        void operator++(){
            pthread_mutex_lock(&mu_lck); 
            switch(int_type_choice){
                case CHAR:
                    ++data.c_mem; 
                    break; 
                case UNSIGNED_CHAR: 
                    ++data.uc_mem; 
                    break; 
                case SHORT: 
                    ++data.s_mem; 
                    break; 
                case UNSIGNED_SHORT: 
                    ++data.us_mem; 
                case INT: 
                    ++data.i_mem; 
                    break; 
                case UNSIGNED_INT:
                    ++data.ui_mem; 
                    break; 
                case LONG: 
                    ++data.li_mem; 
                    break; 
                case UNSIGNED_LONG: 
                    ++data.uli_mem; 
                    break; 
                case LONGLONG: 
                    ++data.lli_mem; 
                    break; 
                case UNSIGNED_LONGLONG: 
                    ++data.ulli_mem; 
                    break; 
            }
            pthread_mutex_unlock(&mu_lck); 
        }

}; 

thread_safe_int tsi(INT); 

void* common_thread_function(void* args){
    ++tsi; 
}