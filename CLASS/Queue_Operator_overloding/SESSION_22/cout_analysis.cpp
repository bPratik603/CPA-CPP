std::cout << epoch_date << ;  

ostream operator<<(cout, epoch_date) 

class ostream
{

    public: 
        ostream& operator<<(const Date& date_obj)
        {


            return *this; 
        }
}; 

class Date 
{

    std::ostream& operator<<(ostream& os)
    {

        return os; 
    }
};

std::cout << objT; 

operator<< 

ostream 

class T 