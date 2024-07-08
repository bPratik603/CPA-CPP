#include <iostream> 
#include <cassert> 
#include "list.hpp"

int main(void)
{
    list* p_list = 0; 
    data_t data; 

    p_list = new list; 
    assert(p_list != 0); 
    assert(p_list->empty() == true);  
    assert(p_list->get_start(&data) == LIST_EMPTY); 
    assert(p_list->get_end(&data) == LIST_EMPTY);
    assert(p_list->pop_start(&data) == LIST_EMPTY);
    assert(p_list->pop_end(&data) == LIST_EMPTY);
    assert(p_list->remove_start() == LIST_EMPTY);
    assert(p_list->remove_end() == LIST_EMPTY);
    std::cout << "p_list->size():" << p_list->size() << std::endl; 

    for(data = 0; data < 5; ++data)
        assert(p_list->insert_end(data * 100) == SUCCESS); 
    p_list->show("After insert_end():"); 

    for(data = 0; data < 5; ++data)
        assert(p_list->insert_start((data+1)*1000)); 
    p_list->show("After insert_start():"); 

    assert(p_list->insert_after(0, -100) == SUCCESS); 
    assert(p_list->insert_before(0, -200) == SUCCESS);

    assert(p_list->get_start(&data) == SUCCESS); 
    std::cout << "START DATA:" << data << std::endl; 

    assert(p_list->get_end(&data) == SUCCESS);
    std::cout << "END DATA:" << data << std::endl; 

    assert(p_list->pop_start(&data) == SUCCESS);
    std::cout << "POPED START DATA:" << data << std::endl; 
    p_list->show("After pop_start():"); 

    assert(p_list->pop_end(&data) == SUCCESS); 
    std::cout << "POPED END DATA:" << data << std::endl; 
    p_list->show("After pop_end():"); 

    assert(p_list->remove_start() == SUCCESS);
    p_list->show("After remove_start():"); 


    assert(p_list->remove_end() == SUCCESS);
    p_list->show("After remove_end():");

    if(p_list->find(0) == true)
        std::cout << "List contains 0" << std::endl; 
    if(p_list->find(-654) == false)
        std::cout << "List does not contain -654" << std::endl; 

    assert(p_list->remove_data(0) == SUCCESS); 
    p_list->show("After removing 0:"); 

    assert(p_list->remove_data(10998) == LIST_DATA_NOT_FOUND);

    if(!p_list->empty()) 
        std::cout << "The list is not empty now" << std::endl; 
    std::cout << "Length of the list:" << p_list->size() << std::endl; 

    delete p_list; 
    p_list = 0; 

    std::cout << "List is destroyed successfully" << std::endl; 
    
    return EXIT_SUCCESS; 
}