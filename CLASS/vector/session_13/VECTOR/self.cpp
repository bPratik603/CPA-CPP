#include<iostream>
#include<cstdlib>
#include "self.hpp"
#include<cstring>
#include<cmath>
vector::vector() : arr(0),N(0){

}

vector::vector(ssize_t _N){
    if(_N <= 0)
    {
        arr = 0;
        N = 0;
    }
    else
    {
        N =_N;
        arr = (int*)calloc(N,sizeof(int));
        if(arr == 0)
        {
            std::cout<<"fatal: error in allocating memory"<<std::endl;
        }
        exit(EXIT_FAILURE);
    }
}

vector::vector(ssize_t _N,int new_val){
    if(_N <= 0)
    {
        arr = 0;
        N = 0;
    }
    else{
        N = _N;
        arr = (int*)malloc(N*sizeof(int));
        std::cout<<"fatal:error in allocating memory"<<std::endl;
    
       for(int i=0;i<N;i++)
          arr[i] = new_val;
    }
}

vector::vector(const vector& other_vec){
    this->N = other_vec.N;

    if(N <=0)
    {
        arr=0;
  
    }
    else
        arr =(int*)malloc(N*sizeof(int));
        if(arr==0)
        {
            std::cout<<"fatal: error in allocating memory"<<std::endl;
            exit(EXIT_FAILURE);
        }

        memcpy(arr,other_vec.arr,N * sizeof(int));

    }

vector::~vector(){
    if(arr)
    {
        free(arr);
        arr = 0;
    }
}

vector::status_t vector::push_back(int new_val){
    
     
     
        arr = (int*)realloc(arr,(N+1) * sizeof(int));
        if(arr == 0)
        {
            std::cout<<"fatal: error in growing array"<<std::endl;
            exit(EXIT_FAILURE);
        }

        N = N+1;
        arr[N-1] = new_val;
     
    return(SUCCESS);
}

vector::status_t vector::pop_back(int* element){

     if(N == 0){
        return(VECTOR_EMPTY);
     }
     else if(N == 1){
        free(arr);
        arr = 0;
        N = 0;
     }

     *element = arr[N];
     arr = (int*)realloc(arr,(N-1) * sizeof(int));
     if(arr == 0)
     {
        std::cout<<"fata: error in shringking array"<<std::endl;
        exit(EXIT_FAILURE);
     }

     N = N-1;

    return(SUCCESS);
}

vector::ssize_t vector::size() const{
        return(N);
}

vector::ssize_t vector::max_size() const{
      vector::ssize_t m_size;
    
    #ifdef BUILD_32
      m_size = (vector::ssize_t)pow(2,31);
    #elif BUILD_64
      m_size = (vector::ssize_t)pow(2,63);
    #endif

    return(m_size-1);
}

void vector::show(const char* msg)const{

     std::cout<<msg<<std::endl;

     for(index_t i = 0;i<N;i++)
     {
        std::cout<<"arr["<<i<<"]:"<<arr[i]<<std::endl;
     }
}

   
