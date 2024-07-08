class Date1{
    private: 
        int dd, mm, yy; 
    public: 
        Date1() : dd(1), mm(1), yy(1970){

        }

    Date1(int _d, int _m, int _y): dd(_d), mm(_m), yy(_y){

    }
}; 

class Date{
    private: 
        int dd, mm, yy; 
    public: 
        Date(int _d=1, int _m=1, int _y=1970) : dd(_d), mm(_m), yy(_y){

        }
}; 

int main(void){
    Date epoch_date; // 1-1-1970
    Date myDate(3, 9, 2023); // 3-9-2023

    return 0; 
}

