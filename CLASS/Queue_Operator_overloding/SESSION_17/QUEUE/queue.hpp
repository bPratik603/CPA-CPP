#include "list.hpp" 

const int QUEUE_EMPTY = LIST_EMPTY; 

class queue
{
    private: 
        list* lst; 
    
    public: 
        typedef list::status_t status_t; 
        queue(); 
        ~queue();
        status_t enqueue(data_t new_data); 
        status_t peek(data_t* p_peek_data); 
        status_t dequeue(data_t* p_dequeued_data); 
        bool empty();  
}; 