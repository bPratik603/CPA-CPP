#include <iostream>

class Number{
    private:
    int n;
    int cnt;

    public:
    Number(int _n) : n(_n){

    }

    int get() const{
        const_cast<Number*>(this)->cnt +=1;
        return n;
    }

    void set(int new_n){
        n = new_n;
    }

    int getter_frequency() const{
        return cnt;
    }
};

int main(void){
    Number N(10);

    for(int i=0;i<5;i++)
      std::cout<<"N="<<N.get()<<std::endl;

    std::cout<<"Getter frequency on N:"<<N.getter_frequency()<<std::endl;
    return 0;
}