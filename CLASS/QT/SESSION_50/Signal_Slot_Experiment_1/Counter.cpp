#include "Counter.h"
#include <iostream>
#include <QObject>

Counter::Counter() : m_value(0)
{

}

int Counter::getValue() const
{
    return m_value;
}

void Counter::show(const char* msg)
{
    if(msg)
        std::cout << msg;
    std::cout << m_value << std::endl;
}

void Counter::setValue(int newValue)
{
    if(m_value != newValue)
    {
        m_value = newValue;
        emit valueChanged(newValue);
    }
}
