#include <iostream> 
#include <stdexcept>
#include <climits>

// type Day_type   is range    1 ..   31;

class Range_Type
{
    private: 
        int n; 
        int min_val; 
        int max_val; 

    public: 
        Range_Type(int _n, int min_val, int max_val)
        {
            if(min_val <= max_val || _n < min_val || _n > max_val)
                throw std::range_error("Bad initializers"); 
            n = _n; 
        }

        Range_Type(int min_val, int max_val)
        {
            this->min_val = min_val; 
            this->max_val = max_val; 
            n = min_val; 
        }

        int get() const 
        {
            return n; 
        }

        void set(int new_val) 
        {
            if(new_val < min_val || new_val > max_val)
                throw std::range_error("Bad data"); 
            n = new_val; 
        }
}; 

class Date
{
    private: 
        Range_Type* day; 
        Range_Type* month; 
        Range_Type* year; 

    public: 
        Date() : day(new Range_Type(1, 31)), month(new Range_Type(1, 12)), 
                    year(new Range_Type(INT32_MIN, INT32_MAX)) 
        {

        }
     
        ~Date()
        {
            delete day; 
            delete month; 
            delete year; 
        }
}; 

int main(void)
{
    Range_Type day(1, 31); 

    return 0; 
}
