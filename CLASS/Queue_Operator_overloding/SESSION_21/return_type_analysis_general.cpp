class T 
{
    private: 
        // data block 

    public: 
        // default constructor 
        T(){}

        // parameterized constructor 
        T(int N)
        {

        }

        // alternative 1 : when sizeof(T) <= 32 
        T operator+(const T& other) const 
        {
            T local_object; 

            // return by value. if sizeof(T) is small enough 
            return local_object; 
        }

        // altnerative 2 : when sizeof(T) > 32 
        T* operator+(const T& other) const 
        {
            T* pT = new T; 
            return pT; 
        }

        // alterative 3 : when sizeof(T) >= 32 
        T& operator+(const T& other) const 
        {
            T* pT = new T; 

            return *pT; 
        }
}; 

int main(void)
{
    T t1, t2; 

    T t3 = t1 + t2; // alternative 1 
                    // lifetime of t3 will be managed by lang 

    // alterative 2 
    T* pT = t1 + t2; 
    delete pT; 
    pT = 0; 

    // alterative 3 
    T& refT = t1 + t2; 
    delete &refT; 

    return 0; 
}

/* 
    T result = t1 + t2 + t3 

    t1 + t2 

    T::operator+(&t1, t2) 

    case 1) Return Type T 
    OBJECT + t3; 
    TMP OBJECT + t3 

    T::operator+(addrees of TMP object, t3)
    TMP2 OBJECT 
    result = T::operator+(addrees of TMP object, t3)
    result = TMP2 OBJECT 
    ////////////////////////////////////////////////////////////
    case 2) Return Type T& 
    T& result = t1 + t2 + t3; 
    t1 + t2 
    T::operator+(&t1, t2)

    DYNAMIC OBJECT 1 + t3 

    T::operator+(ADDR OF DYNAMIC OBJECT 1, t3)

    RETURN VALUE 
    DYNAMIC OBJECT 2 

    will be named by T& result 

    delete &result; 

*/

// t1 + t2 + t3

//type(t1 + t2)   ==  RETURN TYPE ANNOTATION OF 
//                    T::operator+()