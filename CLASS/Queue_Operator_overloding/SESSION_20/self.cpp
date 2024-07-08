#include <iostream>

class test
{
    public:
    int N;

    test(int _N = 0) : N(_N)
    {

    }

    test& operator+(test other)
    {
        int sum = this->N + other.N;

        test* sum_obj = new test(sum);

        return(*sum_obj);
    }
};

int main(void)
{
    test t1(1),t2(2);

    test& t3 = t1 + t2;

    std::cout<<t3.N;

    delete &t3;
    t3 = 0;
}