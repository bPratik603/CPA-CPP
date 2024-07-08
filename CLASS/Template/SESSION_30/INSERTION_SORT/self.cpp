#include <iostream>
#include "self.hpp"

class Date
{
   private:
     int day,month,year;

   public:
     Date(int _d,int _m,int _y) : day(_d),month(_m),year(_y)
     {}

     Date() : day(0),month(0),year(0)
     {}

     bool operator>(const Date& other)
     {
         bool left_greater;

         if(day > other.day)
           left_greater = (day > other.day);
         else if(month > other.month)
           left_greater = (month > other.month);
         else
         {
            left_greater = (year > other.year);
         }

         return left_greater;
     }

     friend std::ostream& operator<<(std::ostream& os,const Date& other);
     
};

std::ostream& operator<<(std::ostream& os,const Date& other)
{
   os << other.day <<"-"<<other.month<<"-"<<other.year<<std::endl;
   return os;
}

int main(void)
{
   const int N = 5;

  int ia[N] = {100, 200, 400, 500, 50};
    double da[N] = {1.1, 4.4, 2.2, 7.7, 3.3};  
    Date date_arr[N] = {
        Date(1, 1, 1970), 
        Date(2, 4, 1969), 
        Date(3, 2, 1999), 
        Date(1, 1, 1965), 
        Date(15, 8, 1947)};

   std::cout<<"sorting Interger array using insertion_sort():"<<std::endl;
   show_arr<int>(ia,N,"Before sort");
   insertion_sort<int>(ia,N);
   show_arr<int>(ia,N,"After sort");

   std::cout<<"soring Double array using insertion sort:"<<std::endl;
   show_arr<double>(da,N,"Before sort");
   insertion_sort<double>(da,N);
   show_arr<double>(da,N,"After sorting");

   std::cout<<"sorting Date array using insertion_sort:"<<std::endl;
   show_arr<Date>(date_arr,N,"Before sort");
   insertion_sort<Date>(date_arr,N);
   show_arr<Date>(date_arr,N,"After sort");

   return EXIT_SUCCESS;
}