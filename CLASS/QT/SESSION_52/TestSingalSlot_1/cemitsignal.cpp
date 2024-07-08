#include <iostream>
#include "cemitsignal.h"

CEmitSignal::CEmitSignal(QObject *parent)
    : QObject{parent}
{}

void CEmitSignal::sendCoordinates(double _x, double _y)
{
    std::cout << "CEmitSignal::sendCoordinates():Address in this:"
              << std::hex << this << std::endl
              <<"_x:" << _x << std::endl
              << "_y:" << _y << std::endl
              << "Emitting signal CEmitSignal::coordinate() with _x, _y"
              << std::endl;

    emit coordinates(_x, _y); // ccs.grabCoordinates(_x, _y)

    std::cout << "Done emitting signal:Returning to main()" << std::endl;
}

