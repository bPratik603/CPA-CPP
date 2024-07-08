#include "mat2d.hpp"
#include <iostream>

mat2d::mat2d(size_type rows,size_type cols) : nr_rows(rows),nr_cols(cols)
{}

mat2d::size_type mat2d::rows() const
{
    return (nr_rows);
}

mat2d::size_type mat2d::cols() const
{
    return (nr_cols);
}

void mat2d::set(size_type i,size_type j,size_type value)
{
    mat2d::pmat = (size_type*)malloc(nr_rows * nr_cols * sizeof(size_type));

    for(size_type _i = 0;_i<i;i++)
    {
        for(size_type _j = 0;_j<j;j++)
        {
            *(pmat + _i * j + _j)  = value;
        }
    } 
}

mat2d mat2d::operator+(const mat2d& rhs_obj) const
{
    size_type* sum_obj = (size_type*)malloc(nr_rows * nr_cols * sizeof(size_type));

    for(size_type i = 0;i<nr_rows;i++)
    {
        for(size_type j = 0;j<nr_cols;j++)
        {
            *(sum_obj + i*nr_cols + j) = ((this->pmat +i*nr_cols+j) + (rhs_obj.pmat + i*nr_cols+j)); 
        }
    }

    return sum_obj;
}

mat2d mat2d::operator-(const mat2d& rhs_obj) const
{
    size_type* sub_obj = (size_type*)malloc(nr_rows * nr_cols * sizeof(size_type));

    for(size_type i = 0;i<nr_rows;i++)
    {
        for(size_type j = 0;j<nr_cols;j++)
        {
            *(sub_obj + i*nr_cols + j) = ((this->pmat + i*nr_cols+j) - (rhs_obj.pmat + i*rhs_obj+j));
        }
    }

    return sub_obj;
}

std::ostream& mat2d::operator<<(std::ostream& os,const mat2d& mat_object)
{
    mat2d::size_type i,j;
   ;
    mat2d::nr_cols;
     for( i = 0;i< mat2d::nr_rows; mat2d::nr_rows++)
     {
        for(j=0;j<mat2d::nr_cols;mat2d::nr_cols++)
        {
           os << *(mat_object + i*mat2d::nr_cols + j);
        }
     }

     return os;
}