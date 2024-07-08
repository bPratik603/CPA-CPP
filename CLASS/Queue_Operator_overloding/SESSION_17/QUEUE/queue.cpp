#include "queue.hpp"

queue::queue() : lst(new list)
{

}

queue::~queue()
{
    delete lst; 
    lst = 0; 
}

queue::status_t queue::enqueue(data_t new_data)
{
    return lst->insert_end(new_data); 
}

queue::status_t queue::peek(data_t* p_peek_data)
{
    return lst->get_start(p_peek_data); 
}

queue::status_t queue::dequeue(data_t* p_dequeued_data)
{
    return lst->pop_start(p_dequeued_data); 
}

bool queue::empty()
{
    return lst->empty(); 
}