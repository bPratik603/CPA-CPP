#ifndef TESTCLASS_H
#define TESTCLASS_H

#include <QObject>

class testclass : public QObject
{
    Q_OBJECT
public:
    explicit testclass(QObject *parent = nullptr);

signals:
};

#endif // TESTCLASS_H
