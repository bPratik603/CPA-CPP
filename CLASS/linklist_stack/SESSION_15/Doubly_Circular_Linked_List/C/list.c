#include <stdio.h> 
#include <stdlib.h> 
#include "list.h"

list_t* create_list(void)
{
    list_t* p_list = NULL; 

    p_list = get_node(-1); 
    p_list->prev = p_list; 
    p_list->next = p_list; 

    return (p_list); 
}

status_t insert_start(list_t* p_list, data_t new_data)
{
    generic_insert(p_list, get_node(new_data), p_list->next); 
    return (SUCCESS); 
}

status_t insert_end(list_t* p_list, data_t new_data)
{
    generic_insert(p_list->prev, get_node(new_data), p_list); 
    return (SUCCESS); 
}

status_t insert_after(list_t* p_list, data_t e_data, data_t new_data)
{
    node_t* e_node = NULL; 

    e_node = search_node(p_list, e_data); 
    if(e_node == NULL)
        return (LIST_DATA_NOT_FOUND); 
    generic_insert(e_node, get_node(new_data), e_node->next); 
    return (SUCCESS); 
}

status_t insert_before(list_t* p_list, data_t e_data, data_t new_data)
{
    node_t* e_node = NULL; 

    e_node = search_node(p_list, e_data); 
    if(e_node == NULL)
        return (LIST_DATA_NOT_FOUND); 
    generic_insert(e_node->prev, get_node(new_data), e_node); 
    return (SUCCESS); 
}

status_t get_start(list_t* p_list, data_t* p_start_data)
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY); 
    *p_start_data = p_list->next->data; 
    return (SUCCESS); 
}

status_t get_end(list_t* p_list, data_t* p_end_data)
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY); 
    *p_end_data = p_list->prev->data; 
    return (SUCCESS); 
}

status_t pop_start(list_t* p_list, data_t* p_start_data)
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY); 
    *p_start_data = p_list->next->data; 
    generic_delete(p_list->next); 
    return (SUCCESS); 
}

status_t pop_end(list_t* p_list, data_t* p_end_data)
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY); 
    *p_end_data = p_list->prev->data; 
    generic_delete(p_list->prev); 
    return (SUCCESS); 
}

status_t remove_start(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY); 
    generic_delete(p_list->next); 
    return (SUCCESS); 
}

status_t remove_end(list_t* p_list)
{
    if(is_list_empty(p_list) == TRUE)
        return (LIST_EMPTY); 
    generic_delete(p_list->prev); 
    return (SUCCESS); 
}

status_t remove_data(list_t* p_list, data_t r_data)
{
    node_t* r_node = NULL; 

    r_node = search_node(p_list, r_data); 
    if(r_node == NULL)
        return (LIST_DATA_NOT_FOUND); 
    generic_delete(r_node); 

    return (SUCCESS); 
}

status_t search_list(list_t* p_list, data_t search_data)
{
    node_t* s_node = NULL; 

    s_node = search_node(p_list, search_data); 
    return (s_node != NULL); 
}

len_t get_list_length(list_t* p_list)
{
    len_t lst_len = 0; 
    node_t* run = NULL; 

    for(run = p_list->next; run != p_list; run = run->next)
        ++lst_len; 

    return (lst_len); 
}

status_t is_list_empty(list_t* p_list)
{
    return (p_list->prev == p_list && p_list->next == p_list); 
}

void show_list(list_t* p_list, const char* msg)
{
    node_t* run = NULL; 

    if(msg)
        puts(msg); 

    printf("[START]<->"); 
    for(run = p_list->next; run != p_list; run = run->next)
        printf("[%d]<->", run->data); 
    puts("[END]"); 
    
}

status_t destroy_list(list_t** pp_list)
{
    list_t* p_list = NULL; 
    node_t* run = NULL; 
    node_t* run_next = NULL; 

    p_list = *pp_list; 
    for(run = p_list->next; run != p_list; run = run_next)
    {
        run_next = run->next; 
        free(run); 
    }
    free(p_list); 
    *pp_list = NULL; 
    return (SUCCESS);
}

static void generic_insert(node_t* p_beg, node_t* p_mid, node_t* p_end)
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
}

static void generic_delete(node_t* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    free(p_delete_node); 
}

static node_t* search_node(list_t* p_list, data_t s_data)
{
    node_t* run = NULL; 

    for(run = p_list->next; run != p_list; run = run->next)
        if(run->data == s_data) 
            return (run); 
    return (NULL); 
}

static node_t* get_node(data_t new_data)
{
    node_t* new_node = NULL; 

    new_node = (node_t*)xcalloc(1, sizeof(node_t)); 
    new_node->data = new_data; 

    return (new_node); 
}

static void* xcalloc(size_t nr_of_elements, size_t size_per_element)
{
    void* p = NULL; 

    p = calloc(nr_of_elements, size_per_element); 
    if(p == NULL)
    {
        puts("Error in allocating memory"); 
        exit(EXIT_FAILURE); 
    }

    return (p); 
}