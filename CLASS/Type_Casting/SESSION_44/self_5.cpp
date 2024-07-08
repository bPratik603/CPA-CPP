#include <cstdio>

class IBuiltinInteger{
    public:
     virtual void show() = 0;
};

class uint8 : public IBuiltinInteger{
    private:
     unsigned char n;

    public:
     uint8(unsigned char _n = 0x0) : n(_n){

     }

     void show(){
        printf("%hhx:\n",n);
     }
};

class uint16 : public IBuiltinInteger{
   private:
     unsigned short n;
   public:
     uint16(unsigned short _n = 0x0) : n(_n){}

     void show(){
        printf("%hx:\n",n);
     }
};

class uint32 : public IBuiltinInteger{
    private:
    unsigned int n;
    public:
    uint32(unsigned int _n = 0x0) : n(_n){}

    void show(){
        printf("%hx:\n",n);
    }
};

class uint64 : public IBuiltinInteger{
    private:
    unsigned long n;
    unsigned long long nn;
    int flag;
    public:
    uint64(unsigned long _n = 0x0) : n(_n) {flag = 1;}
    uint64(unsigned long long _nn = 0x0) : n(_nn){flag = 2;}

    void show(){
        if(flag = 1)
          printf("%lx:\n",n);
        else if(flag = 2)
          printf("%llx:\n",nn);
    }
};

void show_built_in_integer(IBuiltinInteger* pIBuilt_inInteger);

int main(void){

}

void show_built_in_integer(IBuiltinInteger* pIBuilt_inInteger)
{
    pIBuilt_inInteger->show();
}