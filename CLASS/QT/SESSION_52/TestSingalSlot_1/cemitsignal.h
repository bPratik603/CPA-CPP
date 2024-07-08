#ifndef CEMITSIGNAL_H
#define CEMITSIGNAL_H

#include <QObject>

class CEmitSignal : public QObject
{
    Q_OBJECT
public:
    explicit CEmitSignal(QObject *parent = nullptr);
    void sendCoordinates(double _x, double _y);

signals:
    void coordinates(double x, double y);
};

#endif // CEMITSIGNAL_H
