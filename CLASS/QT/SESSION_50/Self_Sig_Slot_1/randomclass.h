#ifndef RANDOMCLASS_H
#define RANDOMCLASS_H

#include <QObject>

class randomclass : public QObject
{
    Q_OBJECT
public:
    randomclass();
    void pqr(int m);

 public slots:
    void xyz(int n);
};

#endif // RANDOMCLASS_H
