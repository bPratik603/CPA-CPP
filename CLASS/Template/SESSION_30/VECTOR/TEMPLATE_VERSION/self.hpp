#ifndef SELF_H
#define SELF_H

#include <iostream>
#include <cassert>

typedef long long ssize_t;

template <typename T>
class Vector {
    private:
      T* arr;
      ssize_t N;

    public:
      Vector() : arr(0),N(0)
      {}

     void push_back(const T& ele)
     {
        arr = (T*)realloc((void*)arr,(N+1) * sizeof(T));
        assert(arr != 0);
        N+=1;
        arr[N-1] = ele;
     }

    ~Vector{
        delete[] arr;
        arr = 0;
        N = 0;
            }

    friend std::ostream& operator<<(std::ostream& os,const Vector<T>& vec)
    {
        for(ssize_t i=0;i!=vec.N;++i)
           os<<"vector["<<i<<"]: "<<vec.arr[i]<<std::endl;
           return os;
    }
};

#endif