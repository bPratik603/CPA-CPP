#include <QObject>

#define INDIE               1
#define  GOLDEN_RERIEVER    2
#define  PITBULL            3


class dog : public QObject{
    Q_OBJECT

    private:
      const char* name;
      int dog_type;

      public:
      dog(const char* _name,int _dog_type);
      const char* get_name() const;

      public slots:
      void barking();
      void shouting_as_told(const char* msg);
}