#include <iostream>
#include "cemitsignal.h"
#include "ccatchsignal.h"

int main(void)
{
    CEmitSignal ces;
    CCatchSignal ccs;

    std::cout << "main():start" << std::endl;

    std::cout << "main():Connecting coordinate() signal from ces object of class CEmitSignal"
              << " with grabCoordinate() slot on ccs object of class CCatchSignal"
              << std::endl;

    QObject::connect(
        &ces,
        SIGNAL(coordinates(double,double)),
        &ccs,
        SLOT(grabCoordinates(double,double))
        );

    std::cout << "main():Done connection" << std::endl;

    std::cout << "main():Address of object ces of the type"
              << " CEmitSignal:" << std::hex << &ces << std::endl
              << "main():Invoking sendCoordinates() member function"
              << " with 1.1 and 2.2 as actual parameters on ces" << std::endl;
    ces.sendCoordinates(1.1, 2.2);
    std::cout << "main():Returned from ces.sendCoordinates()" << std::endl;
    std::cout << "main():end" << std::endl;
    return 0;
}
