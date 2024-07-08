#include <cstdio> 

class IBuiltinInteger{
    public: 
        virtual void show() = 0; 
}; 

class uint8 : public IBuiltinInteger{
    private: 
        unsigned char n; 
    public: 
        uint8(unsigned char _n=0x0) : n(_n){

        }

        void show(){
            printf("%hhx:\n", n); 
        }
}; 

class uint16 : public IBuiltinInteger{
    private: 
        unsigned short n; 
    public: 
        uint16(unsigned short _n=0x0) : n(_n){

        }

        void show(){
            printf("%hx:\n", n); 
        }
}; 

class uint32 : public IBuiltinInteger{
    private: 
        unsigned int n; 
    public: 
        uint32(unsigned int _n=0x0) : n(_n){

        }

        void show(){
            printf("%x:\n", n); 
        }
}; 

class uint64 : public IBuiltinInteger{
    private: 
        int flag; 
        unsigned long n1; 
        unsigned long long int n2; 
    public: 
        uint64(unsigned long _n=0x0) : n1(_n){
            flag = 1; 
        }

        uint64(unsigned long long _n=0x0) : n2(_n){
            flag = 2; 
        }

        void show(){
            if(flag == 1)
                printf("%lx:\n", n1);
            else if(flag == 2)
                printf("%llx:\n", n2);  
        }
}; 

void show_built_in_integer(IBuiltinInteger* pIBuiltinInteger); 

int main(void){
    uint8 u8(0xff);
    uint16 u16(0xa0b0); 
    uint32 u32(0xa0b0c0d0); 
    uint64 u64_1(0xaabbccddUL); 
    uint64 u64_2(0x1122334455667788ULL); 

    show_built_in_integer(&u8); 
    show_built_in_integer(&u16); 
    show_built_in_integer(&u32); 
    show_built_in_integer(&u64_1); 
    show_built_in_integer(&u64_2); 

    return 0; 
}

void show_built_in_integer(IBuiltinInteger* pIBuiltinInteger){
    pIBuiltinInteger->show(); 
}