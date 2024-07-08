#include <iostream>
#include <cassert>
#include "self.hpp"

int main()
{
    list* p_list = 0;
    data_t data;

    p_list = new list;
    assert(p_list !=0);
    assert(p_list->empty() == true);
    assert(p_list->get_start(&data) == LIST_EMPTY);
    assert(p_list->get_end(&data) == LIST_EMPTY);
    assert(p_list->pop_start(&data) == LIST_EMPTY);
    assert(p_list->pop_end(&data) == LIST_EMPTY);
    assert(p_list->remove_start() == LIST_EMPTY);
    assert(p_list->remove_end() == LIST_EMPTY);
    std::cout<<"p_list->size():"<<p_list->size()<<std::endl;

    for(data = 0;data<5;++data)
    {
        assert(p_list->insert_start(data * 100) == SUCCESS);
    }
    p_list->show("After insert_start():");

    for(data = 0;data<5;++data)
      assert(p_list->insert_start(data * 1000) == SUCCESS);
    p_list->show("After insert_end()");

    assert(p_list->insert_after(0,-100) == SUCCESS);
    assert(p_list->insert_before(0,-200) == SUCCESS);

    assert(p_list->get_start(&data) == SUCCESS);
    std::cout<<"START DATA : "<<data<<std::endl;

    assert(p_list->get_end(&data) == SUCCESS);
    std::cout<<"END DATA :"<<data<<std::endl;

    assert(p_list->pop_start(&data) == SUCCESS);
     std::cout<<"POPED START DATA : "<<data<<std::endl;

    assert(p_list->pop_end(&data) == SUCCESS);
     std::cout<<"POPED END DATA : "<<data<<std::endl;

    assert(p_list->remove_start() == SUCCESS);
    assert(p_list->remove_end() == SUCCESS);
    assert(p_list->remove_data(0) == SUCCESS);

    if(p_list->find(0) == SUCCESS)
      std::cout<<" 0 is present"<<std::endl;

    delete p_list;
    p_list = 0;

    
}