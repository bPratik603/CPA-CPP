#include "list.hpp"
#include "Date.hpp"
#include <iostream>

int main(void){
    cpa::dsa::list<int> lst;
    for(int data = 0;data<5;++data){
        lst.insert_end(data);
       
    }

    std::cout<<"AFter insert_start():"<<std::endl
             << lst;

    cpa::dsa::list<char> clist;
    const char* name= "CoreCode Programming Academy";
    for(std::size_t i=0;i < strlen(name);++i)
    {
        clist.insert_end(name[i]);
    }

    std::cout << clist;   

    cpa::dsa::list<Date> date_list;
    date_list.insert_end(Date(1,12,1977));
    date_list.insert_end(Date(2,11,1999));
    date_list.insert_end(Date(5,8,1965));
    date_list.insert_end(Date(5,8,1965));

    std::cout << date_list;          




}