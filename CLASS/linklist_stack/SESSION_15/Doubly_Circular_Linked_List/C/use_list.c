#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include "list.h"

int main(void)
{
    list_t* lst = NULL; 
    data_t data; 
    status_t status; 

    lst = create_list(); 
    assert(lst != NULL); 
    assert(is_list_empty(lst) == TRUE); 
    assert(get_start(lst, &data) == LIST_EMPTY); 
    assert(get_end(lst, &data) == LIST_EMPTY);
    assert(pop_start(lst, &data) == LIST_EMPTY);
    assert(pop_end(lst, &data) == LIST_EMPTY);
    assert(remove_start(lst) == LIST_EMPTY); 
    assert(remove_end(lst) == LIST_EMPTY); 
    show_list(lst, "List after creation:");
    printf("len(lst) = %d\n", get_list_length(lst));  

    for(data = 0; data < 5; ++data)
    {
        status = insert_end(lst, data * 10); 
        assert(status == SUCCESS); 
    }
    show_list(lst, "After insert_end():"); 

    for(data = 0; data < 5; ++data)
    {
        status = insert_start(lst, (data+1) * 1000); 
        assert(status == SUCCESS); 
    }
    show_list(lst, "After insert_start():"); 

    assert(is_list_empty(lst) == FALSE);    

    printf("len(lst) = %d\n", get_list_length(lst)); 
    
    status = search_list(lst, 0); 
    if(status == TRUE)
        puts("lst contains zero"); 
    status = search_list(lst, -1567); 
    if(status == FALSE)
        puts("lst does not contain -1567"); 

    status = insert_after(lst, 0, -100); 
    assert(status == SUCCESS); 

    status = insert_before(lst, 0, -200); 
    assert(status == SUCCESS);
    show_list(lst, "After insert_after():, insert_before():"); 

    assert(insert_after(lst, -57, 100) == LIST_DATA_NOT_FOUND); 
    assert(insert_before(lst, -12, 900) == LIST_DATA_NOT_FOUND); 

    status = get_start(lst, &data); 
    assert(status == SUCCESS); 
    printf("Start data = %d\n", data); 

    status = get_end(lst, &data); 
    assert(status == SUCCESS); 
    printf("End data = %d\n", data); 

    status = pop_start(lst, &data); 
    printf("Start data after pop_start():%d\n", data); 
    show_list(lst, "List after pop_start():");

    status = pop_end(lst, &data); 
    assert(status == SUCCESS); 
    printf("End data after pop_end():%d\n", data); 
    show_list(lst, "List after pop_end():"); 

    status = remove_start(lst); 
    show_list(lst, "after remove_start():"); 

    status = remove_end(lst); 
    show_list(lst, "After remove_end():"); 

    status = remove_data(lst, 0);
    assert(status == SUCCESS); 
    show_list(lst, "After removing 0:"); 

    assert(remove_data(lst, 16743) == LIST_DATA_NOT_FOUND); 

    status = destroy_list(&lst); 
    assert(status == SUCCESS && lst == NULL); 

    puts("List destroyed successfully"); 

    exit(EXIT_SUCCESS); 
}