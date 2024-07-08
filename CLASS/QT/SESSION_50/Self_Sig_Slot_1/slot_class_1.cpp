#include "slot_class_1.h"
#include "slot_class_1.h"
#include <iostream>
slot_class_1::slot_class_1(std::string _s1) : s1(_s1)
{}

void slot_class_1::sig_1_handler(int num){
    std::cout<<"slot for signal named: void sig1(int) in TestClass"<<std::endl;
    std::cout<<"I am object of the class:"<<typeid(*this).name()<<std::endl;
    std::cout<<"My address is:"<<std::hex<<this<<std::endl;
    std::cout<<"My object Name is:"<<s1<<std::endl;
    std::cout<<"Data Received from Slot is:"<<num<<std::endl;
    std::cout<<"Slot END"<<std::endl;
}

void slot_class_1::sig_2_handler(int num){
    std::cout<<"SLOT FOR SIGNAL NAMED: void sig_2_handler(int) in TestClass"<<std::endl;
    std::cout<<"I am object of the class:"<<typeid(*this).name()<<std::endl;
    std::cout<<"My Address is:"<<std::hex<<this<<std::endl;
    std::cout<<"My Object Name is:"<<s1<<std::endl;
    std::cout<<"Data Received from slot is:"<<num<<std::endl;
    std::cout<<"SLOT END"<<std::endl;
}
