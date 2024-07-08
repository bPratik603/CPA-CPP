synthesized constructor : T objT; 
destructor : empty 
copy constructor : T objT(objT_ext);    // memberwise copying 
copy assignment operator objT1 = objT2;     // memberwise assignment 

#-------------------------------------

move constructor            T objT(std::move(objT_ext))
move assignment operator    objT1 = std::move(objT2); 

#--------------------------------------------

class T
{
    public: 
        virtual void f() = 0; 
}; 

// default specifier 
// delete specifier 

class T{
    public: 
        T(const T& obj){} // COPY CC // CLIENT ENABLE: T objT(objT_ext)

        T operator=(const T& obj){} // COPY ASSIGNMENT : objT1 = objT2; 

        ~T(){} // DESTRUCTOR    // delete ptrT; 

        T(T&& obj){} // MOVE CC     // T objT(std::move(objT_ext))

        T operator=(T&& obj){} // MOVE ASSIGNMENT   objT1 = std::move(objT2); 
}
// T() {}  -> SYNTHESIZED 

class T{
    public: 
        T(const T& obj) = default // COPY CC // CLIENT ENABLE: T objT(objT_ext)

        T operator=(const T& obj) = default // COPY ASSIGNMENT : objT1 = objT2; 

        ~T() = default // DESTRUCTOR    // delete ptrT; 

        T(T&& obj) = default // MOVE CC     // T objT(std::move(objT_ext))

        T operator=(T&& obj) = default // MOVE ASSIGNMENT   objT1 = std::move(objT2); 

        T() = default; 
}

// T.h 
class T{

};  

int main(void)
{
    T t1; // synthesized default 
    T t2(t1); // synthesized CC 
    T t3(std::move(t1)); // synthesized move CC

    t3 = t1; // synthesized copy assignment OP 
    t3 = std::move(t2); // synthesized MOVE assignment 

    T* pT = new T; 
    delete pT; // synthesized destructor 

}

class T{
    public: 
        T() = default; 
        ~T() = default; 
        T(const T&) = default 
        T operator=(const T&) = default; 
        T(T&&) = default; 
        T operator=(T&&) = default; 
};  

class node{
    friend class list; 
    private: 
        int data; 
        node* prev; 
        node* next; 
        node(int _data ) : data(_data), prev(0), next(0){}
}; 

class list{
    private: 
        node* head_node; 
    public: 
        list() : head_node(new node){
            head_node->prev = head_node; 
            head_node->next = head_node; 
        }

        ~list(){
            // destroy list
        }

        list(const list&) = delete; 
        list operator=(const list&) = delete; 

        list(list&& rhs_list){
            head_list = rhs_list.head_list; 
            rhs_list.head_node = nullptr; 
        }

        list operator=(list&& rhs_list){
            destroy_list(this->head_node); 
            this->head_node = rhs_list.head_node; 
            rhs_list.head_node = nullptr; 
            return *this;
        }

}

int main(void)
{
    list L1; // populate 
    list L2; // populate 

    list L3(std::move(L1));     // L1 will be trasnferred to L3, L1 will be empty

    list L4; // populate 

    L4 = std::move(L2);     // L4 will be destroyed

    
    list L5(L1); // no 

    L4 = L3; // no 
}