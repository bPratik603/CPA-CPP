#include <iostream>
#include "slot_class_1.h"

Slot_Class_1::Slot_Class_1(std::string _s1) : s1(_s1) {}

void Slot_Class_1::sig_1_handler(int num){
    std::cout << "SLOT FOR SIGNAL NAMED: void sig1(int) in TestClass" << std::endl;
    std::cout << "I am object of the class:" << typeid(*this).name() << std::endl;
    std::cout << "My Address is:" << std::hex << this << std::endl;
    std::cout << "My Object Name is:" << s1 << std::endl;
    std::cout << "Data Received from Slot is:" << num << std::endl;
    std::cout << "SLOT END" << std::endl;
}

void Slot_Class_1::sig_2_handler(int num){
    std::cout << "SLOT FOR SIGNAL NAMED: void sig_2_handler(int) in TestClass" << std::endl;
    std::cout << "I am object of the class:" << typeid(*this).name() << std::endl;
    std::cout << "My Address is:" << std::hex << this << std::endl;
    std::cout << "My Object Name is:" << s1 << std::endl;
    std::cout << "Data Received from Slot is:" << num << std::endl;
    std::cout << "SLOT END" << std::endl;
}
