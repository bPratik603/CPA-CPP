#include<iostream>

class A
{
    private:
     int dd,mm,yy;

     public:
      A() : dd(1),mm(12),yy(2020)
      {

      }

      void show(const char* msg)
      {
         std::cout<<msg<<std::endl<<dd<<"-"<<mm<<"-"<<yy<<std::endl;
      }
};

int main(void)
{
   A a1;

   a1.show(" A a1");

   A* a2 = new A;

   a2->show("A* a2");

   A& a3 = *(new A);

   a3.show("A& a3");

   delete a2;
   a2 = 0;

   delete &a3;
   


}
