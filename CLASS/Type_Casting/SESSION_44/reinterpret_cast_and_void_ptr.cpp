#include <cstdio> 
#include <typeinfo> 
#include <string> 

void generic_built_in_integer(void* p, const char* type_name); 

int main(void){
    unsigned char n1 = 0xff; 
    unsigned short n2 = 0xa0b0; 
    unsigned int n3 = 0xa0b0c0d0; 
    unsigned long n4 = 0xaabbccdd; 
    unsigned long long n5 = 0x1122334455667788; 

    generic_built_in_integer(
                                reinterpret_cast<unsigned char*>(&n1), 
                                typeid(n1).name()
                            ); 
    generic_built_in_integer(
                                reinterpret_cast<unsigned char*>(&n2), 
                                typeid(n2).name()
                            ); 
    generic_built_in_integer(
                                reinterpret_cast<unsigned char*>(&n3), 
                                typeid(n3).name()
                            ); 
    generic_built_in_integer(
                                reinterpret_cast<unsigned char*>(&n4), 
                                typeid(n4).name()
                            ); 
    generic_built_in_integer(
                                reinterpret_cast<unsigned char*>(&n5), 
                                typeid(n5).name()
                            ); 

    return 0; 
}

void generic_built_in_integer(void* p, const char* type_name){
    if(std::string(typeid(unsigned char).name()) == std::string(type_name))
        printf(
                "unsigned char:%hhx\n", 
                *reinterpret_cast<unsigned char*>(p)
            ); 
    else if(std::string(typeid(unsigned short).name()) == std::string(type_name))
        printf(
                "unsigned short:%hx\n", 
                *reinterpret_cast<unsigned short*>(p)
            ); 
    else if(std::string(typeid(unsigned int).name()) == std::string(type_name))
        printf(
                "unsigned int:%x\n", 
                *reinterpret_cast<unsigned int*>(p)
            ); 
    else if(std::string(typeid(unsigned long).name()) == std::string(type_name))
        printf(
                "unsigned long:%lx\n", 
                *reinterpret_cast<unsigned long*>(p)
            ); 
    else if(std::string(typeid(unsigned long long).name()) == std::string(type_name))
        printf(
                "unsigned long long:%llx\n", 
                *reinterpret_cast<unsigned long long*>(p)
            ); 
    else 
        printf("Unknown type"); 
}