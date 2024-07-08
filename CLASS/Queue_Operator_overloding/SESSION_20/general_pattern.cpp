/* 
    class T 
    {

        public: 
            operator-bin_infix_op(T other); 
            operator-bin_infix_op(T& other); 
            operator-bin_infix_op(const T& other); 
            operator-bin_infix_op(T other) const; 
            operator-bin_infix_op(T& other) const; 
            operator-bin_infix_op(const T& other) const;

            T operator-bin_infix_op(T other); 
            T operator-bin_infix_op(T& other); 
            T operator-bin_infix_op(const T& other); 
            T operator-bin_infix_op(T other) const; 
            T operator-bin_infix_op(T& other) const; 
            T operator-bin_infix_op(const T& other) const;  

            // return object should outlive 
            // operator overload member function call 

            T& operator-bin_infix_op(T other); 
            T& operator-bin_infix_op(T& other); 
            T& operator-bin_infix_op(const T& other); 
            T& operator-bin_infix_op(T other) const; 
            T& operator-bin_infix_op(T& other) const; 
            T& operator-bin_infix_op(const T& other) const; 

            // Caller must not change object 
            const T& operator-bin_infix_op(T other); 
            const T& operator-bin_infix_op(T& other); 
            const T& operator-bin_infix_op(const T& other); 
            const T& operator-bin_infix_op(T other) const; 
            const T& operator-bin_infix_op(T& other) const; 
            const T& operator-bin_infix_op(const T& other) const; 

    }; 

*/