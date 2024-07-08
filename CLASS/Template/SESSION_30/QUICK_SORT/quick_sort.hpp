#ifndef _SORT_H 
#define _SORT_H 

#include <iostream> 

typedef long long ssize_t; 

template <typename T> 
void show_array(T* arr, ssize_t N, const char* msg=0){
    if(msg)
        std::cout << msg << std::endl; 
    for(ssize_t i = 0; i != N; ++i)
        std::cout << "arr[" << i << "]:" << arr[i] << std::endl; 
}

template <typename T>
void sort(T* a, ssize_t N)
{
    quick_sort<T>(a, 0, N-1); 
}

template <typename T>
ssize_t partition(T* a, ssize_t p, ssize_t r)
{
    T pivot, tmp; 
    ssize_t i, j;

    pivot = a[r]; 
    i = p - 1; 
    for(j = p; j < r; ++j)
    {
        if(a[j] <= pivot)
        {
            i = i + 1; 
            tmp = a[i]; 
            a[i] = a[j]; 
            a[j] = tmp; 
        }
    }

    tmp = a[r]; 
    a[r] = a[i+1]; 
    a[i+1] = tmp; 

    return (i+1); 
}

template <typename T>
void quick_sort(T* a, ssize_t p, ssize_t r)
{
    ssize_t q; 

    if(p < r)
    {
        q = partition<T>(a, p, r); 
        quick_sort<T>(a, p, q-1); 
        quick_sort<T>(a, q+1, r); 
    }
}


#endif // _SORT_H 
