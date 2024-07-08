#ifndef RANDOMCLASS_H
#define RANDOMCLASS_H

#include <QObject>

class RandomClass : public QObject
{
    Q_OBJECT
public:
    RandomClass();
    void pqr(int m);
public slots:
    void xyz(int n);
};

#endif // RANDOMCLASS_H
