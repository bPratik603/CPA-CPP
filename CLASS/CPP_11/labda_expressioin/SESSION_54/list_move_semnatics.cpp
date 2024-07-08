#include <iostream>

class node{
    friend class list; 
    friend std::ostream& operator<<(std::ostream& os, const list& lst); 
    private: 
        int data; 
        node* prev; 
        node* next; 
        node(int _data = 0) : data(_data), prev(0), next(0){
        }
}; 

class list{
    private: 
        node* head_node;

        static void destroy_list(node** pp_head_node){
            node* head_node = *pp_head_node; 
            node* run, *run_next; 

            run = head_node->next; 
            while(run != head_node){
                run_next = run->next; 
                delete run; 
                run = run_next; 
            }

            delete head_node; 
            *pp_head_node = 0; 
        } 

        static void generic_insert(node* beg, node* mid, node* end){
            mid->next = end; 
            mid->prev = beg; 
            beg->next = mid; 
            end->prev =  mid; 
        }

    public: 
        list() : head_node(new node){
            head_node->prev = head_node; 
            head_node->next = head_node; 
        }

        ~list(){
            destroy_list(&this->head_node); 
        }

        list(const list&) = delete; 
        list& operator=(const list&) = delete; 

        list(list&& rrlist){
            this->head_node = rrlist.head_node; 
            rrlist.head_node = new node; 
            rrlist.head_node->prev = rrlist.head_node; 
            rrlist.head_node->next = rrlist.head_node; 
        }

        list& operator=(list&& rrlist){
            if(this->head_node == rrlist.head_node)
                return *this; 

            destroy_list(&this->head_node); 
            this->head_node = rrlist.head_node; 
            rrlist.head_node = new node; 
            rrlist.head_node->prev = rrlist.head_node; 
            rrlist.head_node->next = rrlist.head_node;

            return *this; 
        }

        void insert_end(int new_data){
            generic_insert(this->head_node->prev, new node(new_data), this->head_node); 
        }

        friend std::ostream& operator<<(std::ostream& os, const list& lst); 

}; 

std::ostream& operator<<(std::ostream& os, const list& lst){
    os << "[START]<->"; 
    for(node* run = lst.head_node->next;  run != lst.head_node; run = run->next)
        os << "[" << run->data << "]<->"; 
    os << "[END]" << std::endl; 
    return os; 
}

int main(void){
    list L1; 

    for(int data = 1; data <= 10; ++data)
        L1.insert_end(data * 10); 

    std::cout << "L1:BEFORE:list L2(std::move(L1));" << std::endl << L1; 
    list L2(std::move(L1)); 
    std::cout << "L1&L2:After list L2(std::move(L1));" << std::endl; 
    std::cout << "L1:" << std::endl << L1; 
    std::cout << "L2:" << std::endl << L2; 

    list L3; 
    for(int data = 10; data <= 20; ++data)
        L3.insert_end(data * 5); 

    std::cout << "L3:BEFORE:L3 = std::move(L2);" << std::endl; 
    std::cout << "L3:" << std::endl << L3; 
    L3 = std::move(L2); 
    std::cout << "L2&L3:After L3 = std::move(L2);" << std::endl; 
    std::cout << "L2:" << std::endl << L2; 
    std::cout << "L3:" << std::endl << L3; 

    return 0; 
}

/*
template <typename T> 
T&& move(T x){
    return reinterpret_cast<T&&)(ref); 
}

template <typename T>
T&& move(T& ref){
    return reinterpret_cast<T&&>(ref); 
}

template <typename T> 
T&& move(T&& ref){
    return ref; 
}
*/