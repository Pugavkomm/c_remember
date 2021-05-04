#include <iostream>

class Node {
    public:
        int data;
        Node * next;
};

void print_list(Node *n){
    while (n != NULL){
        std::cout << n->data << " ";
        n = n->next;     
    }
    std::cout << '\n';
}

void push(struct Node ** head_ref, int new_data){
    struct Node * new_node = (struct Node *)malloc(sizeof(struct Node ));
    new_node->data = new_data;
    new_node->next = ( * head_ref );
    (* head_ref) = new_node;
}

void push_back(struct Node **head_ref, int new_data){
    struct Node * new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = * head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    while (last->next != NULL){
        last = last->next; 
    }
    last->next = new_node;
}

void insert_after(struct Node * prev_node, int new_data){
    if (prev_node = NULL){
        std::cout << "this not excist element\n";
        return; 
    }
    
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    prev_node->next;
    new_node->next = prev_node->next;
    //new_node->next = prev_node->next; 
    //prev_node->next = new_node;
    
}
int main(){
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = new Node();
    second = new Node();
    third = new Node();

    head = new Node();
    second = new Node();
    third = new Node();

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;
    print_list(head); 
    insert_after(third, 99);
    std::cout << '\n';
    print_list(head); 
    return 0;
}
