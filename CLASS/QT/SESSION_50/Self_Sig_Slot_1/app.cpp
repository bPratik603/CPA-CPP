#include <iostream>
#include <string>
#include "testclass_1.h"
#include "slot_class_1.h"
#include "randomclass.h"
#include <iostream>
int main(void)
{
    testclass_1 t1,t2;
    slot_class_1 sc_object1(std::string("SLOT CLASS OBJECT 1"));
    slot_class_1 sc_object2(std::string("SLOT CLASS OBJECT_2"));
    randomclass r1;

    QObject::connect(&t1,SIGNAL(sig1(int)),
                     &sc_object2,SLOT(sig_1_handler(int)));

    QObject::connect(&t1,SIGNAL(sig1(int)),
                     &sc_object1,SLOT(sig_1_handler(int)));

    QObject::connect(&t1,SIGNAL(sig(int)),
                     &r1,SLOT(xyz(int)));

    QObject::connect(&t1,SIGNAL(sig2(int)),
                     &r1,SLOT(xyz(int)));

    std::cout<<"START"<<std::endl;
    t1.trigger_all_signals_sw();
    std::cout<<"END"<<std::endl;

    return (0);
}
