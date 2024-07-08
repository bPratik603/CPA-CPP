#include <iostream> 
#include <cstdlib> 
#include <cassert> 

class node 
{
    friend class list; 
    friend std::ostream& operator<<(std::ostream& os, const list& list_object); 
    private: 
        int data; 
        node* prev; 
        node* next; 
        node(int new_data = 0) :    data (new_data), 
                                    prev(0), 
                                    next(0)
        {
        }
}; 

class list 
{
    private: 
        node* head_node; 
        
        static void generic_insert(node* beg, node* mid, node* end)
        {
            mid->next = end; 
            mid->prev = beg; 
            beg->next = mid; 
            end->prev = mid; 
        }

        static void generic_delete(node* d_node)
        {
            d_node->prev->next = d_node->next; 
            d_node->next->prev = d_node->prev; 
            delete d_node; 
        }

        static node* clone(node* other_head_node)
        {
            node* new_head_node = new node(0); 
            new_head_node->prev = new_head_node; 
            new_head_node->next = new_head_node; 

            for(
                node* nd = other_head_node->next; 
                nd != other_head_node; 
                nd = nd->next
            )
                generic_insert(new_head_node->prev, new node(nd->data), new_head_node); 

            return new_head_node; 
        }

    public: 
        list()
        {
            head_node = new node(0); 
            head_node->prev = head_node; 
            head_node->next = head_node; 
        }

        list(const list& other)
        {
            this->head_node = clone(other.head_node); 
        }

        list& operator=(const list& other)
        {
            if(this->head_node == other.head_node)
                return *this; 
            this->clear(); 
            delete this->head_node; 
            this->head_node = clone(other.head_node); 
            return *this; 
        }

        ~list()
        {
            this->clear(); 
            delete head_node; 
            head_node = 0; 
        }

        void insert_end(int new_data)
        {
            generic_insert(head_node->prev, new node(new_data), head_node); 
        }

        void pop_start(int* p_data)
        {
            if(head_node->prev != head_node && head_node->next != head_node)
            {
                *p_data = head_node->next->data; 
                generic_delete(head_node->next); 
            }
        }

        void clear()
        {
            node* nd_next = 0; 
            for(node* nd = head_node->next; nd != head_node; nd = nd_next)
            {
                nd_next = nd->next; 
                delete nd; 
            }

            head_node->prev = head_node; 
            head_node->next = head_node; 
        }

        friend std::ostream& operator<<(std::ostream& os, const list& list_object); 
};

std::ostream& operator<<(std::ostream& os, const list& list_object)
 {
    os << "[START]<->"; 
    for(
        node* nd = list_object.head_node->next; 
        nd != list_object.head_node; 
        nd = nd->next
    )
        os << "[" << nd->data << "]<->"; 
    os << "[END]" << std::endl; 
    return os; 

}

int main(void)
{
    list L1;    //  list::list() 
    int data; 

    for(data = 10; data <= 100; data += 10)
        L1.insert_end(data);    // void list::insert_end(int); 
    
    // std::ostream& operator<<(std::ostream& os, const list& list_object); 
    std::cout << "L1:" << L1 << std::endl; 

    list L2; 
    for(data = 10; data <= 100; data += 10)
        L2.insert_end(data*10);    // void list::insert_end(int); 
   
    std::cout << "L2:" << L2 << std::endl; 
    
    //  list& list::operator=(const list& other); 
    L2 = L1; 

    std::cout << "L2:" << L2 << std::endl; 

    L2.insert_end(500); 

    std::cout << "L2:" << L2 << std::endl; 
    std::cout << "L1:" << L1 << std::endl; 

    L1.pop_start(&data); 
    std::cout << "L1:" << L1 << std::endl; 
    std::cout << "L2:" << L2 << std::endl;  

    // list::list(const list& other); 
    list L3(L2); 

    std::cout << "L2:" << L2 << std::endl; 
    std::cout << "L3:" << L3 << std::endl; 

    L3.insert_end(1000); 

    std::cout << "L2:" << L2 << std::endl; 
    std::cout << "L3:" << L3 << std::endl; 

    std::cout << "END OF APP" << std::endl; 

    return 0; 
}

//  1) CLUE LESS : C linked list -> C++ linked list -> HasPtr deep copy -> LL deep copy
//  2) Only LL deep copy problem : LL deep copy revise + repeat 
//  3) conceptual level OK but hands on problemetic 
//  repeat all (c linked list to LL deep copy)
//  4) understood all but no confidence of invidual development 
//  client to server 
//  L1 = L2     list& list::operator=(const list& other);  
