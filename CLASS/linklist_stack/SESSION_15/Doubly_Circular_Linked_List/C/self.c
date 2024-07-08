#include<stdio.h>
#include<stdlib.h>
#include "self.h"

list_t* create_list(void)
{
    list_t* p_list = NULL;

    p_list = get_node(-1);

    p_list->next = p_list;
    p_list->prev = p_list;

    return(p_list);
}

status_t insert_start(list_t* p_list,data_t new_data)
{
    generic_insert(p_list,get_node(new_data),p_list->next);
    return(SUCCESS);
}

status_t insert_end(list_t* p_list,data_t new_data)
{
    generic_insert(p_list->prev,get_node(new_data),p_list);
    return(SUCCESS);
}

status_t insert_after(list_t* p_list,data_t e_data,data_t new_data)
{
    node_t* e_node = NULL;
    
    e_node = search_node(p_list,e_data);
    if(e_node == NULL)
    {
        return(LIST_DATA_NOT_FOUND);
    }

    generic_inseret(e_node,get_node(new_data),e_node->next);
    return(SUCCESS);
}

status_t inseret_before(list_t* p_list,data_t e_data,data_t new_data)
{
    node_t* e_node;

    e_node = search_node(p_list,e_data);
    if(e_node == NULL)
    {
        return(LIST_DATA_NOT_FOUND);
    }

    generic_insert(e_node->prev,get_node(new_data),e_node);
    return(SUCCESS);
}

status_t get_start(list_t* p_list,data_t* p_start_data)
{
    if(is_list_empty(p_list) == TRUE)
    {
        return(LIST_EMPTY);
    }

    *p_start_data = p_list->next->data;
    return(SUCCESS);
}

status_t get_end(list_t* p_list,data_t* p_end_data)
{
    if(is_list_empty(p_list) == TRUE)
    {
        return(LIST_EMPTY);
    }

    *p_end_data = p_list->prev->data;
    return(SUCCESS);
}

status_t pop_start(list_t* p_list,data_t* e_data)
{
    node_t* p_node;

    p_node = is_list_empty(p_list);
    if(p_node == NULL)
    {
        return(LIST_EMPTY);
    }

    *e_data = p_list->next->data;

    generic_delete(p_list->next);

    return(SUCCESS);
}

status_t pop_end(list_t* p_list,data_t* p_end_data)
{
    if(is_list_empty(p_list) == TRUE)
    {
        return(LIST_EMPTY);
    }

    *p_end_data = p_list->prev->data;
     generic_delete(p_list->prev);
    return(SUCCESS);
}

status_t remove_start(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
    {
        return(LIST_EMPTY);
    }

    generic_delete(p_list->next);
    return(SUCCESS);
}

status_t remove_end(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
    {
        return(LIST_EMPTY);
    }

    generic_delete(p_list->prev);
    return(SUCCESS);
}

status_t remove_data(list_t* p_list,data_t e_data)
{
    list_t* e_node;

    e_node = search_node(p_list,e_data);
    if(e_node == NULL)
    {
        return(LIST_DATA_NOT_FOUND);
    }

    generic_delete(p_list);
    return(SUCCESS);
}

status_t search_list(list_t* p_list,data_t s_data)
{
    node_t* s_node = NULL;
    s_node = search_node(p_list,s_data);
    return(s_node != NULL);
}

len_t get_list_length(list_t* p_list)
{
    node_t* run = NULL;
    size_t len = 0;

    for(run = p_list->next;run != p_list;run = run->next)
    {
        ++len;
    }
    return(len);
}

void show_list(list_t* p_list,const char* msg)
{
    node_t* run = NULL;

    if(msg)
      puts(msg);

    printf("[START]->");

    for(run = p_list->next;run != p_list;run = run->next)
    {
        printf("[%d]<->",run->data);
    }

    printf("[END]");

}

status_t destory_list(list_t** pp_list)
{
    node_t* p_list;
    node_t* run;
    node_t* run_next;

    p_list = *pp_list;

    for(run = p_list->next;run != p_list;run = run_next)
    {
        run_next = run->next;
        free(run);
    }

    free(p_list);
    *pp_list = NULL;
    return(SUCCESS);
}



status_t is_list_empty(list_t* p_list)
{
    return(p_list->next == p_list && p_list->prev == p_list);
}

node_t* search_node(node_t* p_list,data_t s_data)
{
    node_t* run;

    for(run = p_list->next;run != p_list;run = run->next)
    {
        if(run->data == s_data)
        {
            return(run);
        }
    }

    return(NULL);
}

static void generic_insert(struct node* p_beg,struct node* p_mid,struct node* p_end)
{
    p_mid->next = p_end;
    p_mid->prev = p_beg;
    p_beg->next = p_mid;
    p_end->prev = p_mid;
}

static void generic_delete(list_t* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next;
    p_delete_node->next->prev = p_delete_node->prev;
    free(p_delete_node); 
}

node_t* get_node(data_t new_data)
{
    list_t* p_new_node = NULL;

    p_new_node = (struct list_t*)xcalloc(1,sizeof(struct list_t*));
}

static void* xcalloc(int nr_of_element,int size_per_element)
{
    void* p = NULL;

    p = calloc(nr_of_element,size_per_element);
    if(p == NULL)
    {
        puts("error in allocating memory");
        exit(EXIT_FAILURE);
    }
    return(p);
}