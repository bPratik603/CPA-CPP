#include <iostream> 

class node{
    private: 
        int data; 
        node* prev; 
        node* next; 
    public: 
        //  1. like synthesized constructor of 98
        //  2. default declaration can appear inside class body 
        //  or outside class body. 
        //  3.  if defaulted inside class body, it is inlined 
        //  4.  if defaulted outside class body, it is NOT inlined by default 
        node() = default; 
        node(int data) : data(data), prev(nullptr), next(nullptr) {} 
};  

class bst_node{
    private: 
        int data; 
        bst_node* left; 
        bst_node* right; 
        bst_node* parent; 
    public: 
        bst_node(); 
        bst_node(int); 
}; 

// not inlined by default. 
bst_node::bst_node() = default; 
bst_node::bst_node(int data) : data(data), left(nullptr), right(nullptr), parent(nullptr){

}

int main(){
    node N1(500); 
    bst_node N2(1000); 
    return 0; 
}