#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <iostream>

class Counter : public QObject
{
        Q_OBJECT
private:
        int m_value;
public:
        Counter();
        int getValue() const;
        void show(const char* msg);
public slots:
        void setValue(int newValue);
signals:
        void valueChanged(int newValue);
};

#endif // COUNTER_H
