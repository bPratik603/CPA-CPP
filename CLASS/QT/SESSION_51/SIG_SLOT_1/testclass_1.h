#ifndef TESTCLASS_1_H
#define TESTCLASS_1_H

#include <QObject>

class TestClass_1 : public QObject
{
    Q_OBJECT
public:
    TestClass_1(QObject *parent = nullptr);

    void trigger_all_signals_sw();

signals:
    void sig1(int);
    void sig2(int);
    void sig3(int, int);
    void sig4(const char*, int);
    void sig5(double, const char*);
};

#endif // TESTCLASS_1_H
