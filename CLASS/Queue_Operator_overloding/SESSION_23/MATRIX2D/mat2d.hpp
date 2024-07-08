#ifndef _MAT2D_H 
#define _MAT2D_H 

#include <iostream>

class mat2d 
{
    public:  
        typedef long long size_type; 
    
    private: 
        size_type* pmat; 
        size_type nr_rows, nr_cols; 

    public:     
        // parameterized constructor 
        mat2d(
            size_type rows, 
            size_type cols
        );

        // destructor
        ~mat2d(); 

        // arithmetic operator overload 
        mat2d operator+(const mat2d& rhs_object) const; 
        mat2d operator-(const mat2d& rhs_object) const; 
        mat2d operator*(const mat2d& rhs_object) const; 

        // member functions: getters of nr_rows, and nr_corls 
        // setter of matrix cell at row i, col j 
        size_type rows() const; 
        size_type cols() const; 
        void set(size_type i, size_type j, size_type val); 

        // cout operator overload 
        friend std::ostream& operator<<(
            std::ostream& os, 
            const mat2d& mat_object
        );   
}; 

std::ostream& operator<<(
    std::ostream& os, 
    const mat2d& mat_object
); 

#endif 