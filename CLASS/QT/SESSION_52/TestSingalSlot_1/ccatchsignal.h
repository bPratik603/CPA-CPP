#ifndef CCATCHSIGNAL_H
#define CCATCHSIGNAL_H

#include <QObject>

class CCatchSignal : public QObject
{
    Q_OBJECT
public:
    explicit CCatchSignal(QObject *parent = nullptr);

public slots:
    void grabCoordinates(double cx, double cy);
signals:

};

#endif // CCATCHSIGNAL_H
