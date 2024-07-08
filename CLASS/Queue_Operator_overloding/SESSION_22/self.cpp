#include <iostream>
#include <cassert>

class CPA_int
{
    private:
      int N;
    
    public:
      CPA_int(int _N = 0) : N(_N)
      {}


    CPA_int operator+(const CPA_int& other) const
    {
        int sum = this->N + other.N;

        CPA_int sum_obj(sum);
        return(sum_obj);
    }

    CPA_int operator-(const CPA_int& other) const
    {
        return CPA_int(N - other.N);
    }

    CPA_int operator*(const CPA_int& other) const
    {
        return CPA_int(N * other.N);
    }
  
    CPA_int operator/(const CPA_int& other) const
    {
        assert(other.N != 0);
        return CPA_int(N / other.N);
    }

    CPA_int operator%(const CPA_int& other) const
    {
        return CPA_int(N % other.N);
    }

    CPA_int operator&(const CPA_int& other) const
    {
        return CPA_int(N & other.N);
    }

    CPA_int operator|(const CPA_int& other) const
    {
        return CPA_int(N | other.N);
    }

    CPA_int operator~()
    {
        return CPA_int(~N);
    }

    CPA_int operator>>(const CPA_int& other) const
    {
        return CPA_int(N >> other.N);
    }

    CPA_int operator<<(const CPA_int& other) const
    {
        return CPA_int(N << other.N);
    }

    CPA_int operator^(const CPA_int& other) const
    {
        return CPA_int(N ^ other.N);
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

    bool operator!=(const CPA_int& other) const
    {
        return (N != other.N);
    }

    bool operator==(const CPA_int& other) const
    {
        return (N == other.N);
    }

    CPA_int operator++()
    {
        ++this->N;

        return *this;
    }

    CPA_int operator++(int)
    {
        CPA_int tmp(this->N);
        this->N+= 1;

        return tmp;
    }

    CPA_int operator--(int)
    {
        CPA_int tmp(this->N);
        this->N-= 1;

        return tmp;
    }

    CPA_int operator--()
    {
        return CPA_int(--this->N);
    }
    void show(const char* msg)
    {
        if(msg)
          std::cout<<msg;

        std::cout<<this->N<<std::endl;
    }
};

int main(void)
{
    CPA_int result,t1(10),t2(3);
    bool res;

    t1.show("t1: ");
    t2.show("t2: ");

    std::cout<<"typeid(t1): "<<typeid(t1).name()<<std::endl;
    std::cout<<"typeid(t2): "<<typeid(t2).name()<<std::endl;
    std::cout<<"typeid(result): "<<typeid(result).name()<<std::endl;


    std::cout<<"Arithmatic operators : "<<std::endl;
    result = t1 + t2;
    result.show("operator+ ");

    result = t1 - t2;
    result.show("operator- ");

    result = t1 * t2;
    result.show("operator* ");

    result = t1 / t2;
    result.show("operator/ ");

    result = t1 % t2;
    result.show("operator% ");

    std::cout<<"Bitwise operators: "<<std::endl;
    result = t1 & t2;
    result.show("operator& ");

    result = t1 | t2;
    result.show("operator| ");

    result = ~t1;
    result.show("operator~ ");

    result = t1 >> t2;
    result.show("operator>>");

    result = t1 << t2;
    result.show("operator<<");

    result = t1 ^ t2;
    result.show("operator^");

    std::cout<<"Conditional operators: ";
    res = t1 > t2;
    std::cout<<res<<std::endl;

    res = t1 <t2;
    std::cout<<res<<std::endl;

    res = t1 >= t2;
    std::cout<<res<<std::endl;

    res = t1 <= t2;
    std::cout<<res<<std::endl;

    res = t1 != t2;
    std::cout<<res<<std::endl;

    res = t1 == t2;
    std::cout<<res<<std::endl;

     CPA_int X(100);

     result = X++;
     result.show("operatorX++ ");

     result = ++X;
     result.show("operator++X ");

     result = X--;
     result.show("operator--X ");

     result = --X;
     result.show("operatorX-- ");


}