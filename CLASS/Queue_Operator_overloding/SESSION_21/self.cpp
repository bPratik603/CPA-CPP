#include <iostream>
#include <cassert>
#include <typeinfo>

class CPA_int
{
    private:
       int N;

    public:
       CPA_int(int _n = 0) : N(_n){}

       CPA_int operator+(const CPA_int& other) const
       {
             std::cout<<"In CPA_int::operator+():"<<std::endl;
             int result = this->N + other.N;

             CPA_int sum_obj(result);
             return(sum_obj);
       }

       CPA_int operator-(const CPA_int& other) const
       {
           return CPA_int(this->N - other.N);
       }

       CPA_int operator*(const CPA_int& other) const
       {
           return CPA_int(this->N * other.N);
       }
     
       CPA_int operator/(const CPA_int& other) const
       {
          assert(other.N != 0);
          return CPA_int(N / other.N);
       }

       CPA_int operator%(const CPA_int& other) const
       {
          assert(other.N != 0);
          return CPA_int(N % other.N);
       }

       CPA_int operator<<(const CPA_int& other) const
       {
          return CPA_int(N << other.N);
       }

       CPA_int operator>>(const CPA_int& other) const
       {
        return CPA_int(N >> other.N);
       }

       CPA_int operator&(const CPA_int& other) const
       {
          return CPA_int(N & other.N);
       }

       CPA_int operator|(const CPA_int& other) const
       {
          return CPA_int(N | other.N);
       }

       CPA_int operator^(const CPA_int& other) const
       {
        return CPA_int(N ^ other.N);
       }

       CPA_int operator~() const
       {
        return CPA_int(~N);
       }

        bool operator>(const CPA_int& other) const
       {
         return (N > other.N);
       }

       bool operator<(const CPA_int& other) const
       {
        return (N < other.N);
       }

       bool operator>=(const CPA_int& other) const
       {
        return (N >= other.N);
       }

       bool operator<=(const CPA_int& other) const
       {
        return (N <= other.N);
       }

       bool operator==(const CPA_int& other) const
       {
        return(N == other.N);
       }

       bool operator!=(const CPA_int& other) const
       {
        return (N != other.N);
       }

       double flt_div(const CPA_int& other) const
       {
          assert(other.N != 0);
          return(((double)N) / other.N);
       }
     void show(const char* msg)
     {
        if(msg)
          std::cout<<msg;

        std::cout<<this->N;
     }
};

int main(void)
{
    CPA_int t1(10),t2(3),result;

    t1.show("n1:");
    t2.show("n2:");
    result = t1 + t2;
    result.show("Summation:");

    std::cout<<"type(n1):"<<typeid(t1).name()<<std::endl;
    std::cout<<"type(n2):"<<typeid(t2).name()<<std::endl;
    std::cout<<"type(result):"<<typeid(result).name()<<std::endl;

    result = t1 - t2;
    result.show("substraction");

    result = t1 * t2;

    result = t1 / t2;
    result = t1 % t2;

    result = t1 & t2;
    result = t1 | t2;
    result = t1 << t2;
    result = t1 >> t2;
    result = t1 ^ t2;
    result = ~t1;

    bool res;

    res = t1 > t2;
    res = t1 >= t2;
    res = t1 < t2;
    res = t1 <= t2;
    res = t1 == t2;
    res = t1 != t2;
    

}