#ifndef _ANIMAL_HPP 
#define _ANIMAL_HPP 

#include <QObject>

class animal : public QObject{
    Q_OBJECT 

    public: 
        void trigger_shout(); 
        void trigger_shout_as_told(const char* msg); 

    signals: 
        void shout(); 
        void shout_as_told(const char*); 
}; 


#endif 