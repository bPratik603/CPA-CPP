#ifndef  _ARRAY_H
#define  _ARRAY_H

typedef long long int ssize_t;

class array{
    private:
     int* a;
      ssize_t N;

      public:
      typedef enum status{SUCCESS=1,INDEX_OUT_OF_RANGE} status_t;
      array(ssize_t N);
      status_t get(ssize_t index, int* element) const;
      status_t set(ssize_t index,int new_val);
      ssize_t size() const;
      void sort();
      void show(const char* msg = 0)const;
      ~array();

};



#endif