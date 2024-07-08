#include <cstdio>
#include <typeinfo>
#include <string>

void generic_built_in_intger(void* p,const char* type_name);

int main(void){
    unsigned char n1 = 0xff;
    unsigned short n2 = 0xa0b0;
    unsigned int n3 = 0xa0b0c0d0;
    unsigned long n4 = 0xaabbccdd;
    unsigned long long n5 = 0x1122334455667788;

    generic_built_in_intger(
                              reinterpret_cast<unsigned char*>(&n1),
                              typeid(n1).name()
                           );
    
    generic_built_in_intger(
                            reinterpret_cast<unsigned short*>(&n2),
                            typeid(n2).name()
                        );
    
    generic_built_in_intger(
                             reinterpret_cast<unsigned int*>(&n3),
                             typeid(n3).name()
                           );

    generic_built_in_intger(
                           reinterpret_cast<unsigned long*>(&n4),
                           typeid(n4).name()
                        );

    generic_built_in_intger(
                             reinterpret_cast<unsigned long long*>(&n5),
                             typeid(n5).name()
                            );

    return 0;
}

void generic_built_in_intger(void* p,const char* type_name){
    if(std::string(typeid(unsigned char).name()) == std::string(type_name))
    {
       printf("unsigned char:%hhx\n",
              *reinterpret_cast<unsigned char*>(p));
    }

    else if(std::string(typeid(unsigned short).name()) == std::string(type_name))
    {
        printf("unsigned short:%hhx\n",
              *reinterpret_cast<unsigned short*>(p));
    }

    else if(std::string(typeid(unsigned int).name()) == std::string(type_name))
    {
        printf("unsigned int:%hhx",
               *reinterpret_cast<unsigned int*>(p));
    }

    else if(std::string(typeid(unsigned long).name()) == std::string(type_name))
    {
        printf("unsigned long:%hhx",
               *reinterpret_cast<unsigned long*>(p));
    }

    else if(std::string(typeid(unsigned long long).name()) == std::string(type_name))
    {
        printf("unsigned long long:%hhx",
               *reinterpret_cast<unsigned long long*>(p));
    }
}


void f(reinterpret_cast<unsigned char*>(n1),typeid(n1).name);

void f(void* p,const char* msg)
{
    if(std::string(typeid(unsigned char*).name()) == std::string(msg))
    {
        printf("unsigned char:%hhx",*reinterpret_cast<unsigned char*>(p));
    }
}