#include "testclass_1.h"

TestClass_1::TestClass_1(QObject *parent)
    : QObject{parent}
{}

void TestClass_1::trigger_all_signals_sw(){
    emit sig1(100);
    emit sig2(200);
    emit sig3(400, 500);
    emit sig4("Hello", 600);
    emit sig5(100.513, "Some data");
}
