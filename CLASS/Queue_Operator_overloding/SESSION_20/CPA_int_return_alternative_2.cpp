class CPA_int
{
    private: 
        int N; 
    public: 
        CPA_int(int _N = 0) : N(_N)
        {
        }

        CPA_int& operator+(CPA_int other)
        {
            int result = this->N + other.N; 
            CPA_int summation_object(result); 
            return summation_object; 
        }

   
}; 

int main(void)
{
    CPA_int Ci_1(100), Ci_2(200); 
    CPA_int& ref = Ci_1 + Ci_2; 
    // ref is a dangling reference 

  

    return 0; 
}

/* HOW TO CORRECT THE ERROR 

class CPA_int
{
    private: 
        int N; 
    public: 
        CPA_int(int _N = 0) : N(_N)
        {
        }

        CPA_int& operator+(CPA_int other)
        {
            int result = this->N + other.N; 
            CPA_int* p_result = new CPA_int(result); 
            return (*p_result); 
        }

   
}; 

int main(void)
{
    CPA_int Ci_1(100), Ci_2(200); 
    CPA_int& ref = Ci_1 + Ci_2; 

    // USE ref 

    delete &ref; 
    
    return 0; 
}


*/