// function will be defined only once

// Server v1 
void sort(int *a, int n){
    // insertion sort 

    int i, j, key; 

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

// C1-v1
void f1(void){
    int A1[N1] = {// init values}; 
    sort(A1, N1); 
}

// C2-v1
void f2(void){
    int A2[N2] = {}; 
    sort(A2, N2); 
}

//C3-v1
void f3(void){
    int A3[N3]; 
    sort(A3, N3); 
} 


// server V2 
void sort(int *a, int n){
    // insertion sort 
    // logic of quick_sort here 
}

// C1-v1
void f1(void){
    int A1[N1] = {// init values}; 
    sort(A1, N1); 
}

// C2-v1
void f2(void){
    int A2[N2] = {}; 
    sort(A2, N2); 
}

//C3-v1
void f3(void){
    int A3[N3]; 
    sort(A3, N3); 
} 

// C1-v1, C2-v1, C3-v1 ARE COMPATIBLE WITH S-V2 

