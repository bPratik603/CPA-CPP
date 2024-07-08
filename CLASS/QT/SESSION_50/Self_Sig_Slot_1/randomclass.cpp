#include "randomclass.h"
#include "randomclass.h"
#include <iostream>
randomclass::randomclass()
{}

void randomclass::pqr(int n){
    std::cout<<"I am merely a member function"<<std::endl;
    std::cout<<n<<"is n"<<std::endl;
}

void randomclass::xyz(int m){
    std::cout<<"SLOT START"<<std::endl;
    std::cout<<"I am an object of class:"<<typeid(*this).name()<<std::endl;
    std::cout<<"My address is:"<<std::hex<<this<<std::endl;
    std::cout<<"I am a SLOT "<<std::endl;
    std::cout<<"My class is so random that even entropy shies in front of it"<<std::endl;
    std::cout<<"Input data from signal:"<<m<<std::endl;

}
