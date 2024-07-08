#include <iostream>
#include <cstdlib>
#include "self.hpp"

node::node(int new_data) : data(new_data),prev(0),next(0)
{

}

list::list() : head_node(new node)
{
    head_node->prev = head_node;
    head_node->next = head_node;
}

list::~list()
{
    node* run = 0;
    node* run_next;

    for(run = head_node->next;run != head_node; run = run_next)
    {
        run_next = run->next;
        delete run;
    }

    delete head_node;
    head_node = 0;
}

list::status_t list::insert_start(data_t new_data)
{
    generic_insert(this->head_node,new node(new_data),this->head_node->next);
     return(SUCCESS);
}

list::status_t list::insert_end(data_t new_data)
{
    generic_insert(this->head_node->prev,new node(new_data),this->head_node);
    return(SUCCESS);
}

list::status_t list::insert_after(data_t e_data,data_t new_data)
{
    node* e_node = 0;

    e_node = search_node(e_data);
    if(e_node == NULL)
       return(LIST_DATA_NOT_FOUND);

    generic_insert(e_node,new node(new_data),e_node->next);
    return(SUCCESS);
}

list::status_t list::insert_before(data_t e_data,data_t new_data)
{
       node* e_node = 0;

       e_node = search_node(e_data);
       if(e_node == NULL)
         return(LIST_DATA_NOT_FOUND);

        generic_insert(e_node->prev,new node(new_data),e_node);
        return(SUCCESS);
}

list::status_t list::get_start(data_t* p_start_data) const
{
      if(empty())
        return(LIST_EMPTY);

    *p_start_data = this->head_node->next->data;
    return(SUCCESS);
}

list::status_t list::get_end(data_t* p_end_data) const
{
    if(empty())
      return(LIST_EMPTY);

    *p_end_data = head_node->prev->data;
    return(SUCCESS);
}

list::status_t list::pop_start(data_t* p_start_data)
{
    if(empty())
       return(LIST_EMPTY);

    *p_start_data = head_node->next->data;
    generic_delete(head_node->next);
    return(SUCCESS);
}

list::status_t list::pop_end(data_t* p_end_data)
{
    if(empty())
      return(LIST_EMPTY);

    *p_end_data = head_node->prev->data;
    generic_delete(head_node->prev);
    return(SUCCESS);
}

list::status_t list::remove_start()
{
    if(empty())
       return(LIST_EMPTY);
    
    generic_delete(head_node->next);
    return(SUCCESS);
}

list::status_t list::remove_end()
{
    if(empty())
       return(LIST_EMPTY);

     generic_delete(head_node->prev);
     return(SUCCESS);
}

list::status_t list::remove_data(data_t r_data) 
{
   node* s_node = 0;

   s_node = search_node(r_data);
   if(s_node == NULL)
   {
      return(LIST_EMPTY);
   }

   generic_delete(s_node);
   return(SUCCESS);
}

bool list::find(data_t f_data)
{
    node* f_node = 0;

    f_node = search_node(f_data);
    return(f_node != NULL);
}

void list::show(const char* msg) const
{
    if(msg)
      puts(msg);

    puts("[START]->");

    for(node* run = head_node->next;run != head_node;run = run->next)
    {
        std::cout<<"["<<run->data<<"]<->"<<std::endl;
    }
     puts("[END]");
}

list::len_t list::size() const
{
    list::len_t len = 0;

    for(node* run = head_node;run != head_node;run = run->next)
    {
        ++len;
    }
    return(len);
}







void list::generic_insert(node* beg,node* mid,node* end)
{
      mid->next = end;
      mid->prev = beg;
      beg->next = mid;
      end->prev = mid;
}

void list::generic_delete(node* p_delete_node) 
{
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;
}

node* list::search_node(data_t e_data)
{
    for(node* run = head_node->next;run != head_node;run = run->next)
    {
            if(run->data == e_data)
            {
                return(run);
            }
    }
    return(NULL);
}

bool list::empty() const
{
    return(this->head_node->next == this->head_node && this->head_node->prev == this->head_node);
}