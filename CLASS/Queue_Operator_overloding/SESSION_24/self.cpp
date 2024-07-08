#include <iostream>
#include <cassert>
#include <cstring>

class matrix
{
   private:
     int* pa;
     int nr_rows;
     int nr_cols;

    public:
      matrix(int _nr_rows,int _nr_cols)
      {
        assert(_nr_rows >0 && _nr_cols > 0);

        nr_rows = _nr_rows;
        nr_cols = _nr_cols;

        pa = (int*)malloc(nr_rows * nr_cols * sizeof(int));

        memset(pa,0,nr_rows*nr_cols*sizeof(int));
      }

    int& operator()(int i,int j)
    {
       assert((i >= 0 && i<nr_rows) && (j >= 0 && j<nr_cols));

       return *(pa + i*nr_cols+j);
    }

    ~matrix()
    {
      delete pa;
      pa = 0;
    }
};

int main(void)
{
  matrix m(3,5);

  std::cout<<"before initialise: "<<std::endl;
  for(int i = 0;i <3;i++)
  {
     for(int j= 0;j<5;j++)
     {
        std::cout<<"m("<<i<<","<<j<<"): "<<m(i,j)<<std::endl;
     }
  }

   for(int i = 0;i <3;i++)
  {
     for(int j= 0;j<5;j++)
     {
        m(i,j) = (i+j) * 10;
     }
  }

   std::cout<<"After initialising"<<std::endl;
     for(int i = 0;i <3;i++)
  {
     for(int j= 0;j<5;j++)
     {
        std::cout<<"m("<<i<<","<<j<<"): "<<m(i,j)<<std::endl;
     }
  }
}