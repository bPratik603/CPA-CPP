#include "Counter.h"

int main(int argc, char* argv[])
{
    Counter A, B;

    QObject::connect(&A, SIGNAL(valueChanged(int)),
                     &B, SLOT(setValue(int)));

    B.setValue(10);
    A.show("after B.setValue():A:");
    B.show("after B.setValue():B:");

    A.setValue(500);
    A.show("after A.setValue():A:");
    B.show("after A.setValue():B:");

    return 0;
}

