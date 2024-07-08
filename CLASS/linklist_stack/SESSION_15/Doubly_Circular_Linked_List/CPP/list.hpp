#ifndef _LIST_H 
#define _LIST_H 

const int SUCCESS = 1; 
const int TRUE = 1; 
const int FALSE = 0; 
const int LIST_DATA_NOT_FOUND = 2; 
const int LIST_EMPTY = 3; 

typedef int data_t;  

class node 
{
    friend class list; 
    private: 
        data_t data; 
        node* prev; 
        node* next; 
        node(int new_data = 0); 
}; 

class list
{
    private: 
        node* head_node; 
    public: 
}; 

#endif /* _LIST_H */