#include <iostream> 
#include "list.hpp"
#include "stack.hpp"

stack::stack() : p_list(new list)
{
    
} 

stack::~stack()
{
    delete p_list; 
}

stack::status_t stack::push(data_t new_data)
{
    return p_list->insert_end(new_data); 
}

stack::status_t stack::pop(data_t* p_poped_data)
{
    return p_list->pop_end(p_poped_data); 
}

stack::status_t stack::top(data_t* p_top_data)
{
    return p_list->get_end(p_top_data); 
}

bool stack::empty() const
{
    return p_list->empty(); 
}