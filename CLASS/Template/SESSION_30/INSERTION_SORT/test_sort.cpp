#include <iostream> 
#include <cstdlib> 
#include "sort.hpp"

class Date{
    private: 
        int day, month, year; 
    public: 
        Date(int _d, int _m, int _y) : day(_d), 
                                       month(_m), 
                                       year(_y)
        {
        }

        Date() : day(0), month(0), year(0)
        {
        }

        bool operator>(const Date& other){
            bool left_greater; 

            if(year != other.year)
                left_greater = (year > other.year);  
            else if(month != other.month)
                left_greater = (month > other.month);
            else 
                left_greater = (day > other.day);  

            return left_greater; 
        }

        friend std::ostream& operator<<(std::ostream& os, const Date& date_object); 
}; 

std::ostream& operator<<(std::ostream& os, const Date& date_object){
    os  << date_object.day 
        << "-" 
        << date_object.month 
        << "-" 
        << date_object.year 
        << std::endl; 

    return os; 
}

int main(void){
    const ssize_t N = 5; 
    
    int ia[N] = {100, 200, 400, 500, 50};
    double da[N] = {1.1, 4.4, 2.2, 7.7, 3.3};  
    Date date_arr[N] = {
        Date(1, 1, 1970), 
        Date(2, 4, 1969), 
        Date(3, 2, 1999), 
        Date(1, 1, 1965), 
        Date(15, 8, 1947)
    }; 

    std::cout << "Sorting Integer array using insertion_sort():" << std::endl; 
    show_array<int>(ia, N, "Before Sort:"); 
    insertion_sort<int>(ia, N); 
    show_array<int>(ia, N, "After Sort:"); 

    std::cout << "Sorting Double array using insertion_sort():" << std::endl; 
    show_array<double>(da, N, "Before Sort:"); 
    insertion_sort<double>(da, N); 
    show_array<double>(da, N, "After Sort:"); 

    std::cout << "Sorting Date array using insertion_sort()" << std::endl; 
    show_array<Date>(date_arr, N, "Before Sort:"); 
    insertion_sort<Date>(date_arr, N); 
    show_array<Date>(date_arr, N, "After Sort:"); 

    return EXIT_SUCCESS; 
}