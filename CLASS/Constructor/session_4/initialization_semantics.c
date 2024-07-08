int n = 10; 
int main(void){
    printf("n = %d\n", n); 
}

////////////////////////////

int n; 
int main(void){
    n = 10; 
    printf("n = %d\n", n); 
}

/////////////////////////

struct Date{
    int day, month, year
}myDate = { 
            1, 
            1, 
            1970
        };

struct Date cpaDate; 

int main(void){
    cpaDate.day = 28; 
    cpaDate.month = 2; 
    cpaDate.year = 2015; 
}

/////////////////////////////

const int n = 10; 

const int n; 

void f(){
    n = 10; 
}

void g(){
    n = 20; 
}

/////////////////////////////
