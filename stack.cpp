#include <iostream>
#include <stdexcept> 

template <typename T> 
class Stack {
    private:
        struct Node {
            T data; // data
            Node *next; // next node 
        };
        Node *root;  // top stack 
        size_t len = 0; 

        void del(Node* node){
            if (node == nullptr){
                //delete node; 
                return;
            }
            std::cout << "delete: " << node->data << '\n';
            del(node->next);
            delete node; 
        }


    public:
        Stack() : root (nullptr) {} // free stack
        void push(const T& x){
            Node *new_node = new Node; 
            new_node->data = x;
            new_node->next = root;
            root = new_node; 
            len ++; 
        }

        ~Stack(){
            del(root);

        }

        size_t length() const {
            return len; 
        }

        bool is_empty() const {
            return root == nullptr; // if empty: true 
        }

        const T& top() const {
            if (is_empty())
                throw std::length_error("Stack is empty"); 
            return root->data;
        }
        
        T pop() {
            if (is_empty())
                throw std::length_error("Stack is empty"); 

            Node *delnode = root; 
            T x = delnode->data; 
            root = delnode->next; 
            delete delnode; 
            len --;
            return x; 
        }

        void print() const {
            if (is_empty())
                std::cout << "stack is empty\n";
            Node *current = root; 
            while (current != nullptr){
                std::cout << current->data << ' '; 
                current = current->next; 
            }
            std::cout << '\n';
        }

        void destroy() {
            if (is_empty())
                return; 
            del(root);
            root = nullptr;
            len = 0;

            }
        
};

int main(){
    int Data[] = {1, 2, 4, 45, 64, 23, 5};
    Stack <int> st; 
    for(size_t i = 0; i < sizeof(Data) / sizeof(int); ++i){
        st.push(Data[i]);
        st.print();
        std::cout << "top: " << st.top() << '\n'; 
        std::cout << "SIZE: " << st.length() << '\n';
        
    }
    
    for(size_t i = 0; i < sizeof(Data) / sizeof(int); ++i){
        st.pop();
        st.print();
        std::cout << "SIZE: " << st.length() << '\n';
        
    } 
    return 0;
}
