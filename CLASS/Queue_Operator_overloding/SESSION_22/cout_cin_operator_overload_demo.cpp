/* 
int n; 
std::cin >> n; 
std::cout << n << std::endl;  
*/

#include <iostream> 

class Date 
{
    private: 
        int day; 
        int month; 
        int year; 
    public: 
        Date(int _dd, int _mm, int _yy) : day(_dd), month(_mm), year(_yy)
        {

        }

        Date() : day(1), month(1), year(1970)
        {

        }

        void show(const char* msg) const 
        {
            if(msg)
                std::cout << msg; 
            std::cout << day << "-" << month << "-" << year << std::endl; 
        }

        friend std::ostream& operator<<(
                    std::ostream& op_stream, 
                    const Date& date_obj
                );

        friend std::istream& operator>>(
            std::istream& ip_stream,
            Date& date_obj 
        ); 
        
}; 

std::ostream& operator<<(std::ostream& op_stream, const Date& date_obj)
{
    op_stream << date_obj.day << "-" << date_obj.month << "-" << date_obj.year 
              << std::endl; 
    return op_stream; 
}

std::istream& operator>>(
            std::istream& ip_stream,
            Date& date_obj
        )
{
    std::cout << "Enter day:"; 
    ip_stream >> date_obj.day; 

    std::cout << "Enter month:"; 
    ip_stream >> date_obj.month; 

    std::cout << "Enter year:"; 
    ip_stream >> date_obj.year; 

    return ip_stream; 
}

int main(void)
{
    Date user_date; 
    std::cin >> user_date; 
    std::cout << "USER DATE:" << user_date << std::endl; 
    return 0; 
}

/* 
    class Date {}; 
    Date objDate; 

    class Matrix {}; 
    Matrix m; 

    std::cout << objDate; 

    std::cout << m; 

    C obj; 
    obj.function(param)

    C::function(&obj, param); 

    s1 + s2

    std::operator+(&s1, s2); 
*/

