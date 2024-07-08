#ifndef SLOT_CLASS_1_H
#define SLOT_CLASS_1_H

#include <QObject>
#include <string>

class Slot_Class_1 : public QObject
{
    Q_OBJECT

private:
    std::string s1;

public:
    Slot_Class_1(std::string _s1);
public slots:
    void sig_1_handler(int num);
    void sig_2_handler(int num);
};

#endif // SLOT_CLASS_1_H
