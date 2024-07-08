#ifndef _SORT_H 
#define _SORT_H 

#include <iostream> 

typedef long long ssize_t; 

template <typename T> 
void insertion_sort(T* arr, ssize_t N){
    ssize_t i, j; 
    T key; 

    for(j = 1; j < N; ++j){
        key = arr[j]; 
        i = j - 1; 
        while(i > -1 && arr[i] > key){
            arr[i+1] = arr[i]; 
            i = i - 1; 
        }
        arr[i+1] = key; 
    }
}

template <typename T> 
void show_array(T* arr, ssize_t N, const char* msg=0){
    if(msg)
        std::cout << msg << std::endl; 
    for(ssize_t i = 0; i != N; ++i)
        std::cout << "arr[" << i << "]:" << arr[i] << std::endl; 
}

#endif // _SORT_H 