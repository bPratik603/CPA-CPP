#include <iostream>
#include "ccatchsignal.h"

CCatchSignal::CCatchSignal(QObject *parent)
    : QObject{parent}
{}

void CCatchSignal::grabCoordinates(double cx, double cy)
{
    std::cout << "CCatchSignal::grabCoordinates()" << std::endl
              << "Data from emission" << std::endl
              << "x:" << cx << std::endl << "y:" << cy << std::endl
              << "Returning from CCatchSignal::grabCoordinates()" << std::endl;

}
