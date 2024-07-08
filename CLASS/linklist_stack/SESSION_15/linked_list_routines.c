#include <stdio.h> 
#include <stdlib.h> 

struct node
{
    int data; 
    struct node* prev; 
    struct node* next; 
}; 

void generic_insert(struct node* p_beg, struct node* p_mid, struct node* p_end); 
void generic_delete(struct node* p_delete_node); 
struct node* search_node(struct node* p_head_node, int search_data); 
struct node* get_node(int new_data); 
void* xcalloc(size_t, size_t); 


void generic_insert(struct node* p_beg, struct node* p_mid, struct node* p_end)
{
    p_mid->next = p_end; 
    p_mid->prev = p_beg; 
    p_beg->next = p_mid; 
    p_end->prev = p_mid; 
}

void generic_delete(struct node* p_delete_node)
{
    p_delete_node->prev->next = p_delete_node->next; 
    p_delete_node->next->prev = p_delete_node->prev; 
    free(p_delete_node); 
}

struct node* search_node(struct node* p_head_node, int search_data)
{
    struct node* run = NULL; 

    run = p_head_node->next; 
    while(run != p_head_node)
    {
        if(run->data == search_data)
            return (run); 
        run = run->next; 
    }

    return (NULL); 
}

struct node* get_node(int new_data) 
{
    struct node* p_new_node = NULL; 

    p_new_node = (struct node*)xcalloc(1, sizeof(struct node)); 
    p_new_node->data = new_data; 

    return (p_new_node); 
}

void* xcalloc(size_t nr_of_elements, size_t size_per_element)
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