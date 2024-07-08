struct date{
    int dd, mm, yy; 
}; 

int main(){
    // if you want to create an instance of struct then there are two ways 
    struct date d; // data definition statement 
    struct date* p_date = malloc(sizeof(struct date)); 

    d.dd = rhs; 
    d.mm = rhs; 
    d.yy = rhs; 

    lhs = d.dd; 
    lhs = d.mm; 
    lhs = d.yy; 

    p_date->dd = rhs; 
    p_date->mm = rhs; 
    p_date->yy = rhs; 

    lhs = p_date->dd; 
    lhs = p_date->mm; 
    lhs = p_date->yy; 


}

// information regarding every name of internal member of 
// structure and its type is known as LAYOUT INFORMATION 
// DATA LAYOUT 

// Under C language, if you have instance of structure or 
// pointer of structure then with help of dot or arrow operator 
// AND DATA LAYOUT INFORMATION you have to manip instance. 

// this creates a coupling between internal layout of data 
// at server side and it's use at client side